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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)return head;

        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* prev = temp;
        ListNode* cur = temp;
        ListNode* nex = temp;

        cur = head;
        int cnt=0;
        
        while(cur!=NULL){
            cur = cur->next;
            cnt++;
        }

        while(cnt>=k){
            cur = prev->next;
            nex = cur->next;
            for(int i=1;i<k;i++){
                cur->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = cur->next;
            }
            prev=cur;
            cnt-=k;
        }
        return temp->next;
    }
};