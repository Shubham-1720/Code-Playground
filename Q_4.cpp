#include<iostream>
using namespace std;

class Matrix
{
    public:
       int rows, column;
    
     void setData(int r,int c){
        rows = r;
        column = c;
     }

     void display_Matrix(){
        int matrix[3];
        


     }
};

int main(){
    // int row, column;
    // cout<<"Enter the number of rows in your matrix"<<endl;
    // cin>>row;
    // cout<<"Enter the number of rows in your matrix"<<endl;
    // cin>>column;
    // int array[row][column];
    // int data;
    // for(int i = 0; i<row; i++){
    //     for (int j=0 ;j < column; j++) {
    //         cout<< "enter element "<<i+1 <<","<<j+1 <<" : "<<endl;
    //         cin>>data;
    //         array[i][j]= data;
    // }}
    
    // to find sum of the function
    // int a1 [2][2] = {{1,1},{1,1}};
    // int a2 [2][2] = {{1,1},{1,1}};
    // int sum_array[2][2];
    // for(int i = 0; i<2; i++){
    //     for (int j=0 ;j < 2; j++) {
    //         sum_array[i][j]= a1[i][j]+a2[i][j];

    //     }}

    // for(int i = 0; i<2; i++){
    //     for (int j=0 ;j < 2; j++){
    //         cout<<sum_array[i][j]<<endl;
    //     }}

    //transpose
    int a1 [2][2] = {{1,2},{3,1}};
    int a2 [2];
    int row1[2] , row2[2];
    for (int i = 0; i < 2; i++){
        for(int j=0; j < 2; j++){
            if(j == 0){
                row1[i] = a1[i][j];
            }
            else if(j == 1){
                row2[i] = a1[i][j];
            }
        }
    }
    
    cout<<"[";
    for(int i = 0; i<2; i++){
    cout<<row1[i]<<", ";
   }
    cout<<endl;
    
    for(int i = 0; i<2; i++){
    
    cout<<row2[i]<<", ";
   }
    cout<<"]";
    cout<<endl;
    
    return 0;
}