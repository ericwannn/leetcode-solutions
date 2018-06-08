/**https://leetcode.com/problems/diameter-of-binary-tree/submissions/1
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
    int getDepth(TreeNode* root)
    {
        if(root)
        {
            int llen = getDepth(root->left);
            int rlen = getDepth(root->right);
            return (max(llen, rlen) + 1);
        }
        else
        {
            return 0;
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {   
        if (root)
        {
            int res = getDepth(root->left) + getDepth(root->right);
            return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
        }
        else return 0;
    }
};