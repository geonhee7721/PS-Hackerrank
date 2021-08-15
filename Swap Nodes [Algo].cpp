
/*
 * Swap Nodes [Algo] - Search - Medium
 * https://www.hackerrank.com/challenges/swap-nodes-algo/problem
 */

void swapping(vector<vector<int>> &indexes, int depth, int current, int k) {
    if (current == -1) return;
    if (depth % k == 0) swap(indexes[current - 1][0], indexes[current - 1][1]);
    
    swapping(indexes, depth + 1, indexes[current - 1][0], k);
    swapping(indexes, depth + 1, indexes[current - 1][1], k);
}

void inorder(vector<vector<int>> &indexes, vector<int> &result, int current) {
    if (current == -1) return;
    
    inorder(indexes, result, indexes[current - 1][0]);
    result.push_back(current);
    inorder(indexes, result, indexes[current - 1][1]);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> result;
    
    for (int i = 0; i < queries.size(); ++i) {
        swapping(indexes, 1, 1, queries[i]);
        vector<int> resultTemp;
        inorder(indexes, resultTemp, 1);
        result.push_back(resultTemp);
    }
    
    return result;
}
