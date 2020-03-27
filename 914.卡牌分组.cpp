/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */

// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
      int len = deck.size();
      sort(deck.begin(), deck.end());
      for (int n = 2; n <= len; ++n) {
        if (len % n) continue;
        if (tryying(deck, n)) return true;
      }
      return false;
    }

    bool tryying(vector<int>& deck, int& n) {
      bool res = true;
      for(int i = 0; i < deck.size(); i+=n) {
        if (!res) break;
        int last = deck[i];
        for(int j=i; j < i+n; ++j) {
          if (last != deck[j]) {
            res = false;
            break;
          }
        }
      }
      return res;
    }
};
// @lc code=end

