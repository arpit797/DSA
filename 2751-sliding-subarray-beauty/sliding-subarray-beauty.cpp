class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        vector<int> freq(101, 0);

        int i = 0;

        for (int j = 0; j < nums.size(); j++) {

            freq[nums[j] + 50]++;

            if (j - i + 1 == k) {

                int count = 0;
                int beauty = 0;
                for (int val = -50; val < 0; val++) {

                    count += freq[val + 50];

                    if (count >= x) {
                        beauty = val;
                        break;
                    }
                }

                ans.push_back(beauty);
                freq[nums[i] + 50]--;
                i++;
            }
        }

        return ans;
    }
};