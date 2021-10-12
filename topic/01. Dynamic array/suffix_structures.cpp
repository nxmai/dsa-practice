//codeforces
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isAutomaton ( string s1, string s2) {
    int i = 0, j = 0;
    int n1 = s1.length(), n2 = s2.length();

    while( i < n1 && j < n2){
        if(s1[i] == s2[j]){
            i++; j++;
        } else {
            i++;
        }
    }

    if(j == n2)
        return true;
    return false;
}

string suffix(string s1, string s2){
    if(isAutomaton(s1, s2))
        return "automaton";

    if(s1.length() == s2.length()){
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if(s1 == s2)
            return "array";
    }

    vector<int>s1Arr(26, 0);
    vector<int>s2Arr(26, 0);
    int flag = -1;

    for(int i = 0; i < s1.length(); i++)
        s1Arr[(int)s1[i] - 97]++;

    for(int i = 0; i < s2.length(); i++)
        s2Arr[(int)s2[i] - 97]++;

    for(int i = 0; i < 26; i++){
        if(s2Arr[i] > s1Arr[i])
            flag = 0;
    }

    if(flag == -1)
        return "both";
    
    return "need tree";
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

   cout << suffix(s1, s2);
    
    return 0;

}