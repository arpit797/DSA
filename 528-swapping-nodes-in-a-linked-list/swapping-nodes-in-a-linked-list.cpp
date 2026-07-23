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
    int findlength(ListNode*head){
        int l=0;
        while(head!=NULL){
            head=head->next;
            l++;
        }
        return l;
    } 
    ListNode* swapNodes(ListNode* head, int k) {
        int l=findlength(head);

        int k_1=k;
        ListNode*n1=head;
        while(k_1>1){
            n1=n1->next;
            k_1--;
        }
        int k_2=l-k+1;
        ListNode*n2=head;
        while(k_2>1){
            n2=n2->next;
            k_2--;
        }
        swap(n1->val,n2->val);
        return head;
    }
};