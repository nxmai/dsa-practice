//hackerearth
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Topic {
    int id;
    int new_score;
    int change_score;

    Topic(int id, int new_score, int change_score) :
            id(id), new_score(new_score), change_score(change_score){

            }
};

struct Compare {
    bool operator()(Topic const &t1, Topic &t2){
        if(t1.change_score == t2.change_score){
            return t1.id < t2.id;
        }
        return t1.change_score < t2.change_score;
    }
};

int main() {
    int n;
    int id, old_score, post, like, cmt, share;
    int new_score;
    cin >> n;

    priority_queue<Topic, vector<Topic>, Compare> q;
    while(n!=0){
        cin >> id >> old_score >> post >> like >> cmt >> share;
        new_score = post*50 + like*5 + cmt*10 + share*20;

        q.push(Topic(id, new_score, new_score - old_score));

        n--;
    }

    int k = 5;
    while(q.size() >= 1 && k!=0 ){
        auto t = q.top();
        cout << t.id << " " << t.new_score <<endl;
        k--;

        q.pop();
    }

    return 0;
}