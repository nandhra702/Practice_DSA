/*
LEVELORDER TRAVERSAL OF BINARY TREE : Q-102
TOPIC - BINARY TREE
LEVEL - MEDIUM
SOURCE - LEETCODE : STRIVER
*/

#include<vector>
#include<stdio.h>
#include<queue>
using namespace std;

// @lc code=start

// Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };



class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*>Q;
        Q.push(root);

        //now while there is atleast one discovered node
        while(!Q.empty()){
            int size = Q.size();   //current level size

            vector<int>level;

            for(int i=0;i<size;i++){
                TreeNode* node = Q.front();
                Q.pop();
                level.push_back(node->val);

                if(node->left){
                    Q.push(node->left);
                }

                if(node->right){
                    Q.push(node->right);
                }


            }

            result.push_back(level);
        }

        return result;

    }
};
// @lc code=end

