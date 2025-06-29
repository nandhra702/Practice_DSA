/*
PREORDER TRAVERSAL OF BINARY TREE : Q-144
TOPIC - BINARY TREE
LEVEL - EASY
SOURCE - LEETCODE : STRIVER
*/

#include<vector>
#include<stdio.h>
#include<stack>
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


/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //we need to return a vector with preorder traversal
        vector<int>result;
        if(root==NULL){
            return result;    //simply return
        }
            result.push_back(root->val);
            
            vector<int>left = preorderTraversal (root->left);
            //now we need to add this vector to result vector
            result.insert(result.end(),left.begin(),left.end());

            //now, same for right side
            vector<int>right = preorderTraversal(root->right) ;
            //now we need to add this vector to result vector
            result.insert(result.end(),right.begin(),right.end());



           
            return result;
    }

    
};*/

class Solution{
public:vector<int> preorderTraversal(TreeNode* root) {
    //okay, what we do is, first we push the first element in the stack.
    vector<int>result;
    if(root==NULL){
        return result;
    }

    //now we create a stack
    stack<TreeNode*>stk;
    stk.push(root);

    while(!stk.empty()){
        TreeNode* node = stk.top();
        result.push_back(stk.top()->val);
        stk.pop();
        if(node->right){
            stk.push(node->right);
        }
        if(node->left){
            stk.push(node->left);
        }    
    
    }

    return result;


}
};



// @lc code=end

