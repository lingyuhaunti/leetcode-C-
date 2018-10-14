#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int num = 0;
        sort(nums.begin(), nums.end());
        permuteUnique(nums, 0);
        /*for (int i=0; i<res.size(); ++i) {
            for (int j=i+1; j<res.size(); ++j) {
                int ss = 0;
                for (int k=0; k<res[j].size(); ++k) {
                    if (res[i][k] == res[j][k]) {
                        ++ss;
                    } else {
                        //ss = 0;
                    }
                }
                //cout << res[i].size() << endl;
                if (ss == res[i].size()) {
                    ++num;
                }
            }
        }
        cout << num << " " << res.size() << endl;*/
        for (auto& ans : resset) {
            res.emplace_back(ans);
        }
        return res;
    }

    void permuteUnique(vector<int>& nums, int start) {
        if (start == nums.size()-1) {
            //res.emplace_back(nums);
            resset.insert(nums);
            return ;
        }
        for (int i=start; i<nums.size(); ++i) {
            if (i>start && (nums[i]==nums[i-1] || nums[start]==nums[i])) {
                continue;
            }
            swap(nums[i], nums[start]);
            permuteUnique(nums, start+1);
            swap(nums[i], nums[start]);
        }
    }

private:
    vector<vector<int> > res;
    set<vector<int> > resset;
};

int main()
{
    return 0;
}
