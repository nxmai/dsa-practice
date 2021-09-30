//codeforces

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, tmp;
    int countZero = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp == 0)
            countZero++;
    }

    if((countZero == 1 && n != 1) || (countZero == 0 && n==1))
        cout << "YES";
    else 
        cout << "NO";

    return 0;
}