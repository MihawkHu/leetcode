class Solution {
public:
    int romanToInt(string s) {
        int symbol[255], ans = 0;
        symbol['I'] = 1;
        symbol['V'] = 5;
        symbol['X'] = 10;
        symbol['L'] = 50;
        symbol['C'] = 100;
        symbol['D'] = 500;
        symbol['M'] = 1000;
        
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && symbol[s[i]] > symbol[s[i-1]]) {
                ans += symbol[s[i]] - 2 * symbol[s[i-1]];
            } else {
                ans += symbol[s[i]];
            }
        }
        return ans;
    }
};
