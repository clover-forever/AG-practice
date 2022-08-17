#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int N;

int maximumGap(int *nums) {
    int mx = INT_MIN, mn = INT_MAX, n = N, pre = 0, res = 0;
    for (int i = 0; i < N; i++) {
        mx = max(mx, nums[i]);
        mn = min(mn, nums[i]);
    }
    int size = (mx - mn) / n + 1, cnt = (mx - mn) / size + 1;
    vector<int> bucket_min(cnt, INT_MAX), bucket_max(cnt, INT_MIN);
    for (int i = 0; i < N; i++) {
        int idx = (nums[i] - mn) / size;
        bucket_min[idx] = min(bucket_min[idx], nums[i]);
        bucket_max[idx] = max(bucket_max[idx], nums[i]);
    }
    for (int i = 1; i < cnt; ++i) {
        if (bucket_min[i] == INT_MAX || bucket_max[i] == INT_MIN) continue;
        res = max(res, bucket_min[i] - bucket_max[pre]);
        pre = i;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false); cout.tie(nullptr);
    cin >> N;
    int arr[N];
    if(N == 0){
        cout << 0;
        return 0;
    }
    else{
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cout << maximumGap(arr);
    }
    return 0;
}