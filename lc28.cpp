#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*if (nums.size() < 1) {
            cout << nums.size() << endl;

            return 0;
        }*/
        int i=0;
        for (int j=1; j<nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

int main()
{
    /*vector<int> nums(9, 0);
    int i=0;
    nums[i=0] = -1;
    for (int num : nums) {
        cout << num << endl;
    }
    stack<int> stk;
    stk.empty();*/
    vector<int> nums;
    Solution solve;
    solve.removeDuplicates(nums);
    return 0;
}
