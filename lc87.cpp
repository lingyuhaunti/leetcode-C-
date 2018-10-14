#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        if (nums[left] >= nums[right]) {
            while (left < right-1) {
                int mid = left+(right-left)/2;
                if (nums[left] > nums[mid]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            return min(left, right);
        }
        return nums[0];
    }
};

int main()
{
    string str1 = "adfead";
    string str2 = "dfeidj";
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    cout << str1 << endl;
    cout << str2 << endl;
    return 0;
}
