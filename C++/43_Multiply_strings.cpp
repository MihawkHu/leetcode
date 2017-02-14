class Solution {
public:
    string add(string num1, string num2) {
        string ans;
        int i = num1.size()-1, j = num2.size()-1, c = 0;
        while (i >= 0 && j >= 0) {
            int n1 = (int)(num1[i]-'0');
            int n2 = (int)(num2[j]-'0');
            int tt = n1 + n2 + c;
            if (tt >= 10) {
                c = 1; 
                tt = tt - 10;
            }
            else {
                c = 0;
            }
            ans = string(1, (char)(tt+'0')) + ans;
            --i;  --j;
        }
        if (i < 0 && j >= 0) {
            while (j >= 0) {
                int n2 = (int)(num2[j]-'0');
                int tt = n2 + c;
                if (tt >= 10) {
                    c = 1;
                    tt = tt - 10;
                }
                else {
                    c = 0;
                }
                ans = string(1, (char)(tt+'0'))+ans;
                --j;
            }
        }
        else if (i >= 0 && j <0) {
            while (i >= 0) {
                int n1 = (int)(num1[i]-'0');
                int tt = n1 + c;
                if (tt >= 10) {
                    c = 1;
                    tt = tt - 10;
                }
                else {
                    c = 0;
                }
                ans = string(1, (char)(tt+'0'))+ans;
                --i;
            }
        }
        if (c > 0) {
            ans = string(1, (char)(c+'0')) + ans;
        }
        return ans;
    }
    string mul(string num1, char num2) {
        if (num2 == '0') return string(1, '0');
        int n2 = (int)(num2-'0');
        int c = 0;
        string ans;
        for (int i = num1.size()-1; i >= 0; --i) {
            int tt = (int)(num1[i]-'0');
            tt = tt * n2 + c;
            if (tt >= 10) {
                c = tt / 10;
                tt = tt % 10;
            }
            else {
                c = 0;
            }
            ans = string(1, (char)(tt+'0')) + ans;
        }
        if (c > 0) {
            ans = string(1, (char)(c+'0')) + ans;
        }
        return ans;
    }
    string mul10(string num1) {
        if (num1.size() == 1 && num1[0] == '0') return num1;
        return num1 + string(1, '0');
    }
    string multiply(string num1, string num2) {
        string ans;
        if (num1.size() > num2.size()) {
            for (int j = num2.size()-1; j >= 0; --j) {
                char n2 = num2[j];
                string s = mul(num1, n2);
                for (int r = j; r < num2.size()-1; ++r) {
                    s = mul10(s);
                }
                ans = add(ans, s);
            }
        }
        else {
            for (int i = num1.size()-1; i >= 0; --i) {
                char n1 = num1[i];
                string s = mul(num2, n1);
                for (int r = i; r < num1.size()-1; ++r) {
                    s = mul10(s);
                }
                ans = add(ans, s);
            }
        }
        return ans;
    }
};
