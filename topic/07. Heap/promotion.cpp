//spoj
#include <iostream>
#include <vector>
#include <queue>
const int MAX = 1e6 + 5;

using namespace std;

struct Bill{
    int id;
    int price;
};

struct AscendingPrice{
    bool operator() (const Bill&a, const Bill&b){
        return a.price < b.price;
    }
};

struct DescendingPrice{
    bool operator() (const Bill&a, const Bill&b){
        return a.price > b.price;
    }
};

int main() {
    int n, k, num;
    cin >> n;
    priority_queue<Bill, vector<Bill>, AscendingPrice>maxq;
    priority_queue<Bill, vector<Bill>, DescendingPrice>minq;
    vector<bool>taken(MAX, false);
    long long ans = 0;
    int id = 0;

    while(n!=0){
        cin >> k;
        while(k!=0){
            cin >> num;
            id++;
            maxq.push({id, num});
            minq.push({id, num});
            k--;
        }

        while(taken[maxq.top().id]){
            maxq.pop();
        }

        while(taken[minq.top().id]){
            minq.pop();
        }
        
        ans += maxq.top().price - minq.top().price;
        taken[maxq.top().id] = true;
        taken[minq.top().id] = true;
        maxq.pop();
        minq.pop();

        n--;
    }

    std::cout << ans;
    return 0;
}