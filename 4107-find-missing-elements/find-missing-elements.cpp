class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> present(nums.begin(), nums.end());
        
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        
        vector<int> result;
        for (int v = lo; v <= hi; v++) {
            if (present.find(v) == present.end()) {
                result.push_back(v);
            }
        }
        
        return result;
    }
};