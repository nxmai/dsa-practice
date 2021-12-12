#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        vector<set<char>> count(10);
        
        for(int i = 0; i < rings.length(); i+=2){
            int index = rings[i+1] - '0';
            count[index].insert(rings[i]);
        }
        
        int cnt = 0;
        for(int i = 0; i < count.size(); i++){
            if(count[i].size() == 3){
                cnt++;
            }
        }
        
        return cnt;
    }
};