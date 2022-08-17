#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

int partition(vector<float>& nums, int left, int right) {
        float pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) 
                ++l;
            if (nums[r] <= pivot) 
                --r;
        }
        swap(nums[left], nums[r]);
        return r;
}

float findKthLargest(vector<float>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) 
                return nums[pos];
            if (pos > k - 1) 
                right = pos - 1;
            else 
                left = pos + 1;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, k, num1, num2, num3;
    string str;
    cin >> N >> k;
    vector<float> wine;
    float res;
    unordered_map<float, string> ans;
    for(int i = 0; i < N; i++){
        cin >> num1 >> num2 >> num3 >> str;
        res = ((float) num3 / (float) (num1 + num2 + num3));
        wine.push_back(res);
        ans.insert(pair<float, string>(res, str));
    }
    cout << ans[findKthLargest(wine, k)];
    return 0;
}