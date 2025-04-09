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
        ListNode* cur = head;
        ListNode* res = head;
        if(head==NULL)return NULL;
        int cnt=0;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        int k = cnt-n;
        if (k == 0) 
        {
            ListNode* toDelete = head;
            head = head->next;
            return head;
        }

        // Move cur to the node just before the one we want to delete
        k--;
        while (k-- && cur != NULL) {
            cur = cur->next;
        }

        if (cur && cur->next) {
            ListNode* toDelete = cur->next;
            cur->next = cur->next->next;
        }
        return res;
    }
};