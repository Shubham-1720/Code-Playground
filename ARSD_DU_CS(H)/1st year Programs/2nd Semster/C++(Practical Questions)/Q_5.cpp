#include<iostream>
using namespace std;

int main(){
    int  n1;
    cout<<"Enter the size of first array: "<<endl;
    cin>>n1;
    int array1[n1];
    cout<<"Now enter the elements of first array one-by-one in ascending order"<<endl;
    for(int i=0; i<n1; i++){
        cout<<"Enter element at index "<<i<<endl;
          int values;
          cin>>values;
          array1[i]= values;
    }
     int  n2;
    cout<<"Enter the size of second array: "<<endl;
    cin>>n2;
    int array2[n2];
    cout<<"Now enter the elements of second array one-by-one in ascending order"<<endl;
    for(int i=0; i<n2; i++){
        cout<<"Enter element at index "<<i<<endl;
          int values;
          cin>>values;
          array2[i]= values;
    }
    int mergedarray[n1+n2];
    int n = n1 + n2;
    int i=0, j=0, k=0; 
    while(i<n1 && j<n2){
        if(array1[i]<=array2[j]){
            mergedarray[k]=array1[i];
            i++;
        }
        else{
            mergedarray[k]=array2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        mergedarray[k]=array1[i];
        i++;
        k++;
    }
    while(j<n2){
        mergedarray[k]=array2[j];
        j++;
        k++;
    }
    cout<<"Merged array in ascending order is: "<<endl;
    for(int r=0; r<n ; r++){
        cout<<mergedarray[r]<<" "; 
    }
    return 0;
}