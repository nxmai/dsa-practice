#include <iostream>
#include <string>

using namespace std;
#define MAX 26

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
        ch = s[i] - 'a';
        if(tmp->child[ch] == NULL){
            tmp->child[ch] = new Node();
        }
        tmp = tmp->child[ch];
        tmp->countWord++;
    }
}

//int ans = 0;
int findWord(struct Node *root, string s){
    struct Node *tmp = root;

    for(int i = 0; i < s.length(); i++){
        int ch = s[i] - 'a';
        if(tmp->child[ch] == NULL){
            return 0;
        }
        tmp = tmp->child[ch];
    }

    return tmp->countWord;
}

int find(struct Node *root, string &s, int i){
    if(!root){
        return 0;
    }
    
    if(i == s.length() - 1){
        return root->countWord;
    }
    return find(root->child[s[i+1] - 'a'], s, i+1);
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
    string type, s;
    t = 1;

    for(int i = 1; i <= t; i++){
        cin >> n;

        struct Node *root = new Node();
        for(int j = 0; j < n; j++){
            cin >> type >> s;
            if(type == "add"){
                addWord(root, s);
            } else {
                cout << find(root, s, -1) << '\n';
            }
            
        }
        
        removeWord(root);
    }

    return 0;
}