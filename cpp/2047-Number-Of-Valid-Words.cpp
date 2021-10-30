// Problem Link: https://leetcode.com/problems/number-of-valid-words-in-a-sentence/

class Solution {
public:
    int countValidWords(string sentence) {
        int n = sentence.size(), prev = 0, ans = 0;
        for(int i = 0; i <= n; i++){
            if(i == n || sentence[i] == ' '){
                if(isValid(sentence.substr(prev, i - prev))){
                    ans++;
                }
                prev = i + 1;
            }
        }
        return ans;
    }
private:
    bool isValid(const string& word){
        if(word.empty()){
            return false;
        }
        int n = word.size(), hyphensIdx = -1;
        for(int i = 0; i < n; i++){
            if(word[i] >= '0' && word[i] <= '9'){
                return false;
            }
            if(word[i] == '-'){
                if(hyphensIdx != -1){
                    return false;
                }
                hyphensIdx = i;
            }
            if(i < n - 1 && (word[i] == '!' || word[i] == '.' || word[i] == ',')){
                return false;
            }
        }
        
        if(hyphensIdx != - 1 && (hyphensIdx == 0 || hyphensIdx == n - 1 || !(word[hyphensIdx-1] >= 'a' && word[hyphensIdx-1] <= 'z') || !(word[hyphensIdx+1] >= 'a' && word[hyphensIdx+1] <= 'z'))){
            return false;   
        }
        return true;
    }
};