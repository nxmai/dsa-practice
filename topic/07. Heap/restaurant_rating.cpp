//codechef
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// priority_queue<int>q;
priority_queue<int, vector<int>, greater<int>> q;
priority_queue<int> maxq;

int main() {
    int n, x;
    int num;
    cin >> n;

    int k;
    int added = 0;
    for(int i = 1; i <= n; i++){
        k = added / 3;
        cin >> num;

        if(num == 1){
            cin >> x;
            maxq.push(x);
            added++;
        } else{
            if(k == 0)
                cout << "No reviews yet" << endl;
            else {
                while(q.size() != k){
                    q.push(maxq.top());
                    maxq.pop();
                }
                while(q.top() < maxq.top()){
                    int tmp = q.top();
                    q.pop();
                    q.push(maxq.top());
                    maxq.pop();
                    maxq.push(tmp);
                }
                cout << q.top() << endl;
            }
        }

    }
}