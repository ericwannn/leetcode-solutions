/*https://leetcode.com/problems/convert-bst-to-greater-tree/description/
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
 *
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) 
    {
        if(root)
        {
            root->right = convertBST(root->right);
            root->val += sum;
            sum = root->val;
            root->left = convertBST(root->left);
        }
        return root;
    }
};
