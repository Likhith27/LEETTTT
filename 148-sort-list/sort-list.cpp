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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        if(!head||!head->next)return head;
        vector<int>v;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(),v.end());
        int k = v.size();
        ListNode* t = new ListNode(v[0]);
        ListNode* p=t;
        for(int i=1;i<k;i++){
            p->next =  new ListNode(v[i]);
            p = p->next;
        }
        return t;
    }
};