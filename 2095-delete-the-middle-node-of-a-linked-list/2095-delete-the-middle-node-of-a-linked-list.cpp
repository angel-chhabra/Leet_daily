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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return NULL;
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=NULL;
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;   //slow ko preserve krne ke lie store krana pdega 
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=slow->next;  //directly next node se connection bna lia and slow ko nikal dia bich m se
        delete(slow);
        return head;
    }
};