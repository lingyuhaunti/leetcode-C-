#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


 //Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> qTree;
        if(root){
            qTree.push(root);
        }

        TreeLinkNode* cur = root;

        int len = 0;
        while(!qTree.empty()){
            len = qTree.size();

            for(int i=0; i<len; i++){
                cur = qTree.front();
                qTree.pop();

                if(cur->left){
                    qTree.push(cur->left);
                }
                if(cur->right){
                    qTree.push(cur->right);
                }

                if(i == (len-1)){
                    cur->next = NULL;
                }
                else{
                    cur->next = qTree.front();
                }
            }
        }
    }
};

/*
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution1 {
public:
    // void connect(TreeLinkNode *root) {
    //     if (root==NULL) return;
    //     queue<TreeLinkNode*> qu;
    //     qu.push(root);
    //     TreeLinkNode *cur;
    //     while(qu.size()>0){
    //         int len=qu.size();
    //         for(int i=0;i<len;i++){
    //             cur=qu.front(); qu.pop();
    //             if(cur->left) qu.push(cur->left);
    //             if(cur->right) qu.push(cur->right);
    //             if (i<len-1)
    //                 cur->next=qu.front();
    //             else
    //                 cur->next=NULL;
    //         }
    //     }
    // }
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        if(root->left)
            root->left->next=root->right;
        if(root->right)
            root->right->next=root->next?root->next->left:NULL;
        connect(root->left);
        connect(root->right);
    }
};

int main()
{
    Solution solve;
    TreeLinkNode* root = new TreeLinkNode(1);

    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);

    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);

    cout << root->left->val << endl;
    if(root->left->next == NULL){
        cout << "NULL" << endl;
    }

    solve.connect(root);

    cout << root->left->next->val << endl;
    if(root->right->next == NULL){
        cout << "NULL1" << endl;
    }

    return 0;
}
