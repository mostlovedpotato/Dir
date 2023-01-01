#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ch_to_word;
        unordered_map<string, char> word_to_ch;
        s.push_back(' ');
        string curr_word = "";
        int ch_ind = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                char curr_ch = pattern[ch_ind++];
                if (ch_to_word.count(curr_ch)) {
                    string already_mapped_word = ch_to_word[curr_ch];
                    if (already_mapped_word != curr_word) return false;
                }
                else if (word_to_ch.count(curr_word)) {
                    char already_mapped_char = word_to_ch[curr_word];
                    if (already_mapped_char != curr_ch) return false;
                }
                else {
                    ch_to_word[curr_ch] = curr_word;
                    word_to_ch[curr_word] = curr_ch;
                }
                curr_word = "";
            }
            else {
                curr_word.push_back(s[i]);
            }

        }
        return ch_ind == pattern.size();
    }
};