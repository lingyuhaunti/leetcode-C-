#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, vector<string>> resmap;
        for (string str : strs) {
            vector<int> numcs(26, 0);
            for (char c : str) {
                ++numcs[c-'a'];
            }
            string strkey = "";
            for (int i=0; i<numcs.size(); ++i) {
                strkey.append(numcs[i], ('a'+i));
            }
        }
        return res;
    }
};

int main()
{
    string str = "asd";
    str.append(6, 'a'+1);
    cout << str << endl;
    cout << pow(0.0000001, 25468912) << endl;
    return 0;
}
