/*
STRIVER SHEET MEDIUM
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        
        /*SO WHAT I DID IS, YOU SIMPLY FIND THE PATH FROM GIVEN NODES TO ROOT. THEN YOU HAVE THESE PATHS AND COMPARE THEM
        WHERE EVER THEY DIVERGE, WE TAKE AN ELEMENT BEFORE THAT. THEN WE DO PREORDER TRAVERSAL TO RETURN THE NODE WITH 
        THAT VALUE */



        bool getPath(TreeNode* root, vector<int>&vec, int x){
            if(root==NULL){
                return false;
            }
            vec.push_back(root->val);
            if(root->val==x){
                return true;
            }
    
            if(getPath(root->left, vec, x) || getPath(root->right, vec, x)){
                return true;
            }
    
            //means both left and right are false
            vec.pop_back();
            return false;
    
        }
    
         void preorder(TreeNode* root, int target, TreeNode*& ans) {
            if (!root || ans) return;
            if (root->val == target) {
                ans = root;
                return;
            }
            preorder(root->left, target, ans);
            preorder(root->right, target, ans);
        }
    
    
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            vector<int>arr1;
            vector<int>arr2;
            int val1 = p->val;
            int val2 = q->val;
    
            //now, I gotta call the getPath function for both
            getPath(root,arr1,val1);
            getPath(root,arr2,val2);
            int val;
    
            //now, we just gotta check when is the next element not equal;
            
            int i = 0;
        while (i < arr1.size() && i < arr2.size() && arr1[i] == arr2[i]) {
            i++;
        }
        val = arr1[i - 1]; // Last common node before divergence
    
            //now, we just have to find the node which has a value val.
            //we can do BFS for that.
            TreeNode* ans = nullptr;
            preorder(root,val,ans);
            return ans;
    
    
        }
    };
// @lc code=end

