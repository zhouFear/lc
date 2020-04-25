/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.73%)
 * Likes:    660
 * Dislikes: 0
 * Total Accepted:    116.9K
 * Total Submissions: 154.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& r, vector<int>& nums) {
        if (r.size() == nums.size())
        {
            res.push_back(r);
            return;
        }
        for (int i: nums)
        {
            if (find(r.begin(), r.end(), i) != r.end())
                continue;
            r.push_back(i);
            backtrack(res, r, nums);
            r.erase(r.end()-1);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> r;
        backtrack(res, r, nums);
        return res;
    }
};
// @lc code=end

