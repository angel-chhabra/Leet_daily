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
    ListNode* deleteDuplicates(ListNode* head) { 
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp=head;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->val==temp->next->val){  //if duplicate found
                ListNode* del=temp->next;    //preserve krlia taki del krde ab
                temp->next=temp->next->next;  //connection removed
                delete(del);
            } else{
                temp=temp->next;     //if no duplicate
            }
        }
        return head;
        
    }
};