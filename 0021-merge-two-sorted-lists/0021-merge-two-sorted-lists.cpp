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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode * result=new ListNode(-1);
        ListNode*temp=result;  //result ka head preserve hogya 
      while(l1!=NULL && l2!=NULL){
        if(l1->val<l2->val){  //jiski b value choti hogi , uske lie new node bnajayegi and result m add hojegi
            temp->next=new ListNode(l1->val);
            l1=l1->next;  //next hojayega fr uska b and temp ka b
            temp=temp->next;
        } else{
            temp->next=new ListNode(l2->val);
            l2=l2->next;
            temp=temp->next;
        }
      }
        if(l1!=NULL){   //agr kuch bch jyega to use b add krna pdega
            temp->next=l1;
        } if(l2!=NULL){
            temp->next=l2;
        }
        return result->next;   //bcoz starting m to -1 h and uske bad se list start h
    }
};