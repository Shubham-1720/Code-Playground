#include<iostream>
using namespace std;

void arrayshow(int *array){
    for(int i = 0 ; i<3;i++){
        for (int j= 0;j<3; j++){
            
            cout<<array[i][j]<<endl;
        }
    }
}
int main(){
    int data;
    int row, column;
    cout<<"enter"<<endl;
    cin>>row;
    cin>>column;
    int *array[row];
    for (int i = 0 ; i<3 ;i++ ){
        array[i] =  new int[column];
    }
    for(int i = 0 ; i<3;i++){
        for (int j= 0;j<3; j++){
            cout<<"enter"<<endl;
            cin>>data;
            array[i][j] = data;
        }
    }
    arrayshow(array);
    
    return 0;
}