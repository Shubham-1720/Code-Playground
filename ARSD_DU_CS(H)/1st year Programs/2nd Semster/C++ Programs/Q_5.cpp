#include<iostream>
using namespace std;

int min(int num1, int num2)
{
    if(num1>num2)
    {
        return num2;
    }
    else
    {
        return num1;
    }
}
char min(char ch1, char ch2)
{
    if(ch1>ch2)
    {
        return ch2;
    }
    else
    {
        return ch1;
    }
}
float min(float num1, float num2)
{
    if(num1>num2)
    {
        return num2;
    }
    else
    {
        return num1;
    }
}
int main(){
    cout<<"Smallest in 2 and 3 is "<<min(2,3)<<endl;
    cout<<"Smallest in d and g is "<<min('d','g')<<endl;
    cout<<"Smallest in 2.6 and 3.5 is "<<min(2.6,3.5)<<endl;
    return 0;
}