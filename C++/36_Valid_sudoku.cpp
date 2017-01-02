class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        int flag[27][9];
        memset(flag, 0, sizeof(flag));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = (int)(board[i][j] - '0');
                if (flag[i][num] == 1) return false;
                else flag[i][num] = 1;
                if (flag[j+9][num] == 1) return false;
                else flag[j+9][num] = 1;
                if (flag[(i/3)*3+(j/3)+18][num] == 1) return false;
                else flag[(i/3)*3+(j/3)+18][num] = 1;
            }
        }
        return true;
    }
};
