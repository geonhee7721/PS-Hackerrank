/*
 * Balanced Brackets - Stack and Queue - Medium
 * https://www.hackerrank.com/challenges/balanced-brackets/problem
 */

bool isLeft(char c) {
     return c == '{' || c == '(' || c == '[';
 }

string isBalanced(string s) {
    unordered_map<char, char> mMap = {make_pair('}', '{'), make_pair(')', '('), make_pair(']', '[')};
    stack<char> mStack;
    
    for (char c : s) {
        if (isLeft(c)) {
            mStack.push(c);
        } else {
            if (mStack.empty()) return "NO";
            if (mStack.top() != mMap[c]) return "NO";
            mStack.pop();
        }
    }
    if (mStack.empty()) return "YES";
    else return "NO";
}
