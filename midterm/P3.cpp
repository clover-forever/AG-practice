#include <iostream>
#include <algorithm>
using namespace std;
struct Activitiy
{
    int start, end;
};
bool comp(Activitiy act1, Activitiy act2)
{
    return (act1.end < act2.end);
}
void maxActivity(Activitiy act[], int n)
{
    sort(act, act + n, comp);
    
    int i = 0;
    
    int cnt = 1;
    for (int j = 1; j < n; j++)
    {
        if (act[j].start >= act[i].end)
        {
            cnt ++;
            i = j;
        }
    }
    cout << cnt << "\n";
}
int main()
{
    int N, iter;
    cin >> N;
    
    while(N--){
        cin >> iter;
        Activitiy actArr[iter];
        for(int i = 0; i < iter; i++){
            cin >> actArr[i].start >> actArr[i].end;
        }
        maxActivity(actArr, iter);
    }
    return 0;
}