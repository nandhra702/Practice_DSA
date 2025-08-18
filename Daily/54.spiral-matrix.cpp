/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //lets have limits firstly.
        int left = 0;
        int right = n;
        int top = 0;
        int bottom = m;
        vector<int>ans;
        
        while(top<bottom && left<right){
            
            //firstly print all elemets of the row top is pointing to.
            for(int i=left;i<right;i++){
                ans.push_back(matrix[top][i]);
            }
            
            top++;

            //now I want all emements of rightmost column
            for(int i = top;i<bottom;i++){
                ans.push_back(matrix[i][right-1]);
            }

            right--;

            //i need a break condition here 
            if(top>=bottom || left>=right ){
                break;
            }

            //now I need to go back
            for(int i=right-1;i>=left;i--){
                ans.push_back(matrix[bottom-1][i]) ;
            }
            
            bottom--;

            //now I need to move upwards
            for(int i=bottom-1;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
           

            left++;

        }

        return ans;

    }
};
// @lc code=end

