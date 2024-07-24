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
        if(head==NULL||head->next==NULL)
            return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *temp = head;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
            {
                while(slow!=temp)
                {
                    slow=slow->next;
                    temp = temp->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};