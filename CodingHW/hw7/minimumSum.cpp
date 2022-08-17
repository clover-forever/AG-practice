// #include <bits/stdc++.h>

// using namespace std;

// long long solve(int array[], int n)
// {
//     long long counter1, counter2, minimumSum;
//     counter1 = array[n - 1];
//     counter2 = array[n - 2];
//     int i = n - 3;
//     while(i >= 0)
//     {
//         if(counter1 > counter2)
//         {
//             counter2 = array[i];
//         }
//         else
//         {
//             counter1 = array[i];
//         }
//         i--;
//     }
//     if(counter1 > counter2)
//     {
//         minimumSum = counter1 - counter2;
//     }
//     else
//     {
//         minimumSum = counter2 - counter1;
//     }
//     return minimumSum;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     sort(arr, arr + n);
//     cout << solve(arr, n);
//     return 0;
// }

// #include <iostream>
// using namespace std;

// long long minDifference(long long arr[], int n)
// {
//     long long sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//     }
//     long long y = sum / 2 + 1;
//     bool dp[y], dd[y];
//     for (long long i = 0; i < y; i++)
//     {
//         dp[i] = dd[i] = false;
//     }
//     dd[0] = true;
//     for (long long i = 0; i < n; i++)
//     {
//         for (long long j = 0; j + arr[i] < y; j++)
//         {
//             if (dp[j])
//             {
//                 dd[j + arr[i]] = true;
//             }
//         }
//         for (long long j = 0; j < y; j++)
//         {
//             if (dd[j])
//             {
//                 dp[j] = true;
//             }
//             dd[j] = false;
//         }
//     }
//     for (long long i = y - 1; i >= 0; i--)
//     {
//         if (dp[i])
//         {
//             return (sum - 2 * i);
//         }
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     long long arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     cout << minDifference(arr, n) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int findMin(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j)
            {
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    int diff = INT_MAX;
    for (int j = sum / 2; j >= 0; j--)
    {
        if (dp[n][j] == true)
        {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << findMin(arr, n);
    return 0;
}