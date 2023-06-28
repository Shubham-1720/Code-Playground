#include <iostream>
using namespace std;

int compare_string(string str1, string str2)
{
    int length_str1, length_str2;
    length_str1 = str1.length();
    length_str2 = str2.length();
    for (int i = 0; i < 8; i++)
    {
        if (str1[i] != str2[(length_str2 - 8) + i])
        {
            cout << "Both strings are not equal" << endl;
            return 0;
        }
    }
    cout << "Both strings are equal" << endl;
    return 1;
}

void append_string(string str1, string str2)
{
    for (int i = 3; i < 8; i++)
    {
        str2 = str2 + str1[i];
    }
    cout << "final String after appending " << str2 << endl;
}

void occurence_string(string str1, string str2)
{
    string sub_str;
    
    for(int i =0; i<4; i++){
        sub_str = sub_str + str1[i];
    }
    for(int i = 0; i<4; i++)
    {
        int index_arr[10] = {0};
        int index = 0;
        for(int j=0; j<str2.length(); j++)
        {
            if(sub_str[i]==str2[j])
            {
                index_arr[index] = j;
                index +=1;
            }
        }
        cout<<"First occurence of first character in str1 that is "<<sub_str[i]<<" is "<<index_arr[0]<<endl;
    }
}

int main()
{
    string str1 = "shubhamakushwaha";
    string str2 = "kushwahashubhama";
    // compare_string(str1, str2);
    // append_string( str1, str2);
    // occurence_string(str1, str2);
    return 0;
}