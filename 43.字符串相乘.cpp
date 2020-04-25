/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (42.12%)
 * Likes:    316
 * Dislikes: 0
 * Total Accepted:    55.8K
 * Total Submissions: 132.4K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num1 == "0")
            return "0";
        string res = "0";
        auto ita = num1.rbegin();
        int pow = 0;
        while (ita != num1.rend())
        {
            int lv = *ita - '0';
            int rv = 0, s = 0, carry = 0;
            string temp = "";
            for (auto itb = num2.rbegin(); itb != num2.rend(); ++itb)
            {
                rv = *itb - '0';
                s = lv * rv + carry;
                carry = s / 10;
                s %= 10;
                temp.insert(temp.begin(), s + '0');
            }
            if (carry)
            {
                temp.insert(temp.begin(), carry + '0');
            }
            if (temp == "0")
            {
                pow++;
                ita++;
                continue;
            }
            
            int n = pow;
            while (n--)
            {
                temp += "0";
            }

            res = add(res, temp);
            pow++;
            ita++;
        } 
        return res;
    }

    string add(const string &a, const string &b)
    {
        string res = "";
        if (a == "0")
            return b;
        if (b == "0")
            return a;
        auto ita = a.rbegin();
        auto itb = b.rbegin();
        int lv = 0, rv = 0, sum = 0, jw = 0;
        while (1)
        {
            if (ita == a.rend() && itb == b.rend())
                break;
            lv = ita == a.rend() ? 0 : (*ita++) - '0';
            rv = itb == b.rend() ? 0 : (*itb++) - '0';
            sum = lv + rv + jw;
            jw = sum / 10;
            sum %= 10;
            res.insert(res.begin(), sum + '0');
        }
        if (jw)
            res.insert(res.begin(), jw + '0');
        return res;
    }
};
// @lc code=end
