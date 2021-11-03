//hackerearth
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    long long a;
    int n;
    priority_queue<long long>max_heap;

    cin >> n;
    long long l1, l2, l3;
    for(int i = 0; i < n; i++){
        cin >> a;
        max_heap.push(a);
        if(max_heap.size() < 3){
            cout << -1 << endl;
        } else {
            l1 = max_heap.top();
            max_heap.pop();
            l2 = max_heap.top();
            max_heap.pop();
            l3 = max_heap.top();
            
            cout << l1*l2*l3 << endl;

            max_heap.push(l2);
            max_heap.push(l1);
        }
    }

    return 0;

}