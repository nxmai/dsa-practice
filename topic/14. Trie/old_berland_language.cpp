#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    struct Node*child[2];
    int isBlock;
    struct Node *parent;
};

struct Node *newNode(){
    struct Node *node = new Node;
    node->isBlock = 0;
    node->parent = NULL;
    for(int i = 0; i < 2; i++){
        node->child[i] = NULL;
    }
    return node;
};

string s;
bool addWord(struct Node* root, int len){
    Node *tmp = root;
    if(root->isBlock == 1) return false;
    s = "";

    for(int i = 0; i < len; i++){
        int check_1 = -1;
        bool canMove = false;
        for(int j = 2 - 1; j >= 0; j--){
            if(tmp->child[j] != NULL){
                if(tmp->child[j]->isBlock == 0){
                    s = s + (char)('0' + j);
                    tmp = tmp->child[j];
                    canMove = true;
                    break;
                }
            }
            if(tmp->child[j] == NULL)
                check_1 = j;
        }
        if(!canMove){
            if(check_1 == -1){
                return false;
            } else {
                s = s + char('0' + check_1);

                tmp->child[check_1] = newNode();
                tmp->child[check_1]->parent = tmp;
                tmp = tmp->child[check_1];
            }
        }
    }

    tmp->isBlock = 1;
    while(tmp != NULL){
        if (tmp->child[0] != NULL && tmp->child[1] != NULL)
          if (tmp->child[0]->isBlock * tmp->child[1]->isBlock == 1)
              tmp->isBlock = 1;
        tmp = tmp->parent;
    }
    return true;
}

int main(){
    int n, len; 
    cin >> n;

    vector<pair<int, int>>a;
    struct Node* root = newNode();
    for(int i = 0; i < n; i++){
        cin >> len;
        a.push_back({len, i});
    }

    sort(a.begin(), a.end());
    vector<string>ans(10001);

    for(int i = 0; i < n; i++){
        int len = a[i].first;
        if(addWord(root, len) == false){
            cout << "NO";
            return 0;
        } else{
            ans[a[i].second] = s;
        }
    }
    cout << "YES" << '\n';
    for(int i = 0; i < n; i++){
        cout << ans[i] << '\n';
  	}

    return 0;
}