#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main(){
    /*
    ofstream sout("sample.txt");
    char str[30] = "Hey world this is shubham";
    sout<<str;
    sout.close();
    */

    ifstream sin("sample.txt");
    ofstream sout("sampleb.txt");
    string str1;
    while(sin.eof()==0){
        sin>>str1;
        sout<<str1;
    }
return 0;
}