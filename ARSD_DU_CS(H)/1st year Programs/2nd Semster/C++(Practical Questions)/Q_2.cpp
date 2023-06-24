#include <iostream>
using namespace std;

int main()
{   int size = 10;
    int array[10] = {2,2,2,3,3,4,5,4,6,4};
    for (int i=0; i<size-1; i++){
      for(int j=i+1; j<size;){
        if (array[i]==array[j]){
          for(int k=j; k<size-1;k++){
            array[k]=array[k+1];
             }
             size = size-1;
        }
        else{
            j++;
        }
      }
    }
    cout<<"Array after removing duplicates: ";
    for(int i=0; i<size;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}