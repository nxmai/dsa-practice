//spoj
#include <bits/stdc++.h>
#define MAX 100005;

using namespace std;

struct Job{
    int a, b, d;

    bool operator<(const Job &other) const {
        return a < other.a;
    }
};

bool compare(const Job &a, Job &b){
    return a.d < b.d;
}

int main() {
    int t;
    int n;
    int a, b, d;

    cin >> t;

    while(t!=0){
        cin >> n;
        Job job[100005];
        priority_queue<Job> pq;
        for(int i = 0; i < n; i++){
            cin >> job[i].a >> job[i].b >> job[i].d;
        }

        sort(job, job+n, compare);
        double money = 0;
        int time = 0;

        for(int i = 0; i < n; i++){
            time += job[i].b;
            pq.push(job[i]);

            while(time > job[i].d){
                Job top = pq.top();
                pq.pop();

                if(top.b > time - job[i].d){
                    money += (time - job[i].d) * 1.0 / top.a;
                    top.b -= time - job[i].d;
                    pq.push(top);
                    time = job[i].d;
                } else {
                    money += top.b * 1.0 / top.a;
                    time -= top.b;
                    top.b = 0;
                }
            }
        }

        cout << fixed << setprecision(2) << money << endl;
         
        while (!pq.empty()) {
            pq.pop();
        }

        t--;
    }
}