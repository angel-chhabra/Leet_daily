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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode(0);
        ListNode* ans=res;
        int carry=0;
        int val1=0;
        int val2=0;
        while(l1!=nullptr || l2!=nullptr || carry!=0){   //jb tk koi si b list khtm n hoti
            int val1=0;
            int val2=0;
            if(l1!=nullptr){   //agr h node to val leo , sum m dalo and next pr chlo
                val1=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){  //same as case of l1
                val2=l2->val;
                l2=l2->next;
            }
            int sum= val1 + val2+ carry;
            carry=sum/10;   //carry define hojega isse
            sum=sum%10;     // sum zyda hoga to vo b thk hojega 
            ans->next= new ListNode(sum); //ans m dlta jayega new sum hmesha new node ki trh
            ans=ans->next;
        }
        return res->next;  //new head
    }
};