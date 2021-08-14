/*
 * Sherlock and Anagrams - Dictionaries and Hashmaps - Medium
 * https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
 */

int sherlockAndAnagrams(string s) {
    int count = 0;
    
    for (int len = 1; len < s.size(); ++len) {
        unordered_map<string, int> strMap;
        
        for (int index = 0; index + len <= s.size(); ++index) {
            string subStr = s.substr(index, len);
            sort(subStr.begin(), subStr.end());
            
            if (strMap.count(subStr) > 0) strMap[subStr]++;
            else strMap.insert(make_pair(subStr, 1));
        }
        
        for (auto iter = strMap.begin(); iter != strMap.end(); ++iter) {
            count += iter->second * (iter->second - 1) / 2;
        }
    }
    
    return count;
}
