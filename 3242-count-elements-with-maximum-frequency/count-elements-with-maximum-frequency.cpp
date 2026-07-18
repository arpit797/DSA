class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxfreq=0;
        for(int &num:nums){
            mp[num]++;
            maxfreq=max(maxfreq,mp[num]);
        }
        int result=0;
        for(int i=0;i<mp.size();i++){
            if(mp[i]==maxfreq){
                result+=maxfreq;
            }
        }
        return result;

    }
};