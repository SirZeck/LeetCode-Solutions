// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> dict;
        int maxlen = 0, start = -1;
        
        for (int i = 0; i != s.length(); i++) {
            if (dict.count(s[i]) != 0) {
                start = max(start, dict[s[i]]);
            }
            dict[s[i]] = i;
            maxlen = max(maxlen, i - start);
        }
        return maxlen;
    }
};