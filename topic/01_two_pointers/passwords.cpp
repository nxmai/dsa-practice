//codeforces
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const std::string& a, const std::string& b)
{
    return (a.size() < b.size()); 
}


int main() {
    int n, k;
    string pwd, tmp;
    vector<string>vt;
    cin>> n >> k;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        vt.push_back(tmp);
    }
    cin >> pwd;
    sort(vt.begin(), vt.end(), compare);

    int best, worst;
    for(int i = 0; i < n; i++){
        if(vt[i].length() == pwd.length()){
            best = i + 1;
            break;
        }
    }

    for(int i = n - 1; i >= 0; i--){
        if(vt[i].length() == pwd.length()){
            worst = i + 1;
            break;
        }
    }

    cout << ((best - 1)/k)*5 + best << " ";
    cout << ((worst - 1)/k)*5 + worst;

    return 0;
}