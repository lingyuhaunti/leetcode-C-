#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size()+1, 0);
        int maxarea = 0;
        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[0].size(); ++j) {
                heights[j] = matrix[i][j]-'0' ? heights[j]+matrix[i][j]-'0' : 0;
            }
            for (int j=0; j<heights.size(); ++j) {
                cout << heights[j] << " ";
            }
            cout << endl;
            //maxarea = max(maxarea, areaRectangle(heights));
        }
        return maxarea;
    }

    int areaRectangle (vector<int>& heights) {
        int maxarea = 0;
        stack<int> hstk;
        for (int i=0; i<heights.size(); ++i) {
            while(!hstk.empty() && heights[hstk.top()] >= heights[i]) {
                int cur = hstk.top(); hstk.pop();
                maxarea = max(maxarea, heights[cur]*(hstk.empty() ? i : i-hstk.top()-1));
            }
            hstk.push(i);
        }
        return maxarea;
    }
};

int main()
{
    Solution solve;
    vector<vector<char> > matrix;
    solve.maximalRectangle(matrix);
    return 0;
}

/*
'1','0','1','0','0'
'1','0','1','1','1'
'1','1','1','1','1'
'1','0','0','1','0'
*/
