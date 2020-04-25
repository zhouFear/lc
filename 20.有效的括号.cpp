/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (auto& c:s) {
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (!st.size()) return false; 
                
                if (c == ')' && st.top() != '(')
                {
                    return false;
                }
                if (c == ']' && st.top() != '[')
                {
                    return false;
                }
                if (c == '}' && st.top() != '{')
                {
                    return false;
                }
                st.pop();
            }
        }
        return !st.size();
    }
};
// @lc code=end

