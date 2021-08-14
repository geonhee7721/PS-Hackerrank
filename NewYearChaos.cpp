/*
 * New Year Chaos - Arrays - Medium
 * https://www.hackerrank.com/challenges/new-year-chaos/problem
 */
 
void minimumBribes(vector<int> q) {
    int n = q.size();
    
    int count = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (q[i] != i + 1) {
            if (i - 1 >= 0 && q[i - 1] == i + 1) {
                swap(q[i], q[i-1]);
                count++;
            } else if (i - 2 >= 0 && q[i - 2] == i + 1) {
                int temp = q[i];
                q[i] = q[i - 2];
                q[i - 2] = q[i - 1];
                q[i - 1] = temp;
                count += 2;
            } else {
                cout << "Too chaotic\n";
                return;
            }
        }
    }
    
    cout << count << endl;
}
