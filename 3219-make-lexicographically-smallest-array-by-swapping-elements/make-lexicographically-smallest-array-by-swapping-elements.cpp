class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> valIdx(n);
        for (int i = 0; i < n; i++) valIdx[i] = {nums[i], i};
        sort(valIdx.begin(), valIdx.end());

        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            // group jab tak consecutive sorted values ka diff <= limit ho
            while (j + 1 < n && valIdx[j+1].first - valIdx[j].first <= limit) {
                j++;
            }
            // group [i..j] ke original indices nikal ke sort karo
            vector<int> idxs;
            for (int k = i; k <= j; k++) idxs.push_back(valIdx[k].second);
            sort(idxs.begin(), idxs.end());

            // sorted indices ko sorted values assign karo
            for (int k = i; k <= j; k++) {
                result[idxs[k - i]] = valIdx[k].first;
            }
            i = j + 1;
        }
        return result;
    }
};