#include <iostream>
#include <cmath>
using namespace std;

class TwoDimShape
{   protected:
    float area;
    float perimeter;
    static float PI;

public:
    TwoDimShape(float, float);

    virtual void calcArea() = 0;
    virtual void calcPeri() = 0;
};
TwoDimShape::TwoDimShape(float area, float perimeter)
{
    this->area = area;
    this->perimeter = perimeter;
}
float TwoDimShape::PI = 3.14;

class Circle : public TwoDimShape
{
    float radius;

public:
    Circle(float radius_v, float area_v, float perimeter_v) : TwoDimShape(area_v, perimeter_v)
    {
        radius = radius_v;
    }
    void calcArea()
    {
        area = PI*radius*radius;
        cout<<"Radius of the circle is: "<<area<<" square unit "<<endl;
    }
    void calcPeri()
    {
        perimeter = 2*PI*radius;
        cout<<"Perimeter of the circle is: "<<perimeter<<" unit "<<endl;
    }
};
class Triangle : public TwoDimShape
{
    float sideA, sideB, sideC;

public:
    Triangle(float sideA_v, float sideB_v, float sideC_v, float area_v, float perimeter_v) : TwoDimShape(area_v, perimeter_v)
    {
        try
        {

            if (((sideA_v + sideB_v) > sideC_v and (sideB_v + sideC_v) > sideA_v and (sideA_v + sideC_v) > sideB_v))
            {
                sideA = sideA_v;
                sideB = sideB_v;
                sideC = sideC_v;
            }
            else
            {
                throw (((sideA_v + sideB_v) > sideC_v and (sideB_v + sideC_v) > sideA_v and (sideA_v + sideC_v) > sideB_v));
            }
            
        }
        catch (bool) {
                cout<<"Invalid inputs."<<endl;
                cout<<"Re- enter correct values."<<endl;
                cout<<"Will get garbage values of area and perimeter."<<endl;
                cout<<endl;
                cout<<endl;
            }
    }

    void calcArea()
    {
        float semi_permi = (sideA+ sideB+ sideC)/2;
        area = sqrt(semi_permi*(semi_permi-sideA)*(semi_permi-sideB)*(semi_permi-sideC));
        cout<<"Area of triangle is: "<<area<<" square unit "<<endl;
    }
    
    void calcPeri()
    {
        perimeter = sideA + sideB + sideC;
        cout<<"Perimeter of triangle is "<<perimeter<<" unit "<<endl;
    }
};
class Square : public TwoDimShape
{
    float side_1, side_2;

public:
    Square(float side1_v, float side2_v, float area_v, float perimeter_v) : TwoDimShape(area_v, perimeter_v)
    {
        side_1 = side1_v;
        side_2 = side2_v;
    }

    void calcArea()
    {
        area = side_1*side_2;
        cout<<"Area of the square is "<<area<<" square unit "<<endl;
    }

    void calcPeri()
    {
        perimeter = 4*side_1;
        cout<<"Perimeter of the square is "<<perimeter<<" unit "<<endl;

    }
};

int main()
{
    // Circle c1(1.0 , 0.0 , 0.0);
    // c1.calcArea();
    // c1.calcPeri();
    // Triangle t1(2.0, 2.1, 12.5, 0.0, 0.0);
    // t1.calcArea();
    // t1.calcPeri();
    Square s1(2.0, 2.0, 0.0, 0.0);
    s1.calcArea();
    s1.calcPeri();
    

    return 0;
}