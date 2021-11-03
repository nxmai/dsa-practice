//spoj
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int sheeps = 0, wolves = 0;

bool isValid(int a, int b, int m, int n)
{
    return (a >= 0 && a < m && b >= 0 && b < n);
}

void bfs(int m, int n, vector<vector<char>> &yard, int i , int j)
{
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    queue<pair<int, int>> q;
    q.push({i, j});

    int cntSheep = (yard[i][j] == 'k');
    int cntWolves = (yard[i][j] == 'v');

    bool canEscape = false;
    yard[i][j] = '#';

    while (!q.empty())
    {
        auto pos = q.front();
        q.pop();

        int u = pos.first;
        int v = pos.second;

        for (auto dir : dirs)
        {
            int a = u + dir[0];
            int b = v + dir[1];

            if (!isValid(a, b, m, n))
            {
                canEscape = true;
                continue;
            }

            if (yard[a][b] != '#')
            {
                cntSheep += (yard[a][b] == 'k');
                cntWolves += (yard[a][b] == 'v');
                yard[a][b] = '#';
                q.push({a, b});
            }
        }
    }
    if (canEscape)
    {
        sheeps += cntSheep;
        wolves += cntWolves;
    }
    else
    {
        cntSheep > cntWolves ? sheeps += cntSheep : wolves += cntWolves;
    }

}

int main()
{
    int m, n;
    char c;
    vector<vector<char>> yard;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        vector<char> tmp;
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            tmp.push_back(c);
        }
        yard.push_back(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (yard[i][j] != '#')
            {
                bfs(m, n, yard, i, j);
            }
        }
    }

    cout << sheeps << " " << wolves;
    return 0;
}