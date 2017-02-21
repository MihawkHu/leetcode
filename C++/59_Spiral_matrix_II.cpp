class Solution {
public:
    void zyj(vector<vector<int>>& matrix, int n, int x, int y, int k, int s) {
        if (2*k > n) return;
        if (2*k+1 == n) {
            matrix[x][y] = ++s;
            return;
        }
        
        for (int i = 0; i < n-2*k; ++i) {
            matrix[x][y+i] = ++s;
        }
        for (int i = 0; i < n-2*(k+1); ++i) {
            matrix[x+i+1][y+n-2*k-1] = ++s;
        }
        for (int i = 0; i < n-2*k; ++i) {
            matrix[x+n-2*k-1][y+n-2*k-1-i] = ++s;
        }
        for (int i = 0; i < n-2*(k+1); ++i) {
            matrix[x+n-2*(k+1)-i][y] = ++s;
        }
        
        zyj(matrix, n, x+1, y+1, k+1, s);
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int s = 0;
        zyj(ans, n, 0, 0, 0, s);
        return ans;
    }
};
