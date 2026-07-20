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
    int sizeList(ListNode* head){
        int c =0;
        ListNode* temp =head;
        while(temp != NULL){
            c++;
            temp = temp->next;
        }
        return c;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = sizeList(head);
        if(size == n) return head->next;
        ListNode* temp =  head;
        for(int i =1;i<size-n;i++){
            temp = temp->next;
        }
        temp->next =temp->next->next;
        return head;
    }
};