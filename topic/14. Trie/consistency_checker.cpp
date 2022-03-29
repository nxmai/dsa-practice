#include <iostream>
#include <string>

using namespace std;
#define MAX 10

struct Node {
    struct Node* child[MAX];
    int countWord;
}; 

struct Node *newWord() {
    struct Node *node = new Node;
    node->countWord = 0;

    for(int i = 0; i < MAX; i++){
        node->child[i] = NULL;
    }
    return node;
}

void addWord(struct Node*root, string s){
    int ch;
    struct Node *tmp = root;
    for(int i = 0; i < s.length(); i++){
        ch = s[i] - '0';
        if(tmp->child[ch] == NULL){
            tmp->child[ch] = new Node();
        }
        tmp = tmp->child[ch];
    }
    tmp->countWord++;
}

//int ans = 0;
bool check(struct Node *root){

    for(int i = 0; i < MAX; i++){
        if(root->child[i] != NULL && root->countWord > 0){
            return true;
        }
        if(root->child[i] != NULL){
            if(check(root->child[i])){
                return true;
            } 
        }
    }

    return false;
}

void removeWord(struct Node *root){
    for(int i = 0; i < MAX; i++){
        if(root->child[i] != NULL){
            removeWord(root->child[i]);
        }
    }
    delete root;
}

int main() {
    int n, t;
    string s;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> n;

        struct Node *root = new Node();
        for(int j = 0; j < n; j++){
            cin >> s;
            addWord(root, s);
        }

        cout << "Case " << i << ": " << (check(root) ? "NO" : "YES") << '\n';
        
        removeWord(root);
    }

    return 0;
}