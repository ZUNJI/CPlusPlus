/* -*-c++-*- Present3D - Copyright (C) 1999-2006 Robert Osfield
 *
 * This software is open source and may be redistributed and/or modified under
 * the terms of the GNU General Public License (GPL) version 2.0.
 * The full license is in LICENSE.txt file included with this distribution,.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * include LICENSE.txt for more details.
*/

#include <osgPresentation/PropertyManager>
#include <osg/io_utils>

using namespace SLCore;

const osg::Object* osgPresentation::getUserObject(const osg::NodePath& nodepath, const std::string& name)
{
    for(osg::NodePath::const_reverse_iterator itr = nodepath.rbegin();
        itr != nodepath.rend();
        ++itr)
    {
        const osg::UserDataContainer* udc = (*itr)->getUserDataContainer();
        const osg::Object* object = udc ? udc->getUserObject(name) : 0;
        if (object) return object;
    }
    return 0;
}

bool osgPresentation::containsPropertyReference(const std::string& str)
{
    return (str.find('$')!=std::string::npos);
}

class MySetValueVisitor : public osg::ValueObject::SetValueVisitor
{
public:

    MySetValueVisitor(double in_r1, double in_r2, osg::ValueObject* in_object2):
        _r1(in_r1), _r2(in_r2), _object2(in_object2)
    {
    }

    template<typename T>
    void combineRealUserValue(T& value) const
    {
        typedef osg::TemplateValueObject<T> UserValueObject;
        const UserValueObject* uvo = _object2 ? dynamic_cast<const UserValueObject*>(_object2) : 0;
        if (uvo)
        {
            value = value*_r1 + uvo->getValue()*_r2;
        }
        OSG_NOTICE<<"combineRealUserValue r1="<<_r1<<", r2="<<_r2<<", value="<<value<<std::endl;
    }

    template<typename T>
    void combineIntegerUserValue(T& value) const
    {
        typedef osg::TemplateValueObject<T> UserValueObject;
        const UserValueObject* uvo = _object2 ? dynamic_cast<const UserValueObject*>(_object2) : 0;
        if (uvo)
        {
            value = static_cast<T>(static_cast<double>(value)*_r1 + static_cast<double>(uvo->getValue())*_r2);
        }
        OSG_NOTICE<<"combineIntegerUserValue "<<value<<std::endl;
    }

    template<typename T>
    void combineDiscretUserValue(T& value) const
    {
        if (_r1<_r2) // choose value2 if possible
        {
            typedef osg::TemplateValueObject<T> UserValueObject;
            const UserValueObject* uvo = _object2 ? dynamic_cast<const UserValueObject*>(_object2) : 0;
            if (uvo)
            {
                value = uvo->getValue();
            }
        }
        OSG_NOTICE<<"combineDiscretUserValue "<<value<<std::endl;
    }

    template<typename T>
    void combineRotationUserValue(T& /*value*/) const
    {
        OSG_NOTICE<<"combineRotationUserValue TODO - do slerp"<<std::endl;
    }

    template<typename T>
    void combinePlaneUserValue(T& /*value*/) const
    {
        OSG_NOTICE<<"combinePlaneUserValue TODO"<<std::endl;
    }

    template<typename T>
    void combineMatrixUserValue(T& /*value*/) const
    {
        OSG_NOTICE<<"combineMatrixUserValue TODO - decomposs into translate, rotation and scale and then interpolate."<<std::endl;
    }


    virtual void apply(bool& value)             { combineDiscretUserValue(value); }
    virtual void apply(char& value)             { combineDiscretUserValue(value); }
    virtual void apply(unsigned char& value)    { combineDiscretUserValue(value); }
    virtual void apply(short& value)            { combineIntegerUserValue(value); }
    virtual void apply(unsigned short& value)   { combineIntegerUserValue(value); }
    virtual void apply(int& value)              { combineIntegerUserValue(value); }
    virtual void apply(unsigned int& value)     { combineIntegerUserValue(value); }
    virtual void apply(float& value)            { combineRealUserValue(value); }
    virtual void apply(double& value)           { combineRealUserValue(value); }
    virtual void apply(std::string& value)      { combineDiscretUserValue(value); }
    virtual void apply(osg::Vec2f& value)       { combineRealUserValue(value); }
    virtual void apply(osg::Vec3f& value)       { combineRealUserValue(value); }
    virtual void apply(osg::Vec4f& value)       { combineRealUserValue(value); }
    virtual void apply(osg::Vec2d& value)       { combineRealUserValue(value); }
    virtual void apply(osg::Vec3d& value)       { combineRealUserValue(value); }
    virtual void apply(osg::Vec4d& value)       { combineRealUserValue(value); }
    virtual void apply(osg::Quat& value)        { combineRotationUserValue(value); }
    virtual void apply(osg::Plane& value)       { combinePlaneUserValue(value); }
    virtual void apply(osg::Matrixf& value)     { combineMatrixUserValue(value); }
    virtual void apply(osg::Matrixd& value)     { combineMatrixUserValue(value); }

    virtual ~MySetValueVisitor() {}

    double _r1, _r2;
    osg::ValueObject* _object2;
};