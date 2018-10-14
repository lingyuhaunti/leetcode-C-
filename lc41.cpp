#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(!nums.size()){
            return 1;
        }

        for(int i=0; i<nums.size();){
            if(nums[i]!=i+1 && nums[i]<nums.size() && nums[i]>0){
                swap(nums[i], nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }

        for(int i=0; i<nums.size(); i++){
            cout << nums[i] << endl;
        }

        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=(i+1)){
                res = i+1;
                break;
            }
            if(i == nums.size()-1){
                res = i+2;
            }
        }
        cout << res << endl;
        return res;
    }
};

int main()
{
    vector<int> pov;//[-1,4,2,1,9,10]
    pov.push_back(-1);
    pov.push_back(4);
    pov.push_back(2);
    pov.push_back(1);
    pov.push_back(9);
    pov.push_back(10);

    Solution solve;

    solve.firstMissingPositive(pov);

    return 0;
}
