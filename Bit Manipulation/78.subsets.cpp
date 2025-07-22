/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

 // MEDIUM WEIRDASS QUESTION


// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        //firstly we need to see how many subsets can be there
        int size = nums.size();
        //number of subsets
        int num= 1<<size;
        //we create a vector of vector
        vector<vector<int>>vec_outer;

        for(int i=0;i<num;i++){
            vector<int>vec_inner;
            //now I need to check if the ith element is included or not.
            //means I need to push all combinations of bits
            //here nums[j] is the jth element;
            for(int j=0;j<size;j++){

                //now I check if the ith bit is 1
                if( i & 1<<j ){
                    vec_inner.push_back(nums[j]);
                }

            }
            vec_outer.push_back(vec_inner);

        }
        return vec_outer;

    }
};
// @lc code=end

