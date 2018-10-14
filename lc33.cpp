#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 1) {
            return -1;
        }
        int res = -1;
        int left = 0, right = nums.size()-1;

        while (left < right) {
            int mid = left+(right-left)/2;
            if (nums[mid] == target) {
                res = mid;
                break;
            }
            if (nums[left] < nums[mid]) {
                if (nums[left]<=target && nums[mid]>target) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else if (nums[mid] < nums[right]) {
                if (nums[right]>=target && nums[mid]<target) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        if (nums[left] == target) {
            res = left;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {0, 1, 2, 4, 5, 6, 7};
    int target = 3;
    Solution solve;
    solve.search(nums, target);
    return 0;
}
