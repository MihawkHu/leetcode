class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tt;
    void find(vector<int>& candidates, int s, int t, int target) {
        if (s >= t) return;
        if (candidates[t-1] == target) {
            tt.push_back(target);
            ans.push_back(tt);
            tt.pop_back();
        }
        for (int i = s; i < t; ++i) {
            int gg = t - 1;
            int target_new = target-candidates[i];
            if (target_new < candidates[s]) continue;
            while (candidates[gg] > target_new) --gg;
            tt.push_back(candidates[i]);
            find(candidates, s, gg+1, target_new);
            tt.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        if (target < candidates[0]) return ans;
        int gg = candidates.size() - 1;
        while (candidates[gg] > target) --gg;
        find(candidates, 0, gg+1, target);
        for (int i = 0; i < ans.size(); ++i) {
            sort(ans[i].begin(), ans[i].end());
        }
        sort(ans.begin(), ans.end());
        vector<vector<int>>::iterator iter = unique(ans.begin(), ans.end());
        ans.erase(iter, ans.end());
        return ans;
    }
};
