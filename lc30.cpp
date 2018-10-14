#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size() < 1 || (s.size() < words.size()*words[0].size())) {
            return res;
        }
        unordered_map<string, int> wordmap1;
        for (auto& ans : words) {
            ++wordmap1[ans];
        }
        int listsize = words.size();
        int wordsize = words[0].size();
        for (int i=0; i<=s.size()-listsize*wordsize; ++i) {
            unordered_map<string, int> wordmap2;
            cout << i << endl;
            for (int j=0;  j<listsize; ++j) {
                string tmp = s.substr(i+j*wordsize, wordsize);
                if (wordmap1[tmp] && wordmap1[tmp] > wordmap2[tmp]) {
                    ++wordmap2[tmp];
                    cout << j << " " << listsize << endl;
                    if ((j+1) == listsize) {
                        res.emplace_back(i);
                    }
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    string str1 = "wordgoodgoodgoodbestword";
    vector<string> strvec = {"word","good","best","good"};
    Solution solve;
    solve.findSubstring(str1, strvec);
    return 0;
}
