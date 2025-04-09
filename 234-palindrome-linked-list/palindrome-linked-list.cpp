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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)return 1;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=NULL and fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = NULL;
        ListNode* cur = slow->next;
        while(cur!=NULL){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        ListNode* a = prev;
        ListNode* b = head;
        while(a!=NULL){
            if(a->val!=b->val)return false;
            a=a->next;
            b=b->next;
            
        }
        return true;
    }
};