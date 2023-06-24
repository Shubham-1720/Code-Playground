#include<iostream>
#include<string>
using namespace std;

// function to find address of each character
void addressOfCharacter(void)
{
    string s;
    cout<<"Enter your string"<<endl;
    cin>>s;
    for (int i = 0; i < s.length(); i++)
    {
        cout << "Address of character " << s.at(i) << " is " << &i << endl;
    }
}

// function to concatenate two strings
void concatenate_string(void)
{
    cout << "Enter both strings" << endl;
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    s3 = s1 + s2;
    cout << "Concatenated string is: " << s3 << endl;
}

// function to convert lowercase in upparcase
void lower_upper(void)
{
    string text;
    cout << "enter the string" << endl;
    getline(cin, text);
    for (int i = 0; i < text.length(); i++)
    {
        
        if (int(text[i]) >= 97)
        {
            text[i] = char((int(text[i] - 32)));
        }
        else
        {
            text[i] = text[i];
        }
    }
    cout << "Your text in uppercase:- " << text << endl;
}

// function to reverse a string
void reverse(void)
{
    string text1;
    cout << "enter the string" << endl;
    getline(cin, text1);
    string text2;
    for (int i = text1.length() - 1; i >= 0; i--)
    {
        text2 += text1[i];
    }

    cout << "Entered string in reverse is:- " << text2 << endl;
}

// function to insert a string at specific place of another string
void insert_string(void)
{
    string text1;
    string text2;
    int a;
    cout << "enter the string" << endl;
    cin >> text1;
    cout << "enter the string" << endl;
    cin >> text2;
    cout << "Enter the specific location where you want to enter" << endl;
    cin>>a;
    string text3;
    for (int i = 0; i < a; i++)
    {
        text3 += text1[i];
    }
    text3 = text3 + text2;

    for (int i = a; i < text1.length(); i++)
    {
        text3 += text1[i];
    }
    cout << text3;
}

// function to count length of string using pointers
void length_string(void)
{

    const char *str = "Hello world C++ is fun";
    int length = 0;
    const char *ptr = str;
    while (*ptr != '\0')
    {
        length++;
        ptr++;
    }
    cout << "Length of string is " << length;
}
int main()
{
    int choice;
    cout << "1. To show address of each string" << endl;
    cout << "2. To concatenate two strings" << endl;
    cout << "3. To compare two strings" << endl;
    cout << "4. To calculate length using pointers" << endl;
    cout << "5. To convert all lowercase into uppercase" << endl;
    cout << "6. To reverse the string" << endl;
    cout << "7. To insert another string in a string at specifice location" << endl;
    cout << "Enter your choice of operation" << endl;
    cin >> choice;
    if (choice
        == 1)
        {
            addressOfCharacter();
        }
    else if (choice
        == 2)
        {
            concatenate_string();
        }
    else if (choice
        == 3)
        {
            cout << "hey" << endl;
        }
    else if (choice
        == 4)
        {
            length_string();
        }
    else if (choice
        == 5)
        {
            lower_upper();
        }
    else if (choice
        == 6)
        {
            reverse();
        }
    else if (choice
        == 7)
        {
            insert_string();
        }
    else
    {
        cout << "Invalid choice" << endl;
    }
    return 0;
}