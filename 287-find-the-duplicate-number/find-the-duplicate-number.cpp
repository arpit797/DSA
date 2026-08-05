class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> num(n+1, 0); // count array, index 0 to n

        for(int i=0; i<n; i++){
            num[nums[i]]++;
            if(num[nums[i]] > 1){
                return nums[i]; // yahi duplicate hai, turant return kar do
            }
        }

        return -1; // constraints ke hisaab se yahan kabhi nahi pahunchega
    }
};