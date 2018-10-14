#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m==n) {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *start = dummy;
        ListNode *cur = head, *pre = head;
        int pcur = 1;

        while (cur) {
            ListNode *tmp = cur->next;
            if (pcur < m) {
                start = start->next;
            } else {
                if (pcur>m && pcur<=n) {
                    cur->next = pre;
                    if (pcur == n) {
                        start->next->next = tmp;
                        start->next = cur;
                    }
                }
            }
            pre = cur;
            cur = tmp;
            ++pcur;
        }
        return dummy->next;
    }
};

int main()
{
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    for (int i=1; i<6; ++i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    Solution solve;
    solve.reverseBetween(dummy->next, 2, 4);
    return 0;
}
