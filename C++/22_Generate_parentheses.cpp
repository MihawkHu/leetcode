class Solution {
public:
    vector<string> ans;
    string s;
    void trace(int left_num, int right_num, int n) {
        if (left_num == n && right_num == n) {
            ans.push_back(s);
        }
        if (left_num > right_num) {
            if (left_num < n) {
                s = s + '(';
                trace(left_num+1, right_num, n);
                s = s.substr(0, s.size()-1);
                s = s + ')';
                trace(left_num, right_num+1, n);
                s = s.substr(0, s.size()-1);
            }
            else if (left_num == n) {
                s = s + ')';
                trace(left_num, right_num+1, n);
                s = s.substr(0, s.size()-1);
            }
        }
        else if (left_num == right_num) {
            s = s + '(';
            trace(left_num+1, right_num, n);
            s = s.substr(0, s.size()-1);
        }
    }

    vector<string> generateParenthesis(int n) {
        if (n == 0) return ans;
        if (n == 1) {
            ans.push_back("()");
            return ans;
        }
        trace(0, 0, n);
        return ans;
    }
};
