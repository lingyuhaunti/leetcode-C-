#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor) {
            return -1;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        int res=0;
        long long dividend1 = abs((long long)dividend), divisor1 = abs((long long)divisor);
        int sign = -1;
        if ((dividend1<0&&divisor1<0) || (dividend1>0&&divisor>0)) {
            sign = 1;
        }
        cout << dividend1 << " " << divisor1 << endl;
        while (dividend1 >= divisor1) {
            long long tmp = divisor1, tmpres=1;
            while (dividend1 >= (tmp<<1)) {
                tmp <<= 1;
                tmpres <<= 1;
            }
            res += tmpres;
            dividend1-=tmp;
        }
        return sign*res;
    }
};

int main()
{
    Solution solve;
    int dividend = 10, divisor = -3;
    //solve.divide(dividend, divisor);
    string str(12, '.');
    cout << str << endl;
    return 0;
}
