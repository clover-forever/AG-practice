#include <bits/stdc++.h>

using namespace std;

void findMaxSubArrayIndex()
{
    int N, val;
    int start = 0, end = 0, curr_max = 0, prev_max = 0, start_o = 0, i;
    cin >> N;
    vector<int> nums;
    for (i = 0; i < N; i++)
    {
        cin >> val;
        nums.push_back(val);
    }
    prev_max = nums[0];

    for (i = 0; i < N; i++)
    {
        curr_max += nums[i];
        if (curr_max < 0)
        {
            start = i + 1;
            curr_max = 0;
        }
        else if (curr_max > prev_max)
        {
            end = i;
            start_o = start;
            prev_max = curr_max;
        }
    }
    cout << prev_max << " " << start_o + 1 << " " << end + 1;
}

int main()
{
    findMaxSubArrayIndex();
    return 0;
}