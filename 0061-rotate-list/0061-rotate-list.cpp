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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        ListNode* temp=head;  
        int size=1;   //to include head
        while(temp->next!=NULL){   //to calculate size of list
            temp=temp->next;
            size++;
        }
        temp->next=head; //to make the ll cyclic
        k=k%size;   //if k is too bigger
        int tail_=size-k;
        ListNode* tail=head;   //tail tak jane ke lie pointer (size-k par hoga hmare rotated ll ka tail and usse just next hoga uska head , to hm tail->next null krdnge and usse newhead age chlajega n cyclic b tut jayega)
        for(int i=1;i<tail_;i++){ 
            tail=tail->next;
        }
        ListNode* newHead=tail->next;  
        tail->next=NULL;

        return newHead;
    }
};