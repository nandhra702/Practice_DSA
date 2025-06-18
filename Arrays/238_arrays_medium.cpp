/*
PRODUCT OF ARRAY EXCEPT SELF : 238
TOPIC - ARRAYS
LEVEL - MEDUIM
SOURCE - EMAIL

*/

// @lc code=start
#include<vector>
#include<stdio.h>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //we cannot use division (I multiply all numbers and divide by nums[i] as what if its a 0)
        //moreover, they have asked us not to use division.
        //okay so first we need to find products of prefix and suffix;
        //make a vector first

        int size = nums.size();

        vector<int>result_prefix(size,1);
        vector<int>result_suffix(size,1);
        vector<int>result_final(size,1);

        int prefix=1;
        int suffix=1;
        

        for(int i=0;i<size; i++){
            
            result_prefix[i]=prefix;
            prefix=prefix*nums[i];  

        }

        //now same for suffix
        for(int i=size-1;i>=0;i--){

            result_suffix[i]=suffix;
            suffix*=nums[i];

        }

        //now, store the element-wise products
        for(int i=0;i<size;i++){
            result_final[i] = result_prefix[i]*result_suffix[i];
        }

        return result_final;
    }
};
// @lc code=end

