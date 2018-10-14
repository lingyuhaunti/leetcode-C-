#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int last1 = num1.size(), last2 = num2.size();
        string res(last1+last2, '0');
        int jw = 0;

        for (int i=last1-1; i>=0; --i) {
            int j=0;
            for (j=last2-1; j>=0; --j) {
                int mul = (num1[i]-'0')*(num2[j]-'0')+jw+res[i+j+1]-'0';
                res[i+j+1] = mul%10+'0';
                //cout << i << " " << j << " " << mul << endl;
                jw = mul/10;
            }
            res[i+j+1] += jw;
            jw = 0;
        }
        int i=0;
        while (res[i] == '0') {
            ++i;
        }
        cout << res << endl;
        return res;
    }
};

int main()
{
    string str1 = "999";
    string str2 = "999";
    Solution solve;
    solve.multiply(str1, str2);
    return 0;
}
