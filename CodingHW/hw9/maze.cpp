#include <bits/stdc++.h>

using namespace std;

int n, m;
int sx, sy, ex, ey;
int road[300][300];                                  //棋盤
bool is_run[300][300] = {false};                      //是否已經走過
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}; // 分別代表四個方向
bool out = false;                                   //是否可以出去

// 因為要從4個方向出發，所以需要判斷下一個點是否在地圖里
bool in_road(int x, int y)
{
    return (0 <= x && x < n) && (0 <= y && y < m);
}

void DFS(int x, int y, int ex, int ey)
{
    if (x == ex && y == ey)
    {
        //找到出口
        out = true;
        return;
    }
    if (!in_road(x, y) || road[x][y] == 0 || is_run[x][y])
    {
        return;
    }
    is_run[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        DFS(tx, ty, ex, ey);
    }
    return;
}
int main()
{
    
    cin >> n >> m;
    
    cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> road[i][j];
            
        }
    }
    DFS(sx, sy, ex, ey);
    if (out)
    {
        cout << "Success!" << endl;
    }
    else
    {
        cout << "Fail!" << endl;
    }
    return 0;
}