#include <iostream>
using namespace std;

int searcher(int array[], int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == x)
        {
            return i;
        }
        
    }
    return -1;
}

int main()
{
    int x, n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;
    int array[n];
    cout<<"Now enter the elements of array one-by-one"<<endl;
    for(int i=0; i<n; i++){
        cout<<"Enter element at index "<<i<<endl;
          int values;
          cin>>values;
          array[i]= values;
    }
    cout<<"Enter the value you want to search in array: "<<endl;
    cin>>x;
   
    
    int value = searcher(array, x, n);
    if (value != -1)
    {
        cout << "Element " << x << " is found at inedx " << value << endl;
    }
    else
    {
        cout << "Element " << x << " not found" << endl;
    }
    return 0;
}