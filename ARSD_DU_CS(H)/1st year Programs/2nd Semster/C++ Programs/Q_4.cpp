#include<iostream>
using namespace std;

int main(){
    int n[10]= {1,2,3,4,5,6,7,8,9,10};
    int i = 2;
    int j = 3;
    int *num; // declaring a pointer of interger type

    //*(num+2) will evalute as
    cout<<"*(num+2) will access the third element of the array "<<n[2]<<endl;

    //*(num+j) will evalute as 
    cout<<"*(num+j) will access the fourth element of the array "<<n[j]<<endl;

    //*(num+i+j) will evalute as 
    cout<<"*(num+i+j) will access the sixth element of the array "<<n[i+j]<<endl;

    //*(num+i)+ *(num+j) will evalute as 
    cout<<"*(num+i)+ *(num+j) will access the third and fourth element of the array "<<n[i] + n[j]<<endl;

    //*(num+*(num+1)) will evalute as
    cout<<"*(num+*(num+1)) firstly is access the second element of array and used it as index to access the element of the array "<<n[n[1]]<<endl;


    return 0;
}