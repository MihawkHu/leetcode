class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tt;
    void find(vector<int>& candidates, int target, int pos) {
        if (target == 0) {
            ans.push_back(tt);
            return;
        }
        for (int i = pos; i < candidates.size() && candidates[i] <= target; ++i) {
            if (i != pos && candidates[i] == candidates[i-1]) continue;
            tt.push_back(candidates[i]);
            find(candidates, target-candidates[i], i+1);
            tt.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        find(candidates, target, 0);
        return ans;
    }
};
