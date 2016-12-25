class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while (x != 0) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if (ans > (int)0x7fffffff || ans < (int)0x80000000) return 0;
        return ans;
    }
};