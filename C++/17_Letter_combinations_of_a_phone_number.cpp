class Solution {
public:
    vector<string> ans;
    string s;
    map<char, string> table;
    void init() {
        table['2'] = "abc";
        table['3'] = "def";
        table['4'] = "ghi";
        table['5'] = "jkl";
        table['6'] = "mno";
        table['7'] = "pqrs";
        table['8'] = "tuv";
        table['9'] = "wxyz";
        table['0'] = " ";
    }
    void trace(string digits, int i) {
        if (i == digits.size()) {
            ans.push_back(s);
            return;
        }
        for (int k = 0; k < table[digits[i]].size(); ++k) {
            s = s + table[digits[i]][k];
            trace(digits, i+1);
            s = s.substr(0, s.size()-1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ans;
        init();
        trace(digits, 0);
        return ans;
    }
};
