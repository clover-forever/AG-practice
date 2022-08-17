#include <iostream>
#include <algorithm>
using namespace std;
struct Pt {
    int x, y, idx, r;
    bool operator<(const Pt &a) const {
        if(x != a.x)
            return x < a.x;
		if(y != a.y){
			return y < a.y;
		}
        return false;
    }
};
Pt D[1000001], X[1000001];
void DCmerge(int l, int m, int r) {
    int idx1 = l, idx2 = m+1, top = 0;
    int d = 0, i;
    while(idx1 <= m && idx2 <= r) {
        if(D[idx1].y <= D[idx2].y && D[idx1].x <= D[idx2].x)
            X[top++] = D[idx1++], d++;
		else
            X[top++] = D[idx2++], X[top-1].r += d;
    }
    while(idx1 <= m)    X[top++] = D[idx1++];
    while(idx2 <= r)    X[top++] = D[idx2++], X[top-1].r += d;
    for(i = 0; i < top; i++){
        
        D[l++] = X[i];
    }
}
void DC(int l, int r) {
    if(l >= r)    return ;
    int m = (l+r)/2;
    DC(l, m);
    DC(m+1, r);
    DCmerge(l, m, r);
}
int main() {
    int x, y, n;
    int output[1000001];
    cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> D[i].x >> D[i].y;
            D[i].idx = i;
        }
        sort(D, D+n);
        DC(0, n-1);
        for(int i = 0; i < n; i++)
            output[D[i].idx] = D[i].r;
        for(int i = 0; i < n; i++)
            cout << output[i] << " ";
            
		cout << "\n";
    return 0;
}