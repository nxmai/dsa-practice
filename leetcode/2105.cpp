#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int left = 0, right = n - 1;
        int res = 0;
        int alice = capacityA, bob = capacityB;
        
        while(left < right){
            if(plants[left] > alice){
                alice = capacityA;
                res++;
            } 
            alice -= plants[left++];
            
            if(plants[right] > bob){
                bob = capacityB;
                res++;
            }
            bob -= plants[right--];
        }
        if(left == right){
            if(alice == bob){
                if(plants[left] > alice){
                    res++;
                }
            } else {
                int maxA = max(alice, bob);
                if(plants[left] > maxA){
                    res++;
                }
            }
            
        }
        return res;
    }
};