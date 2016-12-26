class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        long long length = 1;
        long long tt = x;
        while (tt / (long long)pow(10, length) != 0) {
            length++;
        }
        for (int i = 0; i < length / 2; ++i) {
            int a = tt % 10;
            int temp1 = tt / (long long)(pow(10, length-2*i-1));
            int temp2 = tt / (long long)(pow(10, length-2*i));
            int b = temp1 - temp2 * 10;
            if (a != b) return false;
            tt = tt / 10;
        }
        return true;
    }
};
