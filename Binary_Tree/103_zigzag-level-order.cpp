/*
ZIG-ZAG LEVELORDER TRAVERSAL OF BINARY TREE : Q-103
TOPIC - BINARY TREE
LEVEL - MEDIUM
SOURCE - LEETCODE : STRIVER
*/

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
 
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }

        queue<TreeNode*>nodesQueue;
        nodesQueue.push(root);
        bool lefttoright = true;

        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int>row(size);
            for(int i=0;i<size;i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                //find position to fill node's value
                /*Determine where to place the value in row.

                    If traversing left to right, place at i.

                    If right to left, place at size-1-i.*/
                
                int index = (lefttoright)?i:(size-1-i);

                row[index] = node->val;
                if(node->left){
                    nodesQueue.push(node->left);
                }

                if(node->right){
                    nodesQueue.push(node->right);
                }

            }

                //after this level is traversed
                lefttoright = !lefttoright; 
                result.push_back(row);
        }
        return result;
    
    }
};
// @lc code=end

