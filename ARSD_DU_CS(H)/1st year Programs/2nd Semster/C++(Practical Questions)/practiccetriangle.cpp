#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
public:
    float s1, s2, s3, area, semi_permi;

    void area_calc(float s1, float s2)
    {
        if (s1 >= 0 && s2 >= 0)
        {
            area = 0.5 * (s1 * s2);
            cout << "Area of triangle with entered base and heigth is: " << area << " unit " << endl;
        }
        else
        {
            throw(s1>=0 && s2>=0);
            
        }
    }

    void area_calc(float s1, float s2, float s3)
    {
        if (s1 >= 0 && s2 >= 0 && s3 >= 0 && ((s1 + s2) > s3 && (s2 + s3) > s1 && (s1 + s3) > s2))
        {
            float semi_permi = (s1 + s2 + s3) / 2;
            area = sqrt(semi_permi * (semi_permi - s1) * (semi_permi - s2) * (semi_permi - s3));
            cout << "Area of triangle with entered side  is: " << area << " unit " << endl;
        }
        else
        {
            throw(s1 >= 0 && s2 >= 0 && s3 >= 0 && ((s1 + s2) > s3) && ((s2 + s3) > s1) && ((s1 + s3) > s2));
            
        }
        
    }
};
int main()
{
    Triangle set1, set2;
    char a;
    float s_1, s_2, s_3;
    cout << "you want to calcualte area of which " << endl;
    cin >> a;

    try
    {
        if (a == 'r' || a == 'R')
        {
            cout << "enter two sides" << endl;
            cin>>s_1;
            cin>>s_2;
            set1.area_calc(s_1, s_2);
        }
        else if (a == 'n' || a == 'N')
        {
            cin>>s_1;
            cin>>s_2;
            cin>>s_3;
            set1.area_calc(s_1, s_2, s_3);
        }
        else{
            cout<<"invalid selection"<<endl;
        }
    }
    catch (bool)
    {
        cout << "invalid inputs" << endl;
    }
    return 0;
}