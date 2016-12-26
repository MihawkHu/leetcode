class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) return 0;
        int i = 0;
        long long ans = 0;
        while (i < str.size() && str[i] == ' ') {
            ++i;
        }
        bool flag = true;
        if (i < str.size() && str[i] == '-') {
            flag = false;
            ++i;
        }
        else if (i < str.size() && str[i] == '+') {
            ++i;
        }
        if (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
                ans = ans * 10 + int(str[i] - '0');
                if (ans > (int)0x7fffffff || ans < (int)0x80000000) {
                    if (flag) {
                        return (int)0x7fffffff;
                    }
                    else {
                        return (int)0x80000000;
                    }
                }
                ++i;
            }
        }
        else {
            return 0;
        }
        if (!flag) {
            ans = -ans;
        }
        return ans;
    }
};
