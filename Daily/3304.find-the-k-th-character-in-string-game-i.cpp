/*
 * @lc app=leetcode id=3304 lang=cpp
 *
 * [3304] Find the K-th Character in String Game I
 */

// @lc code=start


class Solution {
public:
    char kthCharacter(int k) {
        //vec.clear
            //okay, first, we find the closest multiple of 2 and so those many iterations have to be done
            int iter_num=0;
            if(k==1){
                return 'a';
            }
            if(k%2==0){
                iter_num = (k/2)-1;
            }
            else{
                iter_num = (k-1)/2 - 1;
            }
    
            //now, we first make a vector to which, we will keep appending
            vector<char>vec1;
            vector<char>vec2; 
            vec1.push_back('a');
    
            //now we will do all additions to vec2, then insert vec2 to end of vec1, then clear vec2 and reuseit
            while(vec1.size()<k){
                for(int j=0;j<vec1.size();j++){
                    if(vec1[j]=='z'){
                        vec2.push_back('a');
                    }
                    else{
                    vec2.push_back(vec1[j]+1);
                    }
                }
                //after this, insert this to end of vec1;
                vec1.insert(vec1.end(),vec2.begin(),vec2.end());
                vec2.clear();
            }
            
            return vec1[k-1];
    }
};
// @lc code=end
