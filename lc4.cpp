#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int numsize1 = nums1.size();
        int numsize2 = nums2.size();
        double median = 0;
        //int median2 = 0;
        vector<int> num1t = nums1;
        vector<int> num2t = nums2;
        median = findKthnum(num1t,num2t, (numsize1+numsize2)/2+1);
        if (!((numsize1 + numsize2)&0x1)){
            num1t = nums1;
            num2t = nums2;
            median += findKthnum(nums1, nums2, (numsize1+numsize2)/2);
            median = median/2;
        }
        return median;
    }

    int findKthnum (vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.size() > nums2.size()) {
            return findKthnum (nums2, nums1, k);
        }
        if (nums1.size() < 1) {
            return nums2[k-nums1.size()-1];
        }
        if (k==1) {
            return min(nums1[0], nums2[0]);
        }
        int smsize1 = nums1.size();
        smsize1 = min(k/2, smsize1); int smsize2 = k-smsize1;
        if (nums1[smsize1-1] > nums2[smsize2-1]) {
            nums2.erase(nums2.begin(), nums2.begin()+smsize2);
            return findKthnum (nums1, nums2, k-smsize2);
        } else if (nums1[smsize1-1] < nums2[smsize2-1]) {
            nums1.erase(nums1.begin(), nums1.begin()+smsize1);
            return findKthnum (nums1, nums2, k-smsize1);
        } else {
            return nums1[smsize1-1];
        }
    }
};

int main()
{
    /*int num = 0;
    vector<int> nums;

    cin >> num;
    int tmp = num;
    while (tmp) {
        nums.emplace_back(tmp%10);
        tmp /= 10;
    }

    for (int i=0; i<nums.size()/2; ++i){
        if (nums[i] != nums[nums.size()-1-i]) {
            cout << num << " is not a hui wen shu" << endl;
            return 0;
        }
    }

    int numsize = nums.size();
    if (numsize < 2) {
        cout << num << " is not a request hui wen shu" << endl;
    } else if (nums[numsize/2] == nums[numsize/2-1]) {
        cout << num << " is not a request hui wen shu" << endl;
    } else {
        cout << num << " is a request hui wen shu" << endl;
    }*/
    /*vector<int> nums;
    for (int i=0; i<9; ++i) {
        nums.emplace_back(i);
    }
    nums.erase(nums.begin(), nums.begin()+9);
    cout << nums.size() << endl;*/

    Solution solve;
    vector<int> nums1;
    vector<int> nums2;

    nums1.emplace_back(1);
    nums1.emplace_back(3);
    nums1.emplace_back(6);

    nums2.emplace_back(2);
    //nums2.emplace_back(4);
    //nums2.emplace_back(5);
    double ss;
    ss = solve.findMedianSortedArrays(nums1, nums2);
    cout << ss << endl;
    return 0;
}


