class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1) return 0;
        int ans = 0, cnt = 0;
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++cnt;
                stk.push(i);
            }
            else if (s[i] == ')') {
                if (stk.size() == 0) {
                    cnt = 0;
                }
                else {
                    stk.pop();
                    ++cnt;
                    if (stk.size() == 0) {
                        if (cnt > ans) ans = cnt;
                    }
                }
            }
        }
        if (stk.size() != 0) {
            int len_stk = stk.size();
            int temp = stk.top();
            stk.pop();
            for (int i = 0; i < len_stk; ++i) {
                if (i == 0) {
                    if (s.size()-temp-1 > ans) ans = s.size()-temp-1;
                }
                else {
                    if (temp-stk.top()-1 > ans) ans = temp-stk.top()-1;
                    temp = stk.top();
                    stk.pop();
                }
            }
        }
        
        return ans;
    }
};
