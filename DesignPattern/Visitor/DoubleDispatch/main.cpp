#include <iostream>

// 普通汽车，折扣为0.03
class Vehicle
{
public:
    virtual double GetBaseDiscountRate() { return 0.03; }
};

// 由于是奔驰特销商，因此可以得到更大的折扣
class Benz : public Vehicle
{
public:
    virtual double GetBaseDiscountRate() { return 0.06; }
};

// 普通的销售人员，只能按照公司规定的折扣进行销售
class Sales
{
public:
    virtual double GetDiscountRate(Vehicle& vehicle)
    {
        return vehicle.GetBaseDiscountRate();
    }

    virtual double GetDiscountRate(Benz& benz)
    {
        return benz.GetBaseDiscountRate();
    }
};

// 销售经理，可以针对奔驰提供额外的优惠
class SalesManager : public Sales
{
public:
    virtual double GetDiscountRate(Vehicle& vehicle)
    {
        return vehicle.GetBaseDiscountRate();
    }

    virtual double GetDiscountRate(Benz& benz)
    {
        return benz.GetBaseDiscountRate() * 1.1;
    }
};

int main(int argc, char** argv)
{
    // 有两辆车需要销售，一辆是普通轿车，而另一辆则是奔驰
    Vehicle& vehicle = Vehicle();
	// 
	Vehicle& benz = Benz();
	//Benz& benz = Benz();

    // 向普通销售询问这两辆车的折扣
    Sales* pSales = new Sales();
    double rate = pSales->GetDiscountRate(vehicle);
    std::cout << "Sales: The rate for common vehicle is: " << rate << std::endl;
    rate = pSales->GetDiscountRate(benz);
	std::cout << "Sales: The rate for benz is: " << rate << std::endl;

    // 向销售经理询问这两辆车的折扣
    SalesManager* pSalesManager = new SalesManager();
    rate = pSalesManager->GetDiscountRate(vehicle);
	std::cout << "Sales Manager: The rate for common vehicle is: " << rate << std::endl;
    rate = pSalesManager->GetDiscountRate(benz);
	std::cout << "Sales Manager: The rate for benz is: " << rate << std::endl;

    return 0;
}