#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int T;
char s[maxn];
int now[30];
char t[maxn];
int nex[maxn][30];
void init() {
    memset(now,-1,sizeof(now));
    int len  = strlen(s + 1);
    for(int i = len; i >= 0; i--) {
        for(int j = 0; j < 26; j++) {
            nex[i][j] = now[j];
        }
        if(i)
            now[s[i] - 'a'] = i;
    }
}
int main() {
    cin >> T;
    while(T--) {
        scanf("%s%s",s+1,t+1);
        init();
        int pos = 0;
        int ans = 1;
        bool f = 0;
        int len = strlen(t + 1);
        for(int i = 1; i <= len; i++) {
            int r = t[i] - 'a';
            if(nex[pos][r] == -1) {
                if(nex[0][r] == -1) {
                    f = 1;
                    break;
                }
                ans++;
                pos = 0;
            }
            pos = nex[pos][r];
        }
        if(f == 1) {
            ans = -1;
        }
        printf("%d\n",ans);
    }
}