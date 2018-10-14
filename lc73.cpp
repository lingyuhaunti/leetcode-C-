#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> colSet;
        if(!matrix.empty()){
            return ;
        }
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i<row; i++){
            bool flag = 0;
            for(int j=0; j<col; j++){
                if(!matrix[i][j]){
                    colSet.insert(j);
                    flag = 1;
                }

                if(colSet.count(j)){
                    matrix[i][j] = 0;
                }
            }
            if(flag){
                vector<int> v(col, 0);
                matrix[i] = v;
            }
        }
    }
};

int main()
{
    Solution solve;
    vector<vector<int> > TreeV;
    vector<int> TreeV1(3, 1);
    vector<int> TreeV3(3, 1);
    vector<int> TreeV2;
    TreeV2.push_back(1);
    TreeV2.push_back(0);
    TreeV2.push_back(1);
    TreeV.push_back(TreeV1);
    TreeV.push_back(TreeV2);
    TreeV.push_back(TreeV3);
    solve.setZeroes(TreeV);
    return 0;
}
