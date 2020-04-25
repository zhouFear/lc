/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.26%)
 * Likes:    1972
 * Dislikes: 0
 * Total Accepted:    227.5K
 * Total Submissions: 777.7K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
{
    if (s.empty()) return "";
    int len = s.size();
    if (len == 1)return s;
    int longest = 1;
    int start=0;
    vector<vector<int> > dp(len,vector<int>(len));
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if(i<len-1)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                start=i;
                longest=2;
            }
        }
    }
    for (int l = 3; l <= len; l++)//子串长度
    {
        for (int i = 0; i+l-1 < len; i++)//枚举子串的起始点
        {
            int j=l+i-1;//终点
            if (s[i] == s[j] && dp[i+1][j-1]==1)
            {
                dp[i][j] = 1;
                start=i;
                longest = l;
            }
        }
    }
    return s.substr(start,longest);
}
};
// @lc code=end
