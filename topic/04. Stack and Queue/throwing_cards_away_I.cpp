//uva
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void process (int n) {
    vector<int>discards;
    stack<int>cards;
    vector<int>tmp={};
    int flag = 0;

    for(int i = n; i >= 1; i--){
        cards.push(i);
    }

    while(tmp.size() != 1){
      	tmp.clear();
      	flag = 0;
        while(!cards.empty()){
            discards.push_back(cards.top());
            cards.pop();
    
            if(cards.empty()){
                tmp.push_back(tmp[0]);
                flag = 1;
            } else {
                tmp.push_back(cards.top());
                cards.pop();
            }
        }

        if(tmp.size() <= 2){
          break;
        }

        for(int i = tmp.size() - 1; i >= 1; i--){
            cards.push(tmp[i]);
        }
        
        if(flag == 0){
          cards.push(tmp[0]);
        }
        
    }
    int ans;
    if(tmp.size() == 2 && tmp[0]!=tmp[1]){
      discards.push_back(tmp[0]);
      ans = tmp[1];
    } else {
      ans =tmp[0];
    }

    cout << "Discarded cards: ";
    for(int i = 0; i < discards.size() - 1; i++){
        cout << discards[i] << ", ";
    }
    cout << discards[discards.size() - 1] <<endl;

    cout << "Remaining card: " << ans << endl;
}
void process2 (int n){
  vector<int>cards;
  vector<int>discards={};

  for(int i = 1; i <= n; i++){
    cards.push_back(i);
  }

  while(cards.size() >= 2){
    discards.push_back(cards.front());
    cards.erase(cards.begin());
    cards.push_back(cards.front());
    cards.erase(cards.begin());
  }

  cout << "Discarded cards: ";
    for(int i = 0; i < discards.size() - 1; i++){
        cout << discards[i] << ", ";
    }
    cout << discards[discards.size() - 1] <<endl;
    
    cout << "Remaining card: " << cards[0] << endl;
}

int main() {
    int n;

    cin >> n;
    while(n != 0){
        if(n== 1){
          cout << "Discarded cards:" <<endl;
          cout << "Remaining card: " << 1 << endl;
        } else {
          process2(n);
        }

        cin >> n;
    }
    

    return 0;
}
