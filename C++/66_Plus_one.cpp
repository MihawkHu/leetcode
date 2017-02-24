class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = true;
        for (int i = 0; i < digits.size(); ++i) {
            if (digits[i] != 9) {
                flag = false;
                break;
            }
        }
        if (flag) {
            vector<int> ans(digits.size()+1, 0);
            ans[0] = 1;
            return ans;
        }
        int c = 0;
        vector<int> ans(digits.size());
        for (int i = digits.size()-1; i >= 0; --i) {
            if (i == digits.size()-1) {
                ans[i] = digits[i] + 1;
            }
            else {
                ans[i] = digits[i] + c;
                c = 0;
            }
            if (ans[i] > 9) {
                ans[i] -= 10;
                c = 1;
            }
        }
        return ans;
    }
};
