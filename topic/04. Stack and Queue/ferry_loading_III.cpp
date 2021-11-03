//uva
#include <iostream>
#include <queue>
#define MAX 10005
using namespace std;

struct Car
{
    int id, arriveTime;
};

int main()
{
    int n, t, m, q;
    int res[MAX];

    cin >> q;
    while (q--)
    {
        queue<Car> qSide[2];
        int arrived;
        string atBank;

        cin >> n >> t >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> arrived >> atBank;

            if (atBank == "left")
            {
                qSide[0].push((Car){i, arrived});
            }
            else
            {
                qSide[1].push((Car){i, arrived});
            }
        }
        
        int curSide = 0, curTime = 0, nextTime;
        int waiting = !qSide[0].empty() + !qSide[1].empty();

        while (waiting)
        {
            if (waiting == 1)
            {
                nextTime = (qSide[0].empty() ? qSide[1].front().arriveTime : qSide[0].front().arriveTime);
            }
            else
            {
                nextTime = min(qSide[0].front().arriveTime, qSide[1].front().arriveTime);
            }

            curTime = max(curTime, nextTime);
            int carried = 0;

            while (!qSide[curSide].empty())
            {
                Car car = qSide[curSide].front();
                if (car.arriveTime <= curTime && carried < n)
                {
                    res[car.id] = curTime + t;
                    carried++;
                    qSide[curSide].pop();
                }
                else
                {
                    break;
                }
            }

            curTime += t;
            curSide = 1 - curSide;
            waiting = !qSide[0].empty() + !qSide[1].empty();
        }

        for (int i = 1; i <= m; i++)
        {
            cout << res[i] << endl;
        }
        if (q)
        {
            cout << endl;
        }
    }
}