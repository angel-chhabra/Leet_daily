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
        ListNode* dummy=new ListNode(0);  //new node types jo hmesha head ko point kregi
        dummy->next=head;
        ListNode* temp=dummy;   //temp pointer jo abi dummy pr h but always unique ko point krega
        while(head!=nullptr && head->next!=nullptr){
            if(head->val==head->next->val){ 
                while( head->next!=nullptr && head->val==head->next->val){  //jb tk duplicate milre age chlo
                    head=head->next;
                }
                temp->next=head->next;  //jha last duplicate h vha phuchgya head , to temp head k next ko point krega to continue the ll with unique ones 
            } else{
                temp=temp->next;  //agr duplicate nhi mila to , temp next pr jayega jo unique hoga
            }
            head=head->next;
        }
        return dummy->next;  //kyuki dummy hmesha new head ko hi point krega
        
    }
};