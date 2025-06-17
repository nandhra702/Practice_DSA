/*
 FIRST POSITIVE MISSING NUMBER : 41
TOPIC - ARRAYS
LEVEL - HARD
SOURCE - EMAIL
 */

// @lc code=start

#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

//brute force whivh does not use inplace replacements
/*
class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            if (nums.empty()) return 1;
            //solving using an extra array
            long maximum = *max_element(nums.begin(),nums.end()); //max is used to compare 2 numbers and max_element gives iterator, so you need to dereference it.
            if(maximum<=0) return 1;
            int size = nums.size();
            vector<bool>checker(maximum+2,false);
    
            for(int i=0;i<size;i++){
                if(nums[i]>0){
                    checker[nums[i]]=true;
                }
            }
            
             int result=0;   
    
    
            for(long i=1;i<checker.size();i++){
                if(checker[i]==false){
                    result=i;
                    break;
                }
    
            }
            
            return result;
        }
    };
*/

//THIS IS THE OPTIMAL INPLACE REPLACEMENT ALGORITHM
//WHAT WE DO IS, ANY NUMBER <=0 OR >SIZE, WE SET IT TO 1. then we go on every nums[i], and then change the sign of number
// which is present at the location where index = nums[i]. Now, we also keep a consideration of always taking absolute value
// and then changing the sign as what if we change negative numbers back to positive.


class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            bool contains1=false;
            int size = nums.size();
    
            for(int i=0;i<size;i++){
                if(nums[i]==1){
                    contains1 = true;
                }
    
                if(nums[i]>size || nums[i]<=0){
                    nums[i]=1;
                }
            }
    
            if(contains1==false){
                return 1;
            }
    
            //now data cleaning has been done
            //now we are gonna start changing signs
            for(int i=0;i<size;i++){
                int index = abs(nums[i]);
                if (index <= size) {
                    nums[index - 1] = -abs(nums[index - 1]);  // Mark as negative
                }
            }
    
            //now go through the whole thing
            for(int i=0;i<size;i++){
                if(nums[i]>0){
                    return i+1;
                }
            }
    
            return size+1;
        }
    };


// @lc code=end

