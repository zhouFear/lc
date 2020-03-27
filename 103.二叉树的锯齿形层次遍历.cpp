/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode*> nodes;
        int times;
        nodes.push_back(root);
        getNodes(nodes, result, times);
        return result;
    }

    void getNodes(const vector<TreeNode*>& nodes, vector<vector<int>>& result, int& times) {
      vector<int> res;
      vector<TreeNode*> child;
      for(auto& node: nodes) {
        if(!node) continue;
        if(node->left) child.push_back(node->left);
        if(node->right) child.push_back(node->right);
        res.push_back(node->val);
      }
      if (res.size()) {
        if (times++ %2) {
          reverse(res.begin(), res.end());
        }
        result.push_back(res);
      }
      if(!child.size()) {
        return;
      } else {
        getNodes(child, result, times);
      }
    }
};
// @lc code=end

