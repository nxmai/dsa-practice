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
    int n, k, t;
    vector<int> vt;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vt.push_back(t);
    }

    sort(vt.begin(), vt.end());

    int res = 0;

    for (int j = 0; j < vt.size(); j++)
    {
        int index = binarySearch(vt, j + 1, n - 1, k + vt[j]);
        if (index != -1)
        {
            res++;
        }
    }
    cout << res;

    return 0;
}