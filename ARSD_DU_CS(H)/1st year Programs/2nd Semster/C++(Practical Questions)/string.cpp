#include<iostream>
using namespace std;
void length(){
    const char *str = "hello how are you";
    int length = 0;
    const char *ptr = str;
    while(*ptr != '\0'){
        length ++;
        ptr ++;
    }
    cout<<length<<endl;

}
void addresss(){
    const char * str = "shubham.";
    const char *ptr = str;
    while(*ptr != '\0'){ //'\0'end of line 
        cout<<"address of "<<*ptr<<" is "<<(void*)ptr<<endl;
        ptr++;
    }
}
int main(){
    // length();
    // cout<<char(int('c'));
    // addresss();
    const char *str = "shubham";
    // char * ptr = str;
    // for (int i = 0; i< 7; i++){
    //     cout<<*str<<" "<<endl;
    //     *str++;
    // }
    int length = 0;
    while(*str != '\0'){
         length++;
         cout<<*str<<(void*)str<<endl;
         *str++;
    }

cout<<length;

    return 0;
}