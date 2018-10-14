#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0, j=0, k=0;
        char point = 'a';
        int ssize = s.size();
        int psize = p.size();
        while (i < ssize && j < psize) {
            if (s[i] == p[j]) {
                ++i;
                ++j;
            } else if (p[j] == '.') {
                point = s[i];
                ++i;
                ++j;
            } else if (j && p[j] == '*') {
                if (p[j-1] == '.' || s[i] == s[i-1]) {
                    ++i;
                } else {
                    ++j;
                }
            } else {
                i = 0;
                k++;
                j = k;
            }
        }

        if (i == ssize) {
            return true;
        } else {
            return false;
        }
    }
};

class Solution1 {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() > 1 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        } else {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main()
{
    string s = "abbfdfrdsds";
    string p = ".*c";
    Solution solve;
    //cout << solve.isMatch(s,  p) << endl;
    cout << s.substr(5) << endl;
    return 0;
}
