//uva
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    int t;
    string s;

    cin >> t;
    getline(cin, s);
    getline(cin, s);

    while(t!=0){
        map<string, int>mp;
        int n = 0;
        while(getline(cin, s)){
            if(s.size() < 1){
                break;
            }
            mp[s]++;
            n++;
        }

        double percent;
        for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
            percent = it->second * 100.0 / n;
            cout << it->first << " " << fixed << setprecision(4) << percent << endl;
        }

        if(t>1)
            cout << endl;

        t--;
    }


}