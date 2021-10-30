// Problem Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        if(n < 3){
            return false;
        }
        int aliceCnt = 0, bobCnt = 0, i = 0;
        while(i < n){
            int j = i;
            while(j < n && colors[j] == colors[i]){
                j++;
            }
            if(colors[i] == 'A'){
                aliceCnt += max(0, j - i - 2);
            }else{
                bobCnt += max(0, j - i - 2);
            }
            i = j;
        }
        return aliceCnt > bobCnt;
    }
};