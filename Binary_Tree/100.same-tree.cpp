/*
CHECK IF BINARY TREES ARE SAME: Q-100
TOPIC - BINARY TREE
LEVEL - EASY
SOURCE - LEETCODE : STRIVER
*/
// @lc code=start

//  Definition for a binary tree node.

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
#include<stdio.h>
#include<stack>
#include<string>
#include<vector>
using namespace std;

 



class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string>res1,res2;
        preorder(p,res1);
        preorder(q,res2);
        return res1==res2;
        
    }

    void preorder(TreeNode* root,vector<string>& vec){
        if(root==NULL){
            vec.push_back("NULL");
            return;
        }

        vec.push_back(to_string(root->val));
        preorder(root->left,vec);
        preorder(root->right,vec);
    }
       

    


};
// @lc code=end

