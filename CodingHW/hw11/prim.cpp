#include <bits/stdc++.h>

using namespace std;

int n;
const int N = 2010;
vector<string> vs;

int g[N][N];

const int INF = INT32_MAX;

int dist[N];
int st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF)
            return INF;

        if (i)
            res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int main()
{
    while (cin >> n && n != 0)
    {
        memset(g, 0x3f, sizeof(g));
        memset(st, 0, sizeof st);
        vs.clear();
        vs.push_back("no_use,place_holder");
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 1; j < vs.size(); j++)
            {
                int difCount = 0;
                for (int idx = 0; idx < 7; idx++)
                {
                    if (s[idx] != vs[j][idx])
                        difCount++;
                }
                g[j][vs.size()] = g[vs.size()][j] = difCount;
            }
            vs.push_back(s);
        }

        int ret = prim();

        cout << "The highest possible quality is 1/" << ret << "." << endl;
    }
}