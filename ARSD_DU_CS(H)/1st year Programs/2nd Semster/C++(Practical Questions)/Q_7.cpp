#include<iostream>
using namespace std;

int main(){
    int int1, int2, smaller, GCD;
    cout<<"Enter two number to calculate their GCD: "<<endl;
    cin>>int1;
    cin>>int2;
    if(int1>int2){
        smaller = int2;
    }
    else{
        smaller = int1;
    }
    for(int i = 1; i<=smaller; i++){
        if(int1%i==0 and int2%i==0){
            GCD = i;
        }
    }
    cout<<"GCD of entered number is: "<<GCD<<endl;
    return 0;
}