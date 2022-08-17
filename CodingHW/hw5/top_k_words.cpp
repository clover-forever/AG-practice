#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<set>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res(k);
        unordered_map<string, int> freq;
        auto cmp = [](pair<string, int>& a, pair<string, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp) > q(cmp);
        for (auto word : words) ++freq[word];
        for (auto f : freq) {
            q.push(f);
            if (q.size() > k) q.pop();
        }
        for (int i = res.size() - 1; i >= 0; --i) {
            res[i] = q.top().first; q.pop();
        }
        return res;
    }

int main(){
    int N, k;
    cin >> N >> k;
    vector<string> dic;
    string s;
    for(int i = 0; i < N; i++){
        cin >> s;
        dic.push_back(s);
    }
    vector<string> ans = topKFrequent(dic, k);
    int cnt = 0;
    for(string wine: ans){
        cnt++;
        if(cnt == k)
            cout << wine << "\n";
    }
    return 0;
}