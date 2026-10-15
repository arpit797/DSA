class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = new ListNode();
        temp->next = head;
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->next->val < curr->val) {
                ListNode* toInsert = curr->next;
                curr->next = toInsert->next;

                ListNode* prev = temp;

                while (prev->next->val < toInsert->val) {
                    prev = prev->next;
                }

                toInsert->next = prev->next;
                prev->next = toInsert;
            } else {
                curr = curr->next;
            }
        }

        head = temp->next;
        delete temp;
        return head;
    }
};