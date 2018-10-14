#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int mid = 0, reslen = 0, maxlen = 0;
        string str = "";
        for (char c : s) {
            str += '#';
            str += c;
        }
        str += '#';
        cout << str << endl;
        int slen = s.size();
        vector<int> nums(2*slen+1, 0);
        int maxp = 1, id = 0;
        for (int i=0; i<str.size(); ++i) {
            if (i < maxp) {
                nums[i] = min(maxp-i, nums[2*id-i]);
            } else {
                nums[i] = 1;
            }
            while (i-nums[i]>=0 && i+nums[i]<str.size() && str[i-nums[i]] == str[i+nums[i]]) {
                ++nums[i];
            }
            --nums[i];
            if (i + nums[i] > maxp) {
                maxp = i+nums[i];
                id = i;
            }
            if (nums[i] > maxlen) {
                maxlen = nums[i];
                mid = i;
            }
        }
        cout << s.substr((mid-maxlen)/2, maxlen) << endl;
        return s.substr((mid-maxlen)/2, maxlen);
    }
};

int main()
{
    Solution solve;
    string str = "babad";
    solve.longestPalindrome(str);
    return 0;
}
