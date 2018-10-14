#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.size() < 1 || matrix[0].size() < 1 || matrix[0][0] > target || matrix[matrix.size()-1][matrix[0].size()-1] < target) {
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int send = row*col-1;
        int length = (send-start)/2;

        while (start < send) {
            int middle = start+length;
            if (matrix[middle/col][middle%col] == target) {
                return true;
            } else if (matrix[middle/col][middle%col] < target){
                start = middle+1;
            } else {
                send = middle;
            }
            length = length/2 ? length/2:1;
            cout << start << " " << send << endl;
        }
        if (matrix[start/col][start%col] == target) {
            return true;
        }
        return false;
    }
};

int main()
{
    vector<vector<int> > nums = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    int target = 13;

    Solution solve;

    solve.searchMatrix(nums, target);

    /*for (int i=0; i<nums.size(); ++i) {
        for (int j=0; j<nums[i].size(); ++j) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }*/

    return 0;
}

/*
[[1,3,5,7],[10,11,16,20],[23,30,34,50]]
13
*/
