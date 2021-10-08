#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> construct2DArray(vector<int>& ori, int m, int n) {
    vector<vector<int>>res;
    
    if(m*n != ori.size()) return {};
    
    for(int i = 0; i < m; i++){
        vector<int>tmp;
        for(int j = 0; j < n; j++){
            tmp.push_back(ori[i*n + j]);
        }
        res.push_back(tmp);
    }
    
    return res;
}