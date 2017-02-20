class Solution {
public:
    void zyj(vector<vector<int>>& matrix, vector<int>& ans, int x, int y, int k) {
        if (2*k == matrix.size() || 2*k == matrix[0].size()) return;
        if (2*k+1 == matrix.size()) {
            for (int i = 0; i < matrix[0].size() - 2*k; ++i) {
                ans.push_back(matrix[x][y+i]);
            }
            return;
        }
        if (2*k+1 == matrix[0].size()) {
            for (int i = 0; i < matrix.size() - 2*k; ++i) {
                ans.push_back(matrix[x+i][y]);
            }
            return;
        }
        
        for (int i = 0; i < matrix[0].size() - 2*k; ++i) {
            ans.push_back(matrix[x][y+i]);
        }
        for (int i = 0; i < matrix.size() - 2*(k+1); ++i) {
            ans.push_back(matrix[x+i+1][y+matrix[0].size()-2*k-1]);
        }
        for (int i = 0; i < matrix[0].size() - 2*k; ++i) {
            ans.push_back(matrix[x+matrix.size()-2*k-1][y+matrix[0].size()-2*k-1-i]);
        }
        for (int i = 0; i < matrix.size() - 2*(k+1); ++i) {
            ans.push_back(matrix[x+matrix.size()-2*(k+1)-i][y]);
        }
        
        zyj(matrix, ans, x+1, y+1, k+1);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        zyj(matrix, ans, 0, 0, 0);
        return ans;
    }
};
