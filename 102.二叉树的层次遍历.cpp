/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        getNodes(nodes, result);
        return result;
    }

    void getNodes(const vector<TreeNode*>& nodes, vector<vector<int>>& result) {
      vector<int> res;
      vector<TreeNode*> child;
      for(auto& node: nodes) {
        if(!node) continue;
        if(node->left) child.push_back(node->left);
        if(node->right) child.push_back(node->right);
        res.push_back(node.val);
      }
      if (res.size()) result.push_back(res);
      if(!child.size()) {
        return;
      } else {
        getNodes(child, result);
      }
    }
};
// @lc code=end

