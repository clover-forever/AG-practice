#include <bits/stdc++.h>

using namespace std;

struct Task
{
    bool isdone;
    int preTaskCount;
    vector<int> afterTasks;

    Task()
    {
        preTaskCount = 0;
        isdone = false;
    }
};

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        Task tasks[505];

        for (int line = 0; line < m; ++line)
        {
            int i, j;
            cin >> i >> j;
            ++(tasks[j].preTaskCount);
            tasks[i].afterTasks.push_back(j);
        }

        for (int printedCount = 0; printedCount < n;)
        {
            if (printedCount > 0)
                cout << " ";

            bool isFindOneJob = false;
            for (int i = 1; !isFindOneJob; i = i % n + 1)
            {
                if (!(tasks[i].isdone) && tasks[i].preTaskCount == 0)
                {
                    cout << i;
                    tasks[i].isdone = true;

                    for (int j = 0; j < tasks[i].afterTasks.size(); ++j)
                    {
                        --(tasks[tasks[i].afterTasks[j]].preTaskCount);
                    }
                    ++printedCount;
                    isFindOneJob = true;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}