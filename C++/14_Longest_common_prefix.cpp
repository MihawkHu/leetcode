class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string("");
        int min_length = 0x7fffffff;
        for (int i = 0; i < strs.size(); ++i) {
            if (min_length > strs[i].size()) {
                min_length = strs[i].size();
            }
        }
        string ans("");
        for (int i = 0; i < min_length; ++i) {
            char a = strs[0][i];
            bool flag = true;
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[j][i] != a) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = ans + a;
            }
            else {
                break;
            }
        }
        return ans;
    }
};
