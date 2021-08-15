/* 
 * Candies - Dynamic Programming - Medium
 * hackerrank.com/challenges/candies/problem
 */
 
 
long candies(int n, vector<int> arr) {
    long sum = 0;
    
    vector<long> result(arr.size());
    result[0] = 1;
    
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] < arr[i]) {
            result[i] = result[i - 1] + 1;
        } else {
            result[i] = 1;
        }
    }
    
    for (int i = arr.size() - 1; i > 0; --i) {
        if (arr[i - 1] > arr[i] && result[i - 1] < (result[i] + 1)) {
            result[i - 1] = result[i] + 1;
        }
    }
    
    for (int i = 0; i < result.size(); ++i) sum += result[i];
    
    return sum;
}
