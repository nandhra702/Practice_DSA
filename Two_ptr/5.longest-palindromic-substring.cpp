/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {

        //okay, so what we do is, first we count the number of centers
        //if n is the number of characters, then taking characters as centers, we have n centers.
        //then n characters have n-1 gaps in the middle. So for even length palindromes, we have n-1 centers. Hence in total we have 2n-1 centers
        int n = s.size();
        int longest=0;
        int f_left=-1;
        int f_right = -1;
        //now, we start a length variable which will store the longest palindrome lenght and ptrs.

        int left =0,right=0;

        for(int center = 0 ; center<2*n-1 ; center++){
            left = center/2;
            right = left + (center%2);
            while( (left>=0 && right < n) && s[left]==s[right] ){
                //means, we have found the substring
                int length = right-left+1;
                if(length>longest){
                    f_left = left;
                    f_right = right;
                    longest = length;
                }
                left--;
                right++;
            }

        }

        return s.substr(f_left, f_right - f_left + 1);
    }
        
    
};
// @lc code=end

