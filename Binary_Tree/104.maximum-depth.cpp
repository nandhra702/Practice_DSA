/*
DEPTH OF BINARY TREE : Q-104
TOPIC - BINARY TREE
LEVEL - EASY
SOURCE - LEETCODE : STRIVER
*/


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 


#include<vector>
#include<stdio.h>
#include<stack>
using namespace std;



class Solution {
public:


    int maxDepth(TreeNode* root) {
        //first lets count the number of nodes, and then we can do log of that number, (floor of log base 2)+1. 
        //BUT THIS WAS ONLY FOR Balanced binary tree. Here tree can be skewed, so height can change.

        //step2 is level order traversal. Do level order traversal and find the size of the queue

        if(root==NULL){
            return 0;
        }

        int leftheight = maxDepth(root->left);
        int rightheight= maxDepth(root->right);

        //return the maximum depth of the tree, adding 1 for the current node
        return 1+ max(leftheight,rightheight);


    }
};
// @lc code=end

