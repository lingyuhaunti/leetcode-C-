#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector <string> matrix(numRows, "");
        int i=0;
        bool flag = 0;
        for (char c : s) {
            matrix[i] += c;
            if (i == 0 || i == numRows-1) {
                flag = !flag;
            }
            i += (flag ? 1:-1);
        }
        string str = "";
        for (string stmp : matrix) {
            str += stmp;
        }
        return str;
    }
};

int main()
{
    Solution solve;
    string str = "AB";
    //solve.convert(str, 4);
    vector<int> nums;
    cout << nums.size() << endl;
    sort(nums.begin(), nums.end());
    return 0;
}
