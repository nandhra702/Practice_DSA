/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newinterval) {
        vector<vector<int>>ans;
        int i = 0;
        int n = interval.size();
        
        //setting all intervals that are towards the left
        while( i < n && interval[i][1]<newinterval[0]){
            //then simply push them
            ans.push_back(interval[i]);
            i++;
        }

        while(i<n && interval[i][0]<= newinterval[1]){
            newinterval[0] = min(newinterval[0],interval[i][0]);
            newinterval[1] = max(newinterval[1],interval[i][1]);
            i++;
        }
        ans.push_back(newinterval);
        while(i<n){
            ans.push_back(interval[i]);
            i++;
        }
         return ans;
    }
   
};
// @lc code=end

