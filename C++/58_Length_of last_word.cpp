class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int i = s.size()-1;
        while (s[i] == ' ') --i;
        for (; i >= 0; --i) {
            if (s[i] != ' ') ++ans;
            else break;
        }
        return ans;
    }
};
