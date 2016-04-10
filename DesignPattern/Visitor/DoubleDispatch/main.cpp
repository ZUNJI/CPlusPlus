#include <iostream>

// ��ͨ�������ۿ�Ϊ0.03
class Vehicle
{
public:
    virtual double GetBaseDiscountRate() { return 0.03; }
};

// �����Ǳ��������̣���˿��Եõ�������ۿ�
class Benz : public Vehicle
{
public:
    virtual double GetBaseDiscountRate() { return 0.06; }
};

// ��ͨ��������Ա��ֻ�ܰ��չ�˾�涨���ۿ۽�������
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

// ���۾���������Ա����ṩ������Ż�
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
    // ����������Ҫ���ۣ�һ������ͨ�γ�������һ�����Ǳ���
    Vehicle& vehicle = Vehicle();
	// 
	Vehicle& benz = Benz();
	//Benz& benz = Benz();

    // ����ͨ����ѯ�������������ۿ�
    Sales* pSales = new Sales();
    double rate = pSales->GetDiscountRate(vehicle);
    std::cout << "Sales: The rate for common vehicle is: " << rate << std::endl;
    rate = pSales->GetDiscountRate(benz);
	std::cout << "Sales: The rate for benz is: " << rate << std::endl;

    // �����۾���ѯ�������������ۿ�
    SalesManager* pSalesManager = new SalesManager();
    rate = pSalesManager->GetDiscountRate(vehicle);
	std::cout << "Sales Manager: The rate for common vehicle is: " << rate << std::endl;
    rate = pSalesManager->GetDiscountRate(benz);
	std::cout << "Sales Manager: The rate for benz is: " << rate << std::endl;

    return 0;
}