class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0, j = height.size()-1;
        while (i != j) {
            if (height[i] <= height[j]) {
                if (ans < height[i] * (j - i)) {
                    ans = height[i] * (j - i);
                }
                ++i;
            }
            else {
                if (ans < height[j] * (j - i)) {
                    ans = height[j] * (j - i);
                }
                --j;
            }
        }
        return ans;
    }
};
