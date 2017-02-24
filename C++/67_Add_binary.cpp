class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() == 0) return b;
        if (b.size() == 0) return a;
        string ans;
        
        if (a.size() > b.size()) {
            swap(a, b);
        }
        
        int c = 0;
        int i = 0;
        string tt(1,' ');
        for (; i < a.size(); ++i) {
            tt[0] = a[a.size()-i-1] + b[b.size()-i-1] -'0' + c;
            c = 0;
            if (tt[0] > '1') {
                tt[0] = tt[0] - 2;
                c = 1;
            }
            ans = string(tt) + ans;
        }
        for (; i  < b.size(); ++i) {
            tt[0] = b[b.size()-i-1] + c;
            c = 0;
            if (tt[0] > '1') {
                tt[0] = tt[0] - 2;
                c = 1;
            }
            ans = string(tt) + ans;
        }
        if (c > 0) ans = string("1") + ans;
        
        return ans;
    }
};
