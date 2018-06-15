/** https://leetcode.com/problems/subtree-of-another-tree/description/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

class Solution {
public:
    string dfs(TreeNode* root)
    {
        stringstream ss;
        stack<TreeNode*> stk;
        TreeNode* p;
        stk.push(root);
        while(!stk.empty())
        {
            p = stk.top();
            stk.pop();
            if (p)
            {
                ss << "(" << p->val << ")";
                stk.push(p->right);
                stk.push(nullptr);
                stk.push(p->left);
            }
            else ss << "#";
        }
        string s = ss.str();
        return ss.str();
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        string ss = dfs(s), st = dfs(t);
        cout << ss << "\t" << st;
        return (ss.find(st) != std::string::npos) ;
    }
};