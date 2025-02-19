/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        if (cnt == n) return head->next;

        int k = cnt-n-1;
        ListNode* prev = head;
        while(k--){
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};