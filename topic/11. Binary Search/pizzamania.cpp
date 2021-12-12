//spoj
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int> &a, int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (x == a[mid])
            return mid;
        else if (x < a[mid])
            right = mid - 1;
        else if (x > a[mid])
            left = mid + 1;
    }

    return -1;
}

int main()
{
    int t, n, m;
    int num;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        vector<int> vt;

        for (int j = 0; j < n; j++)
        {
            cin >> num;
            vt.push_back(num);
        }
        sort(vt.begin(), vt.end());

        int index;
        int res = 0;
        for (int j = 0; j < vt.size(); j++)
        {
            index = binarySearch(vt, j + 1, n - 1, m - vt[j]);
            if (index != -1)
            {
                res++;
            }
        }
        cout << res << endl;
    }

    return 0;
}