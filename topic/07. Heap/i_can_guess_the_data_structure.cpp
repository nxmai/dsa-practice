//uva
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n;
    int type, num;
    bool isStack, isQueue, isHeap;

    while(cin >> n){
        queue<int>q;
        stack<int>s;
        priority_queue<int>pq;
        isStack = true, isQueue = true, isHeap = true;

        while(n!=0){
            cin >> type >> num;
            if(type == 1){
                q.push(num);
                s.push(num);
                pq.push(num);
            } else {
                if(num != q.front()){
                    isQueue = false;
                } 
                q.pop();
                
                if(num != s.top()){
                    isStack = false;
                } 
                s.pop();
                
                if(num != pq.top()){
                    isHeap = false;
                } 
                pq.pop();
            }
            n--;
        }
        int cnt = isStack + isQueue + isHeap;

        if(cnt >= 2){
            cout << "not sure" << endl;
        } else if(isStack){
            cout << "stack" << endl;
        } else if(isQueue){
            cout << "queue" << endl;
        } else if(isHeap){
            cout << "priority queue" << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
}