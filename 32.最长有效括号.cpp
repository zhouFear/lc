/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
  int longestValidParentheses(string s)
  {
    int len = s.size();
    vector<int> dp(len, 0);
    int max = 0;
    for (int i = 1; i < len; i++)
    {
      if (s[i] == ')')
      {
        if (s[i - 1] == '(')
        {
          dp[i] = 2;
          if (i - 2 > 0)
          {
            dp[i] = dp[i - 2] + 2;
          }
        } else if (dp[i-1] > 0)
        {
          int j = i - dp[i - 1] - 1;
          if (j >= 0 && s[j] == '(')
          {
            dp[i] = dp[i-1] + 2;
            if (i - dp[i] > 0)
            {
              dp[i] = dp[i] + dp[i - dp[i]];
            }
            
          }
        }
      }
      max = max > dp[i] ? max : dp[i]; 
    }
    return max;
  }
};
// @lc code=end
