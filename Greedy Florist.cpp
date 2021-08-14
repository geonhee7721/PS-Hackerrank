/*
 * Greedy Florist - Greedy - Medium
 * https://www.hackerrank.com/challenges/greedy-florist/problem
 */

int getMinimumCost(int k, vector<int> c) {
    sort(c.begin(), c.end(), greater<int>());
    
    int cost = 0;
    int count = 0;
    
    for (int i = 0; i < c.size(); ++i) {
        cost += (c[i] * (count++ / k + 1));
    }
    
    return cost;
}
