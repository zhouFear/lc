/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        if(!s.size()) return 0;
        stack<char> sta;
        int max = 0;
        for (int i = 0; i<s.size(); ++i) {
          if(s[i] == '(') sta.push('(');
          else if (s[i] == ')') {
            if (sta.size() == 0) break;
            else {
              sta.pop();
              max+=2;
            }
          }
        }
        int max1 = longestValidParentheses(s.substr(1));
        return max > max1 ? max : max1;
    }
};
// @lc code=end

