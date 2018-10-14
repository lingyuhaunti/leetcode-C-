#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "123456789";
        string res = "";
        int maxnum = 1, num = n-1;
        while (num) {
            maxnum *= num;
            --num;
        }
        --k;
        for (int i=n-1; i>=0; --i) {

            int index = k/maxnum;
            res += str[index];
            cout << index << endl;
            str.erase(index);
            k = k%maxnum;

            maxnum /= (max(i, 1));
        }
        return res;
    }
};

int main()
{
    Solution solve;
    solve.getPermutation(3, 3);
    vector<int> res;
    res.empty();
    return 0;
}
