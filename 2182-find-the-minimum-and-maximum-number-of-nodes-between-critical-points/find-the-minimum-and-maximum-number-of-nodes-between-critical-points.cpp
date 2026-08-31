/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // prev node track karne ke liye
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1; // curr ka index (head ka index 0 hai)

        int firstIdx = -1;   // pehla critical point ka index
        int prevIdx = -1;    // pichla critical point ka index
        int minDist = INT_MAX;
        int maxDist = -1;

        while (curr->next != nullptr) {
            // local maxima check
            bool isMax = curr->val > prev->val && curr->val > curr->next->val;
            // local minima check
            bool isMin = curr->val < prev->val && curr->val < curr->next->val;

            if (isMax || isMin) {
                if (firstIdx == -1) {
                    // ye pehla critical point hai
                    firstIdx = index;
                } else {
                    // min distance consecutive critical points se update hoga
                    minDist = min(minDist, index - prevIdx);
                }
                // max distance hamesha first se current tak ka hoga
                maxDist = index - firstIdx;
                prevIdx = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // agar 2 se kam critical points mile
        if (minDist == INT_MAX) return {-1, -1};

        return {minDist, maxDist};
    }
};