class Solution {
public:
    bool isNumber(string s) {
        int dot_num = 0;
        int e_num = 0;
        
        int start = 0;
        while (start < s.size() && s[start] == ' ') ++start;
        int end = s.size();
        while (end > 0 && s[end-1] == ' ') --end;
        if (end <= start) return false;
        
        for (int i = start; i < end; ++i) {
            if (s[i] == '-') {
                if (i != start && s[i-1] != 'e' || i == end-1) return false;
            }
            else if (s[i] == '+') {
                if (i != start && s[i-1] != 'e' || i == end-1) return false;
            }
            else if (s[i] == '.') {
                if (i == end-1 && i == start || dot_num > 0) return false;
                if (i != start && s[i-1] == 'e') return false;
                if (i != start && (s[i-1] == '-' || s[i-1] == '+') && i == end-1) return false;
                dot_num++;
            }
            else if (s[i] == 'e') {
                if (i == start || i == end-1 || e_num > 0) return false;
                if (i == start+1 && s[i-1] == '.') return false;
                if (i != start && (s[i-1] == '-' || s[i-1] == '+')) return false;
                e_num++;
                dot_num++;
            }
            else if (s[i] > '9' || s[i] <'0') return false;
        }
        
        return true;
    }
};
