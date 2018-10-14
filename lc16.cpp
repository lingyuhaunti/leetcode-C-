#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) {return 0;}
        sort(nums.begin(), nums.end());
        int res = 0, mindit = INT_MAX;
        for (int i=0; i<nums.size()-2; ++i) {
            if (i && nums[i] == nums[i-1]) {
                continue;
            }
            int targets = target-nums[i];
            int j = i+1, k = nums.size()-1;
            while (j < k) {
                if (nums[j]+nums[k] == targets) {
                    return target;
                } else if (nums[j]+nums[k] < targets){
                    if (mindit > targets-nums[j]-nums[k]) {
                        mindit = targets-nums[j]-nums[k];
                        res = nums[i]+nums[j]+nums[k];
                    }
                    ++j;
                } else {
                    if (mindit > nums[j]+nums[k]-targets) {
                        mindit = nums[j]+nums[k]-targets;
                        res = nums[i]+nums[j]+nums[k];

                    }
                    --k;
                }
            }
        }
        cout << res << endl;
        return res;
    }
};

int main()
{
    vector<int> nums = {1,1,0,1};
    int target = -100;
    Solution solve;
    solve.threeSumClosest(nums, target);
    return 0;
}
