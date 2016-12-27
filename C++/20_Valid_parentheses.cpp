class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            switch(s[i]) {
                case '(': stk.push('(');  break;
                case '[': stk.push('[');  break;
                case '{': stk.push('{');  break;
                case ')': 
                    if (stk.size() == 0 || stk.top() != '(') return false;
                    else stk.pop();
                    break;
                case ']': 
                    if (stk.size() == 0 || stk.top() != '[') return false;
                    else stk.pop();
                    break;
                case '}': 
                    if (stk.size() == 0 || stk.top() != '{') return false;
                    else stk.pop();
                    break;
            }
        }
        if (stk.size() != 0) return false;
        else return true;
    }
};
