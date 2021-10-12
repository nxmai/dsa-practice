//codeforces

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nA, nB;
    int kA, kB;
    int tmp;
    int valueA, valueB;

    cin >> nA >> nB;
    cin >> kA >> kB;

    for(int i = 0; i < nA; i++){
        cin >> tmp;
        if(i == kA - 1)
            valueA = tmp;
    }

    for(int i = 0; i < nB; i++){
        cin >> tmp;
        if(i + kB == nB)
            valueB = tmp;
    }

    if(valueA < valueB)
        cout << "YES";
    else    
        cout << "NO";

    return 0;
}