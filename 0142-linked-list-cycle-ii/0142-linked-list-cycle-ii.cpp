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
        if(head==NULL ||head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){   //means cycle detect hogyi
                slow=head;    //slow ko head pr bhejdiya 
                while(slow!=fast){
                    slow=slow->next;  //ek ek krke chlaya , jha p b meet honge vhi cycle ka start hoga (its an algoo)
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
        
    }
};