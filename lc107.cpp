#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> qTreeNode;
        vector<vector<int> > res;
        vector<int> res1;
        if(root){
            qTreeNode.push(root);
        }

        TreeNode* lastNode = root;
        TreeNode* last;

        while(!qTreeNode.empty()){
            TreeNode* cur;
            cur = qTreeNode.front();

            res1.push_back(cur->val);

            if(cur->left != NULL){
                qTreeNode.push(cur->left);
                last = cur->left;
            }
            if(cur->right != NULL){
                qTreeNode.push(cur->right);
                last = cur->right;
            }

            if(cur == lastNode){
                lastNode = last;
                res.push_back(res1);
                res1.clear();
            }
            qTreeNode.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    return 0;
}
