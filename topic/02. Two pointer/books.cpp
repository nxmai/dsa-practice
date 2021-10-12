//codeforces

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, t, tmp;
    vector<int> nums;

    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        nums.push_back(tmp);
    }

    int i = 0, j = 0;
    int res = 0, count = 1;
    int sum = 0;

    do {
        sum += nums[j];
        if(sum > t){
            count --;
            res = max(res, count);
            sum -= nums[i];
            i++;
            j++;
            count++;
        } else {
            j++;
            count++;
        }

    }while (j < n);

    res = max(res, count - 1);

    cout << res;

    return 0;
}