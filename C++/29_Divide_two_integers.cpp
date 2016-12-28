class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return 0x7fffffff;
        long long a = dividend, b = divisor, ans = 0, tt = 1;
        if (abs(a) < abs(b)) return 0;
        
        bool f1 = false, f2 = false;
        if (a < 0) {
            f1 = true;
            a = -a;
        }
        if (b < 0) {
            f2 = true;
            b = -b;
        }
        
        while (a > b) {
            b = b << 1;
            tt = tt << 1;
        }
        while (a >= abs((long long)divisor)) {
            if (a >= b) {
                a -= b;
                ans += tt;
            }
            b = b >> 1;
            tt = tt >> 1;
        }
        
        if (!f1 && f2 || f1 && !f2) {
            ans = -ans;
        }
        if (ans > (int)0x7fffffff || ans < (int)0x80000000) return 0x7fffffff;
        return ans;
    }
};
