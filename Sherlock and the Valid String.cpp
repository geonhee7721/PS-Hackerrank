/*
 * Sherlock and the Valid String - String Maniputaion - Medium
 * https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
 */

string isValid(string s) {
    vector<int> times(26);
    for (char c : s) {
        times[c - 'a']++;
    }
    sort(times.begin(), times.end(), greater<int>());
    
    int deleted = 0;
    
    for (int i = 0; i < 26; ++i) {
        if (times[i] == 0) break;
        
        if (abs(times[1] - times[i]) == 1 || times[i] == 1) {
            if (deleted++ > 0) return "NO";
        } 
        else if (abs(times[1] - times[i]) > 1) {
            return "NO";
        }
    }
    return "YES";
}
