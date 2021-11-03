//uva
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n;
    long long a;

    cin >> n;
    while(n!=0){
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i = 0; i < n; i++){
            cin >> a;
            pq.push(a);
        }

        long long total = 0, cost = 0;
        while(pq.size() > 1){
            cost = pq.top();
            pq.pop();
            cost += pq.top();
            pq.pop();
            total += cost;
            pq.push(cost);
        }
        cout << total << endl;

        cin >> n;
    }

    return 0;
}