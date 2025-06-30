/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence : EASY
 * FIND THE LONGEST SUBSEQUENCE WHICH HAS MIN AND MAX ELEMENT DIFFERENCE AS 1
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        //best solution I saw is simply sort it first and then apply sliding window
        sort(nums.begin(),nums.end());

        int left=0,right=0;
        int countmax= 0;

        for(right ; right<nums.size() ; right++){

            while(nums[right]-nums[left]>1){
                left++;
            }
            if(nums[right]-nums[left]==1){
                countmax = max(countmax,right-left+1);
            }

    
        }
        return countmax;
    }
};
// @lc code=end

