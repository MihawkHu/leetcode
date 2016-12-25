class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= numRows || numRows == 1) return s;
        string s1(s.size(), '\0');
        int cnt = 0;
        for (int j = 0; j < numRows; ++j) {
            if (j != 0 && j != numRows - 1) {
                int i = 0;
                while (1) {
                    if (i * (2 * numRows - 2) + j < s1.size()) {
                        s1[cnt++] = s[i * (2 * numRows - 2) + j];
                    } 
                    else {
                        break;
                    }
                    if ((i + 1) * (2 * numRows - 2) - j < s1.size()) {
                        s1[cnt++] = s[(i + 1) * (2 * numRows - 2) - j];
                    }
                    else {
                        break;
                    }
                    ++i;
                }
            }
            else {
                int i = 0;
                while (i * (2 * numRows - 2) + j < s1.size()) {
                    s1[cnt++] = s[i * (2 * numRows - 2) + j];
                    ++i;
                }
            }
        }
        return s1;
    }
};