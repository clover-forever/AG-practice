#include <bits/stdc++.h>
using namespace std;
#define ROW 1000
#define COL 1000
int N, M, sx, sy, ex, ey;
struct Point
{
    int x;
    int y;
};

struct queueNode
{
    Point pt;
    int dist;
};

// bool isValid(int row, int col)
// {

//     return (row >= 0) && (row < ROW) &&
//            (col >= 0) && (col < COL);
// }

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

int BFS(vector<vector<int>> &mat, Point src, Point dest, int N, int M)
{

    if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
        return -1;

    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);

    visited[src.x][src.y] = true;

    queue<queueNode> q;

    queueNode s = {src, 0};
    q.push(s);
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;

        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            if ((row >= 0) && (row < N) && (col >= 0) && (col < M) && mat[row][col] && !visited[row][col])
            {
                visited[row][col] = true;
                queueNode Adjcell = {{row, col},
                                     curr.dist + 1};
                q.push(Adjcell);
            }
        }
    }
    return -1;
}

int main()
{
    
    cin >> N >> M;
    Point source, dest;
    cin >> source.x >> source.y >> dest.x >> dest.y;
    source.x--, source.y--, dest.x--, dest.y--;
    vector<vector<int>> mat;
    int num;
    for(int i = 0; i < N; i++){
        mat.push_back(vector<int>());
        for(int j = 0; j < M; j++){
            
            cin >> num;
            mat[i].push_back(num);
        }
    }
    int dist = BFS(mat, source, dest, N, M);

    if (dist != -1)
        cout << dist;
    else
        cout << -1;

    return 0;
}