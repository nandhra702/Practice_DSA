/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    int reverseBits(int n) {
    //first, we will get the bits and then create the equivalent decimanl number
    vector<int>rev;
    

    for(int i=0;i<32;i++){
        int lbit = (n >> i) & 1; //right shift the number itself by i places 
        rev.push_back(lbit);
    }
    //now that we have a reversed binary number, we just have to start from last of vector, to the first
    //and add the results.
    long sum = 0;
    for(int i=31;i>=0;i--){
        sum+= (rev[i] * ( 1<< (31-i) ));
    }
    return sum;

    }
};
// @lc code=end

