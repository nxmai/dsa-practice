//codeforces
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, b;
    queue<int> qu;
    vector<pair<long long,long long>> vt;
    
    long long t, d;
    cin >> n >> b;
    
    vector<long long> ans(n, 0);

    for(int i = 0; i < n; i++){
        cin >> t >> d;

        vt.push_back({t, d});
    }

    long long process = vt[0].first + vt[0].second;
    ans[0] = process;

    for(int i = 1; i < vt.size(); i++){
        if(vt[i].first < process){
            if( qu.size() < b)
                qu.push(i);
            else 
                ans[i] = -1;
        } else {
            if(!qu.empty()){
                if(process < vt[qu.front()].first)
                    process = vt[qu.front()].first + vt[qu.front()].second;
                else
                    process += vt[qu.front()].second;
                    
                ans[qu.front()] = process;
                qu.pop();

                qu.push(i);
            } else {
                qu.push(i);
            }
        }
    }
    while(!qu.empty()){
        if(process < vt[qu.front()].first)
            process = vt[qu.front()].first + vt[qu.front()].second;
        else
            process += vt[qu.front()].second;
            
        ans[qu.front()] = process;
        qu.pop();
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}
