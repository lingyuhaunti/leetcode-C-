#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        if(preorder.empty()||inorder.empty()||(preorder.size()!=inorder.size())){
            return NULL;
        }
        int prestart = 0;
        int preend = preorder.size();
        int instart = 0;
        int inend = inorder.size();

        return (buildTree(preorder, prestart, preend, inorder, instart, inend));
    }

    TreeNode* buildTree(vector<int>& pre, int prestart, int preend, vector<int>& in, int instart, int inend){
        if( prestart>=preend || instart>=inend){
            return NULL;
        }
        int rootVal = pre[prestart];
        int rootIdx = 0;

        for(int i=instart; i<inend; i++){
            if(rootVal == in[i]){
                rootIdx = i;
                break;
            }
        }

        TreeNode* root = new TreeNode(rootVal);

        int inLen = rootIdx-instart;
        root->left = buildTree(pre, prestart+1, prestart+inLen+1, in, instart, rootIdx);
        root->right = buildTree(pre, prestart+inLen+1, preend, in, rootIdx+1, inend);

        return root;
    }
};

class Solution1 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int in_idx = 0;
        int pre_idx = 0;
        TreeNode new_node = TreeNode(0);
        TreeNode* root = &new_node;

        stack<TreeNode*> bt_stk;

        while(in_idx < preorder.size())
        {
            //put on stack new tree nodes till including the point when preorder node = inorder node
            TreeNode* left_branch_head = NULL;
            TreeNode* left_branch = NULL;
            do
            {
                TreeNode* new_node = new TreeNode(preorder[pre_idx]);

                if(left_branch == NULL)
                {
                    left_branch = new_node;
                    left_branch_head = left_branch;
                }
                else
                {
                    left_branch->left = new_node;
                    left_branch = left_branch->left;
                }
                bt_stk.push(new_node);
                //cout<<"pushed "<<new_node->val<<endl;
            }
            while((preorder[pre_idx++] != inorder[in_idx]));
            //append to right of root
            root->right = left_branch_head;
            //pop off the stack till the last mathing top element with the next inorder element, last matching node will be root of next right branch
            TreeNode* last_matching_node = NULL;
            while( !bt_stk.empty())
            {
                TreeNode* top_node = bt_stk.top();
                if(top_node->val ==  inorder[in_idx])
                {
                    //cout<<"popped node "<<top_node->val<<endl;
                    bt_stk.pop();
                    in_idx++;

                    last_matching_node = top_node;
                }
                else
                {
                    break;
                }
            }
            root = last_matching_node;
        }
        return new_node.right;
    }
};

class Solution2{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 || postorder.size()==0 || (inorder.size()!=postorder.size())){
            return NULL;
        }

        int instart = 0;
        int inend = inorder.size();
        int poststart = 0;
        int postend = postorder.size();

        return buildTree(inorder, instart, inend, postorder, poststart, postend);
    }

    TreeNode* buildTree(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend){
        if(instart>=inend || poststart>=postend){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postend-1]);

        int rootIdx = 0;
        for(int i=instart; i<inend; i++){
            if(inorder[i] == postorder[postend-1]){
                rootIdx = i;
                break;
            }
        }

        int leftLen = rootIdx-instart;

        root->left = buildTree(inorder, instart, rootIdx, postorder, poststart, poststart+leftLen);
        root->right = buildTree(inorder, rootIdx+1, inend, postorder, poststart+leftLen, postend-1);

        return root;
    }
};

class Solution3{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        if(inorder.empty() || postorder.empty() || inorder.size()!=postorder.size()){
            return NULL;
        }

        TreeNode* newNode = new TreeNode(0);
        TreeNode* root = newNode;
        stack<TreeNode*> TreeStack;

        int instart = 0;
        int poststart = 0;
        int inend = inorder.size()-1;
        int postend = postorder.size()-1;

        while(inend >= 0){
            TreeNode* right_branch_head = NULL;
            TreeNode* right_branch = NULL;

            do{
                TreeNode* lnewNode = new TreeNode(postorder[postend]);
                if(right_branch_head==NULL || right_branch==NULL){
                    right_branch = lnewNode;
                    right_branch_head = right_branch;
                }
                else{
                    right_branch->right = lnewNode;
                    right_branch = right_branch->right;
                }
                TreeStack.push(lnewNode);
            }
            while(postorder[postend--] != inorder[inend]);

            root->left = right_branch_head;

            TreeNode* matching_Top = NULL;
            while(!TreeStack.empty()){
                TreeNode* TopVal= TreeStack.top();
                if(TopVal->val == inorder[inend]){
                    TreeStack.pop();
                    inend--;
                    matching_Top = TopVal;
                }
                else{
                    break;
                }
            }
            root = matching_Top;
        }

        return newNode->left;
    }
};

int main()
{
    //Solution solve;
    Solution2 solve1;
    Solution3 solve3;

    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    preorder.push_back(3);
    preorder.push_back(9);
    preorder.push_back(20);
    preorder.push_back(15);
    preorder.push_back(7);

    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(7);

    postorder.push_back(9);
    postorder.push_back(15);
    postorder.push_back(7);
    postorder.push_back(20);
    postorder.push_back(3);

    //TreeNode* root;
    TreeNode* postroot;
    TreeNode* postroot3;

    //root = solve.buildTree(preorder, inorder);
    //cout << root->right->right->val << endl;

    //postroot = solve1.buildTree(inorder, postorder);
    //cout << postroot->right->right->val <<endl;

    //postroot3 = solve3.buildTree(inorder, postorder);
    //cout << postroot3->right->right->val << endl;

    vector<int> res1;
    vector<vector<int> > res;

    res1.push_back(1);
    res.push_back(res1);
    res1.push_back(2);
    res.push_back(res1);
    res1.push_back(3);
    res.push_back(res1);
    res1.push_back(4);
    res.push_back(res1);

    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j] << "  ";
        }
        cout << endl;
    }

    reverse(res.begin(), res.end());

    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
