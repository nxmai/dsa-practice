//uva
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int p, n;
    char in;

    cin >> p >> n;

    int cntTest = 1;
    while (p != 0 && n != 0){
        cout << "Case " << cntTest++ << ": " << endl;
        deque<int>qu;
        p = min(p, 1000);
        for(int i = 0; i < p; i++){
            qu.push_back(i + 1);
        }

        for(int i = 0; i < n; i++){
            cin >> in;
            if(in == 'N'){
                cout << qu.front() << endl;
                qu.push_back(qu.front());
                qu.pop_front();

            } else {
                int x;
                cin >> x;
                deque<int>::iterator del = qu.end();
                for (deque<int>::iterator it = qu.begin(); it != qu.end(); it++){
                    
                    if ((*it) == x){
                        del = it;
                    }
                }
              
                if(del != qu.end())
                    qu.erase(del);
                qu.push_front(x);

            }
        }

        cin >> p >> n;
    }

    return 0;
}