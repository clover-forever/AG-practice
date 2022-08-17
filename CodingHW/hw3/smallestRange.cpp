#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums) {
        int curMax = INT_MIN, n = nums.size();
        vector<int> idx(n, 0);
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {return a.first > b.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) > q(cmp);
        for (int i = 0; i < n; ++i) {
            q.push({nums[i][0], i});
            idx[i] = 1;
            curMax = max(curMax, nums[i][0]);
        }
        vector<int> res{q.top().first, curMax};
        while (idx[q.top().second] < nums[q.top().second].size()) {
            int t = q.top().second; q.pop();
            q.push({nums[t][idx[t]], t});
            curMax = max(curMax, nums[t][idx[t]]);
            ++idx[t];
            if (res[1] - res[0] > curMax - q.top().first) {
                res = {q.top().first, curMax};
            }
        }
        return res;
}

int main(){
    int N, M, num;
    vector<vector<int>> lists;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> M;
        lists.push_back(vector<int>());
        for(int j = 0; j < M; j++){
            cin >> num;
            lists[i].push_back(num);
        }
    }
    vector<int> ret = smallestRange(lists);
    cout << ret[0] << " " << ret[1] << "\n";
    return 0;
}