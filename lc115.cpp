#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();

        vector<int> dp(s_size+1, 1);

        for(int i=0; i<t_size; i++){

            int pre = dp[i];
            dp[i] = 0;

            for(int i=0; i<s_size+1; i++){
                cout << dp[i] << "  ";
            }
            cout << endl;

            for(int j=i; j<s_size; j++){
                int temp = dp[j+1];
                if(t[i] == s[j]){
                    dp[j+1] = pre+dp[j];
                }
                else{
                    dp[j+1] = dp[j];
                }
                pre = temp;
            }
        }

        return dp[s_size];
    }
};

int main()
{
    vector<int> v(4, 1);
    for(int i=0; i<4; i++){
        cout << v[i] << endl;
    }
    queue<int> q1;
    string s = "rabbbit";
    string t = "rabbit";
    Solution solve;
    solve.numDistinct(s, t);
    return 0;
}
