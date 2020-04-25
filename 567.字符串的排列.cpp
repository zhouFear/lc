/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode-cn.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (34.99%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    23.1K
 * Total Submissions: 65.9K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 * 
 * 换句话说，第一个字符串的排列之一是第二个字符串的子串。
 * 
 * 示例1:
 * 
 * 
 * 输入: s1 = "ab" s2 = "eidbaooo"
 * 输出: True
 * 解释: s2 包含 s1 的排列之一 ("ba").
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: s1= "ab" s2 = "eidboaoo"
 * 输出: False
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的字符串只包含小写字母
 * 两个字符串的长度都在 [1, 10,000] 之间
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for (auto c: s1) mp[c]++;
        int l = 0;
        int r = 0;
        while (l < s2.size())
        {
            char c = s2[l++];
            mp[c]--;
            while (r < l && mp[c] < 0)
            {
                mp[s2[r++]]++;
            }
            if (l - r == s1.size()) return true;
        }
         return false;
        
    }
};
// @lc code=end

