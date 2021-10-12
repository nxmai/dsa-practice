//codeforces
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct point {
    int x;
    int y;
};

bool compare(const point& a, const point& b)
{
    if(a.x < b.x || (a.x == b.x && a.y < b.y))
        return true;
    return false;    
}

int main() {
    vector<point>arr;
    set<int> setX;
    set<int> setY;
    
    for(int i = 0; i < 8; i++){
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
        setX.insert(x);
        setY.insert(y);
    }

    sort(arr.begin(), arr.end(), compare);
    int flag = 1;
    set<int>::iterator itX = setX.begin();
    set<int>::iterator itY = setY.begin();


    if(setX.size() == 3 && setY.size() == 3){
        for(int i = 0; i < 3; i++){
            if(arr[i].x != (*itX) || arr[i].y != (*itY)){
                flag = 0;
            }
            itY++;
        }
        
        itX++;
        itY = setY.begin();
        for(int i = 3; i < 5; i++){
            if(arr[i].x != (*itX) || arr[i].y != (*itY)){
                flag = 0;
            }
            itY++;
            itY++;
        }

        itX++;
        itY = setY.begin();
        for(int i = 5; i < 8; i++){
            if(arr[i].x != (*itX) || arr[i].y != (*itY)){
                flag = 0;
            }
            itY++;
        }
    } else {
        flag = 0;
    }

    if(flag == 1){
        cout << "respectable";
    } else {
        cout << "ugly";
    }
    
    return 0;

}