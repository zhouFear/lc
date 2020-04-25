/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if (x != 0 && x % 10 == 0) return false;
        long res = 0;
        int t = x;
        while(t) {
          res *= 10;
          res += t%10;
          t /= 10;
        }
        return res == x;
    }
};
// @lc code=end

