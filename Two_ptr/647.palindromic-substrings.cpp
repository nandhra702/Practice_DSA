/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
     int n = s.size();
        int count = 0;
        
        for (int center = 0; center < 2 * n - 1; ++center) {
            int left = center / 2;
            int right = left + (center % 2); //either it'll be 1 place to the right or at the same place as left ptr.
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};
// @lc code=end

