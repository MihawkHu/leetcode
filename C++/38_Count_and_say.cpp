class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        for (int p = 0; p < n-1; ++p) {
            int cnt = 1;
            string s1("");
            for (int i = 0; i < s.size(); ++i) {
                if (i+1 < s.size() && s[i+1] == s[i]) {
                    cnt++;
                }
                else {
                    s1 = s1 + char(cnt+'0') + s[i];
                    cnt = 1;
                }
            }
            s = s1;
        }
        return s;
    }
};
