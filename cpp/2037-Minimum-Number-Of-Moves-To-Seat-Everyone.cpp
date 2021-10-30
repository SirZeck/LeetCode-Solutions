// Problem Link: https://leetcode.com/contest/biweekly-contest-63/problems/minimum-number-of-moves-to-seat-everyone/

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end()), sort(students.begin(), students.end());
        vector<int> ans(seats.size());
        
        for (int i = 0; i < seats.size(); i++) {
            ans[i] = abs(seats[i] - students[i]);
        }
        
        return accumulate(ans.begin(), ans.end(), 0);
        
        
    }
};