#include<iostream>
#include<cmath>
using namespace std;

class Triangle
{
    public:
    float s1,s2,s3,area,semi_permi;
    

    void area_calc(float s1, float s2)
    {
        area = 0.5*(s1*s2);
        cout<<"Area of triangle with entered base and heigth is: "<<area<<" unit "<<endl;
    }

    void area_calc(float s1, float s2, float s3)
    {
        float semi_permi = (s1+s2+s3)/2;
        area = sqrt(semi_permi*(semi_permi-s1)*(semi_permi-s2)*(semi_permi-s3));
        cout<<"Area of triangle with entered side  is: "<<area<<" unit "<<endl;
    }
};

int main(){
    float s1,s2,s3;
    cout<<"Enter sides for calculation of area"<<endl;
    cout<<"Notice: If triangle is right then enter base and height"<<endl;
    cout<<"        otherwise enter all the three side"<<endl;
    cout<<"Enter side_1"<<endl;
    cin>>s1;
    cout<<"Enter side_2"<<endl;
    cin>>s2;
    cout<<"Enter side_3"<<endl;
    cin>>s3;
    try
    {
        if(((s1>0) and (s2>0) and (s3>0)) and ((s1+s2)>s3 and (s2+s3)>s1 and (s1+s3)>s2)){
            Triangle set1;
            Triangle set2;
            // set2.area_calc(s1,s2);

            set1.area_calc(s1,s2,s3);
        }
        else{
            throw ((s1>0) and (s2>0) and (s3>0)) and ((s1+s2)>s3 and (s2+s3)>s1 and (s1+s3)>s2);
        
    
        }
    }
    catch (bool){
        cout<<"Data entered by you is invalid";
    }
    
    return 0;
}