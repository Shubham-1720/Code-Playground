#include <iostream>
using namespace std;

int main()
{   int size = 5;
    int array[5] = {2,3,2,3,5};
    cout<<"Array before removing duplicates: ";
    for(int i=0; i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    for (int i=0; i<size-1; i++){
      for(int j=i+1; j<size;){
        if (array[i]==array[j]){
          for(int k=j; k<size-1;k++){
            array[k]=array[k+1];
             }
             size = size-1;
             cout<<size<<endl;
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