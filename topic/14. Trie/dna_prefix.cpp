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
    node->countWord = 1;

    for(int i = 0; i < MAX; i++){
        node->child[i] = NULL;
    }
    return node;
}

void addWord(struct Node*root, string s){
    int ch;
    struct Node *tmp = root;
    for(int i = 0; i < s.length(); i++){
        ch = s[i] - 'A';
        if(tmp->child[ch] == NULL){
            tmp->child[ch] = new Node();
        }
        tmp = tmp->child[ch];
        tmp->countWord++;
    }
}

//int ans = 0;
int count(struct Node *root, int len){
    int ans = len*(root->countWord);

    for(int i = 0; i < MAX; i++){
        if(root->child[i] != NULL){
            ans = max(ans, count(root->child[i], len+1));
        }
    }

    return ans;
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

        cout << "Case " << i << ": " << count(root, 0) << '\n';
      
      	removeWord(root);
    }

    
    return 0;
}