/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> last;
        for (int i = 0; i < numRows; ++i) {
          vector<int> r;
          for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) r.push_back(1);
            else {
              r.push_back(last[j-1] + last[j]);
            }
          }
          res.push_back(r);
          last = std::move(r);
        }
      return res;
    }
};
// @lc code=end

