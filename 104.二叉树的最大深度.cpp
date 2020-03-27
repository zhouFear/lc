/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
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
    int maxDepth(TreeNode* root) {
      if(!root) return 0;
      vector<TreeNode*> nodes;
      int deep = 0;
      getDeep(nodes, deep);
      return deep;
    }

    void getDeep(const vector<TreeNode*> nodes, int& deep) {
      if(!nodes.size()) return;
      vector<TreeNode*> nodess;
      ++deep;
      for(auto& node: nodes) {
        if(!node) continue;
        if(node->left) nodess.push_back(node->left);
        if(node->right) nodess.push_back(node->right);
      }
      getDeep(nodess, deep);
    }
};
// @lc code=end

