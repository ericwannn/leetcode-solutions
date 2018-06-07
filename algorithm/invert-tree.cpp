/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution 
{
  public:
    // Recursive method
    TreeNode* invertTree(TreeNode* root)
    {
      if (root)
      {
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left, root->right);
      }
      return root;
    }

    // Non-recursive method
    TreeNode* invertTree2(Treenode* root)
    {
      std::stack <TreeNode*> stk;
      stk.push(root);

      while (!stk.empty())
      {
        TreeNode* p = stk.top();
        stk.pop()
        if (p)
        {
          stk.push(p->left);
          stk.push(p->right);
          std::swap(p->left, p->right);
        }
      }
      return root;
    }

}