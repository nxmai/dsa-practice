//codeforces
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void input(int n, vector<int> &arr)
{
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    return;
}

int main()
{
    int n;
    vector<int> nums;
    set<int> st;
    map<int, int> mp;

    cin >> n;
    input(n, nums);

    int i = 0, j = 0;
    int res = 0;

    while (j < n)
    {
        // st.insert(nums[j]);
        mp[nums[j]] = j;
        if (mp.size() == 3)
        {
            res = max(res, j - i);
            for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
                if(abs(nums[j] - it->first) == 2){
                    i = it->second + 1;
                    mp.erase(it->first);
                    it = mp.end();
                }
            }
        }
        j++;
    }
    res = max(res, j - i);
    cout << res;

    return 0;
}