class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0) {
            if (nums2.size() % 2 == 0) {
                return ((double)(nums2[nums2.size()/2]+nums2[nums2.size()/2-1])/2);
            }
            else {
                return (double)(nums2[nums2.size()/2]);
            }
        }
        if (nums2.size() == 0) {
            if (nums1.size() % 2 == 0) {
                return ((double)(nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2);
            }
            else {
                return (double)(nums1[nums1.size()/2]);
            }
        }
        
        int i = 0, j = 0;
        while (i + j < (nums1.size()+nums2.size()) / 2) {
            if (i < nums1.size() && j < nums2.size() && nums1[i] > nums2[j] || i >= nums1.size()) {
                ++j;
            }
            else {
                ++i;
            }
        }
        bool flag1 = true, flag2 = true;
        if (i >= nums1.size()) {
            --i;
            flag1 = false;
        }
        else if (j >= nums2.size()) {
            --j;
            flag2 = false;
        }
        double res = !flag1 || !flag2 ? max(nums1[i], nums2[j]) : min(nums1[i], nums2[j]);
        if ((nums1.size()+nums2.size()) % 2 == 0) {
            double t1 = 0, t2 = 0;
            if (!flag1) t1 = nums1[i];
            else if (i >= 0 && i < nums1.size()) t1 = nums1[i-1];
            if (!flag2) t2 = nums2[j];
            else if (j > 0 && j < nums2.size()) t2 = nums2[j-1];
            res += max(t1, t2);
            res /= 2;
        }
        return res;
    }
};
