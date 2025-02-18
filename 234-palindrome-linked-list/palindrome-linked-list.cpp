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
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        while(fast!=NULL and fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }   
        // ListNode* temp = slow;
        ListNode* prev = NULL;
        while(slow!=NULL)
        {
            ListNode* next = slow->next;
            slow->next=prev;
            prev=slow;
            slow = next;
        }
        
        ListNode* a = head;
        ListNode* b = prev;
        while(b){
            if(a->val!=b->val){
                return false;
            }
            a=a->next;
            b=b->next;
        }
        return true;
    }
};