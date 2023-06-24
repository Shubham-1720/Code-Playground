#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(int argc, char*argv[])
{
    int n = atoi(argv[1]);
    float s = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            s = s + float(1 / pow(i, i));
        }
        else
        {
            s = s - float(1 / pow(i, i));
        }
    }
        cout << "Sum of series upto " << s << endl;
        return 0;
    }