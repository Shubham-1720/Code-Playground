#include<iostream>
using namespace std;


class Matrix
{
    public:
    void sumMatrix(void);
    void productMatrix(void);
    void transposeMatrix(void);
};
void Matrix::sumMatrix(){
    int row, column;
    cout<<"Enter the number of rows in your matrix"<<endl;
    cin>>row;
    cout<<"Enter the number of columns in your matrix"<<endl;
    cin>>column;
    int matrix1[row][column];
    int data1;
    for(int i = 0; i<row; i++){
        for (int j=0 ;j < column; j++) {
            cout<< "enter element at "<<i+1 <<","<<j+1 <<" : "<<endl;
            cin>>data1;
            matrix1[i][j]= data1;
    }}

    cout<<"Now enter second matrix for addition"<<endl;
    int matrix2[row][column];
    int data2;
    for(int i = 0; i<row; i++){
        for (int j=0; j < column; j++) {
            cout<< "enter element at "<<i+1 <<","<<j+1 <<" : "<<endl;
            cin>>data2;
            matrix2[i][j]= data2;
    }}

    int sum_matrix[row][column];
    for(int i = 0; i<row; i++){
        for (int j=0 ;j < column; j++) {
            sum_matrix[i][j]= matrix1[i][j] + matrix2[i][j];
            

        }}
    cout<<"";
    cout<<"Elements of matrix obtain by adding both matrix are: "<<endl;
    for(int  i = 0; i<row; i++){
        for(int j = 0;j< column;j++){
            cout<<"Element at position ("<<i+1<<", "<<j+1<<") is "<<sum_matrix[i][j]<<endl;
        }
    }
 }

void Matrix::productMatrix(void){
    int row_mat1, column_mat1;
    cout<<"Enter the number of rows in your matrix"<<endl;
    cin>>row_mat1;
    cout<<"Enter the number of columns in your matrix"<<endl;
    cin>>column_mat1;
    int matrix1[row_mat1][column_mat1];
    int data1;
    for(int i = 0; i<row_mat1; i++){
        for (int j=0 ;j < column_mat1; j++) {
            cout<< "enter element at "<<i+1 <<","<<j+1 <<" : "<<endl;
            cin>>data1;
            matrix1[i][j]= data1;
    }}

    cout<<"Now enter second matrix for addition"<<endl;
    cout<<"Notice: For product column_mat1 should be equal to row_mat2"<<endl;
    int row_mat2, column_mat2;
    cout<<"Enter the number of rows in your matrix"<<endl;
    cin>>row_mat2;
    cout<<"Enter the number of columns in your matrix"<<endl;
    cin>>column_mat2;
    int matrix2[row_mat2][column_mat2];
    int data2;
    for(int i = 0; i<row_mat2; i++){
        for (int j=0 ;j < column_mat2; j++) {
            cout<< "enter element at "<<i+1 <<","<<j+1 <<" : "<<endl;
            cin>>data2;
            matrix2[i][j]= data2;
    }}

    int matrix3[row_mat1][column_mat2];
    for (int i = 0; i < row_mat1; i++){
        for(int j=0; j < column_mat2; j++){
            matrix3[i][j] = 0;
            for(int k=0; k<row_mat2; k++){
                matrix3[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }}
    

    cout<<"";
    cout<<"Elements of matrix obtain by product are: "<<endl;
    for(int i=0; i<row_mat1;i++){
        for(int j=0;j<column_mat2;j++){
            cout<<"Element at ("<<i+1<<", "<<j+1<<") is "<<matrix3[i][j]<<endl;
        }
    }

}

void Matrix::transposeMatrix(void){
    int row, column;
    cout<<"Enter the number of rows in your matrix"<<endl;
    cin>>row;
    cout<<"Enter the number of columns in your matrix"<<endl;
    cin>>column;
    int matrix[row][column];
    int data;
    for(int i = 0; i<row; i++){
        for (int j=0 ;j < column; j++) {
            cout<< "enter element at "<<i+1 <<","<<j+1 <<" : "<<endl;
            cin>>data;
            matrix[i][j]= data;
    }}

    int trans_matrix[column][row];
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            trans_matrix[j][i]=matrix[i][j];
        }
    }

    cout<<"";
    cout<<"Elements of matrix obtain by traspose are: "<<endl;
    for(int i=0; i<column; i++){
        for(int j=0; j<row; j++){
            cout<<"Element at position ("<<i+1<<", "<<j+1<<") is "<<trans_matrix[i][j]<<endl;
        }}
}

int main(){
    Matrix set1;
    // set1.sumMatrix();
    // set1.productMatrix();
    set1.transposeMatrix();
    return 0;
}
