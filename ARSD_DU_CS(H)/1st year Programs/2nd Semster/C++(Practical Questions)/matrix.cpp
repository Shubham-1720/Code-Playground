#include<iostream>
using namespace std;
const int size = 3;
class Matrix
{
    public:
    void sumMatrix(int array1[][3], int array2[][3], int row1, int column1, int row2, int column2);
    // void sumMatrix(int,int,int,int,int,int);
    void productMatrix(void);
    void transposeMatrix(void);
};
void Matrix::sumMatrix(int array1[][size], int array2[][size], int row1, int column1, int row2, int column2){
    if(row1==row2 && column1==column2){
        int arraysum[row1][column1];
        for(int i = 0; i<row1 ; i++){
            for(int j = 0; j<column1; j++){
                arraysum[i][j] = array1[i][j] + array2[i][j];
            }
        }
        for(int  i = 0; i<row1; i++){
        for(int j = 0;j< column2;j++){
            cout<<"Element at position ("<<i+1<<", "<<j+1<<") is "<<arraysum[i][j]<<endl;
        }
    }
    }
    else{
        throw(row1==row2 && column1==column2);
    }
}
int main(){
    //to enter matrix number one
    int row_1, column_1;
    cout<<"Enter the number of rows in your matrix"<<endl;
    cin>>row_1;
    cout<<"Enter the number of columns in your matrix"<<endl;
    cin>>column_1;
    int matrix1[row_1][3];
    int data1;
    for(int i = 0; i<row_1; i++){
        for (int j=0 ;j < column_1; j++) {
            cout<< "enter element at "<<i+1 <<","<<j+1 <<" : "<<endl;
            cin>>data1;
            matrix1[i][j]= data1;
    }}
    int row_2, column_2;
    cout<<"Now enter second matrix for addition"<<endl;
    cout<<"Enter the number of rows in your matrix"<<endl;
    cin>>row_2;
    cout<<"Enter the number of columns in your matrix"<<endl;
    cin>>column_2;
    int matrix2[row_2][3];
    int data2;
    for(int i = 0; i<row_2; i++){
        for (int j=0 ;j < column_2; j++) {
            cout<< "enter element at "<<i+1 <<","<<j+1 <<" : "<<endl;
            cin>>data2;
            matrix2[i][j]= data2;
    }}


    try{

        Matrix set1;
        set1.sumMatrix(matrix1, matrix2, row_1, column_1, row_2, column_2);
    }
    catch (bool){
        cout<<"matrix is not compactiable for operation"<<endl;
    }
    return 0;
}