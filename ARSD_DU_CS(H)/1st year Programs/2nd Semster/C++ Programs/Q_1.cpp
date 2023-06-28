#include <iostream>
using namespace std;

const int m = 5;
// defining functions
void setArrData(int array_A[], int array_B[])
{
    int i, data;
    cout << "Enter data for array A " << endl;
    for (i = 0; i < m; i++)
    {
        cin >> data;
        array_A[i] = data;
    }
    cout << "Enter data for array B " << endl;
    for (i = 0; i < m; i++)
    {
        cin >> data;
        array_B[i] = data;
    }
}

void printArrData(int array_A[], int array_B[])
{
    int i;
    for (i = 0; i < m; i++)
    {

        cout << "Element at index " << i << " in array A is " << array_A[i] << endl;
    }
    cout << endl;
    cout << endl;
    for (i = 0; i < m; i++)
    {

        cout << "Element at index " << i << " in array B is " << array_B[i] << endl;
    }
}

int testData(int array_A[], int array_B[])
{
    int i;
    for (i = 0; i < m; i++)
    {
        if (array_A[i] != array_B[i])
        {
            cout << "Both the arrays are not equal" << endl;
            return 0;
        }
    }
    cout << "Both the arrays are equal" << endl;
    return 1;
}

void reverseArray(int array_A[], int array_B[])
{
    int rev_array_A[m];
    int rev_array_B[m];
    int i;
    for (i = 0; i < m; i++)
    {
        rev_array_A[(m - 1) - i] = array_A[i];
    }
    for (i = 0; i < m; i++)
    {
        cout << "Reverse array A is " << rev_array_A[i] << endl;
    }
    cout << endl;
    cout << endl;
    for (i = 0; i < m; i++)
    {
        rev_array_B[(m - 1) - i] = array_B[i];
    }
    for (i = 0; i < m; i++)
    {
        cout << "Reverse array B is " << rev_array_B[i] << endl;
    }
}

void numOfOccur(int array_A[], int array_B[], int num)
{
    int i;
    int count_a = 0;
    int count_b = 0;
    for (i = 0; i < m; i++)
    {
        if (array_A[i] == num)
        {
            count_a += 1;
        }
        else
        {
            count_a = count_a;
        }
    }
    cout << "Number of occurence of integer in array A " << num << " is " << count_a << endl;

    for (i = 0; i < m; i++)
    {
        if (array_B[i] == num)
        {
            count_b += 1;
        }
        else
        {
            count_b = count_b;
        }
    }
    cout << "Number of occurence of integer in array A " << num << " is " << count_b << endl;
}
int main()
{
    int num;
    int array_A[m];
    int array_B[m];
    cout<<"Firstly set the value of arrays"<<endl;
    setArrData(array_A, array_B);
    cout << "Enter your choice from the following options. " << endl;
    cout << "1. want to print data of array. " << endl;
    cout << "2. want to test array A is equal to B or not." << endl;
    cout << "3. want to reverse the array. " << endl;
    cout << "4. want a search for a element in the both array." << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {

        printArrData(array_A, array_B);
    }
    else if (choice == 2)
    {
        testData(array_A, array_B);
    }
    else if (choice == 3)
    {
        reverseArray(array_A, array_B);
    }
    else if (choice == 4)
    {
        cout << "Enter the integer you want to search for " << endl;
        cin >> num;
        numOfOccur(array_A, array_B, num);
    }
    else
    {
        cout<<"Invalid Input"<<endl;
    }

    return 0;
}