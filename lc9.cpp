#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return 0;
        }
        int tmp = x;
        int x1 = 0;
        while(tmp){
            if((INT_MAX/10)<x1 || (INT_MIN/10)>x1){
                return 0;
            }
            x1 = x1*10 + tmp%10;
            tmp /= 10;
        }

        if(x == x1){
            return 1;
        }

        return 0;
    }
};

int main()
{
    //cout << INT_MAX << endl;
    //cout << INT_MIN << endl;
    //cout << 2147483647+10 << endl;
    vector<char> word = {'A', 'C', 'G', 'T'};
    //cout << word[1] << endl;
    //string s = "3 3\nsssssssssd";
    string str = "\n";

    cin >> str;
    cout << str << endl;
    return 0;
}
