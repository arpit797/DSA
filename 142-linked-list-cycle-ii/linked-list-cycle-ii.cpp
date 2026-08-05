class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        bool hasCycle=false;

        // pahle cycle detect karo (Floyd's algorithm)
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                hasCycle=true;
                break;
            }
        }

        if(!hasCycle) return NULL;

        // ab cycle ka starting point dhoondo
        ListNode*p=head;
        while(p!=slow){
            p=p->next;
            slow=slow->next;
        }
        return p;
    }
};