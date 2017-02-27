class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int temp_length = 0;
        
        vector<string> temp;
        for (int i = 0; i < words.size(); ++i) {
            if (temp_length == 0) {
            }
            else {
                if (temp_length+temp.size()+words[i].size() <= maxWidth) {
                }
                else {
                    int space_num = maxWidth - temp_length;
                    int words_num = temp.size();
                    if (words_num == 1) {
                        string tt = temp[0] + string(space_num, ' ');
                        ans.push_back(tt);
                    }
                    else {
                        int space_per_word = space_num / (words_num - 1);
                        int res_space = space_num % (words_num - 1);
                        string tt = temp[0];
                        for (int j = 1; j < temp.size(); ++j) {
                            if (j <= res_space) {
                                tt = tt + string(space_per_word+1, ' ');
                            }
                            else {
                                tt = tt + string(space_per_word, ' ');
                            }
                            tt = tt + temp[j];
                        }
                        ans.push_back(tt);
                    }
                    temp_length = 0;
                    temp.clear();
                }
            }
            temp_length += words[i].size();
            temp.push_back(words[i]);
        }
        if (temp.size() > 0) {
            string tt = temp[0];
            for (int i = 1; i < temp.size(); ++i) {
                tt = tt + string(" ");
                tt = tt + temp[i];
            }
            tt = tt + string(maxWidth-temp_length-temp.size()+1, ' ');
            ans.push_back(tt);
        }
        
        return ans;
    }
};
