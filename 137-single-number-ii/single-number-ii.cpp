class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        
        for(int bit=0;bit<=31;bit++){
            int temp=1<<bit;
            int countones=0;

            for(int &num:nums){
                if((num & temp)==0){

                }
                else{
                    countones++;
                }
            }
            if(countones%3==1){
                result=(result | temp);
            }
        }
        return result;
    }
};