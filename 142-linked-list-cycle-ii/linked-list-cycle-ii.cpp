/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                while(slow!=head)
                {
                    slow=slow->next;
                    head = head->next;
                }
                return head;
            }
        }
        return NULL;
    }
};