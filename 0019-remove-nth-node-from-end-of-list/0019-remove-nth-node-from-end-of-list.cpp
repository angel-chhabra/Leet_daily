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
        if(head==NULL || head->next==NULL) return NULL;
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;   //puri ll ka total size nikala
            count++;
        }
        if(count==n){
            return head->next;
        }
        ListNode*temp1=head;
        for(int i=1;i<count-n;i++){   //jb tk hm count-n  wali node tak nhi phuch jate
            temp1=temp1->next;
        }
        temp1->next=temp1->next->next;  
        return head;
    }
};