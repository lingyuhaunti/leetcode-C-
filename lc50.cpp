#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0, tmp = 1.0;
        if (x == 0 || x==1) {
            return x;
        }

        for (int i=n; i!=0; i/=2) {
            if (i%2) {
                res *= x;
            }
            x *= x;
            if ((n>0 && !x) || (n<0 && tmp/res==0)) {
                return 0;
            }
        }
        return n<0 ? 1/res:res;
    }
};

int main()
{
    Solution solve;
    cout << solve.myPow(2.00000, -2147483648) << endl;
    return 0;
}
