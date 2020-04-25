/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (36.92%)
 * Likes:    970
 * Dislikes: 0
 * Total Accepted:    232.5K
 * Total Submissions: 628.7K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
class Solution {
public:
    int minLength(vector<string>& strs) {
        int min = INT_MAX;
        for (auto& str: strs)
        {
            min = min < str.length() ? min : str.length();
        }
        return min;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        
        int min = minLength(strs);
        string res = "";
        for (int i = 0; i < min; i++)
        {
            char last = strs[0][i];
            for (auto& str: strs)
            {
                if (last != str[i])
                {
                    return res;
                }
            }
            res.push_back(last);;
        }
        return res;
    }
};
// @lc code=end

