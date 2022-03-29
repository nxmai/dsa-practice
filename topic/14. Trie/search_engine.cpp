#include <string>
#include <iostream>

using namespace std;

#define MAX 26

struct Node {
    struct Node *child[MAX];
    int maxValue;
};

struct Node *newNode() {
    struct Node *node = new Node ;
    node->maxValue = -1;

    for(int i = 0; i < MAX; i++){
        node->child[i] = NULL;
    }

    return node;
};

void addWord(struct Node *root, string s, int value){
    int ch;
    struct Node *tmp = root;
    for(int i = 0; i < s.size(); i++){
        ch = s[i] - 'a';
        if(tmp->child[ch] == NULL){
            tmp->child[ch] = newNode();
        }
        tmp = tmp->child[ch];
        tmp->maxValue = max(tmp->maxValue, value);
    }
}

int getMaxValue(struct Node *root, string s){
    struct Node *tmp = root;
    int ch;
    for(int i = 0; i < s.size(); i++){
        ch = s[i] - 'a';
        if(tmp->child[ch] == NULL)
            return -1;
        tmp = tmp->child[ch];
    }
    return tmp->maxValue;
}


int main() {
    struct Node *root = newNode();
    int n, q, val;
    string s;
    cin >> n >> q;

    for(int i = 0; i < n; i++){
        cin >> s;
        cin >> val;
        addWord(root, s, val);
    }

    for(int i = 0; i < q; i++){
        cin >> s;
        cout << getMaxValue(root, s) << endl;
    }

    return 0;
}