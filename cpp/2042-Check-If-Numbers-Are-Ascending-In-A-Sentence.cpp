// Problem Link: https://leetcode.com/contest/weekly-contest-263/problems/check-if-numbers-are-ascending-in-a-sentence/

class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> ans;
        int n = s.size();
        
        
        for (int i = 0; i < n; ) {
            if (isdigit(s[i]) && isdigit(s[i + 1])) {
                // ans.push_back(s[i] - '0');
                // ans.push_back(s[i + 1] - '0');
                
                string t = "";
                t += s[i], t+=s[i + 1];
                int tmp = stoi(t);
                ans.push_back(tmp);
                i += 2;
            } else if (isdigit(s[i])) {
                ans.push_back(s[i] - '0');
                i++;
            } else i++;
        }
        
        for (int i : ans) cout << i << ' ';
        
        bool res = true;
        
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i - 1] >= ans[i]) {
                res = false;
            }
        }
        
        return res;
    }
};