/*
 * Max Array Sum - Dynamic Programming - Medium
 * https://www.hackerrank.com/challenges/max-array-sum/problem
 */

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    int dp[100001];
    int n = arr.size();
    
    dp[0] = max(0, arr[0]);
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; ++i) dp[i] = max({dp[i - 2] + arr[i], dp[i - 2], dp[i - 1]});
    
    return dp[n - 1];
}
