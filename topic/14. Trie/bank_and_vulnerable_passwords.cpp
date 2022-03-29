#include <iostream>
#include <string>

using namespace std;
#define MAX 26

struct Node
{
    struct Node *child[MAX];
    int countWord;
};

struct Node *newWord()
{
    struct Node *node = new Node;
    node->countWord = 0;

    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    return node;
}

bool isEmpty(struct Node *node)
{
    for (int i = 0; i < MAX; i++)
    {
        if (node->child[i] != NULL)
            return false;
    }
    return true;
}

bool addWord(struct Node *root, string s)
{
    int ch;
    struct Node *tmp = root;
    bool res = false;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        ch = s[i] - 'a';
        if (tmp->child[ch] == NULL)
        {
            tmp->child[ch] = new Node();
        }
        tmp = tmp->child[ch];
        if (tmp->countWord > 0)
        {
            res = true;
        }
    }
    tmp->countWord++;
    if (res)
    {
        return true;
    }

    res = isEmpty(tmp);
    if (res)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void removeWord(struct Node *root)
{
    for (int i = 0; i < MAX; i++)
    {
        if (root->child[i] != NULL)
        {
            removeWord(root->child[i]);
        }
    }
    delete root;
}

int main()
{
    int n;
    string s;

    cin >> n;

    struct Node *root = new Node();
    int flag = 1;
    bool check;

    for (int j = 0; j < n; j++)
    {
        cin >> s;
        check = addWord(root, s);
        if (check && flag == 1)
        {
            flag = 0;
        }
    }

    if (flag)
    {
        cout << "non vulnerable";
    }
    else
    {
        cout << "vulnerable";
    }

    removeWord(root);

    return 0;
}