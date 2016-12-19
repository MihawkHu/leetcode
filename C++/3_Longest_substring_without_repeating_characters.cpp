class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;
        
        map<char,bool> mp;
        int res = 1;
        int i = 0, j = 0;
        for (; j < s.length(); i++,j++) {
            for (; j < s.length(); ++j) {
                map<char, bool>::iterator iter = mp.find(s[j]);
                if (iter == mp.end()) {
                    mp.insert(pair<char, bool>(s[j], true));                    
                }
                else {
                    if (res < mp.size()) {
                        res = mp.size();
                    }
                    break;
                }
            }
            while (j < s.length() && s[i] != s[j]) {
                mp.erase(s[i]);
                i++;
            }
            
        }
        if (res < mp.size()) {
            res = mp.size();
        }
        return res;
    }
};