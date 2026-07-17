class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int largest=0;
        int sec_largest=0;
        for(int &num:nums){
            if(num>largest){
                sec_largest=largest;
                largest=num;

            }
            else{
                sec_largest=max(sec_largest,num);
            }
        }
        int maxproduct=largest*sec_largest;
        int smallest=INT_MAX;
        int sec_smallest=INT_MAX;
        for(int &num:nums){
            if(num<smallest){
                sec_smallest=smallest;
                smallest=num;
            }
            else{
                sec_smallest=min(sec_smallest,num);
            }
        }
        int minproduct=smallest*sec_smallest;
        int diff=maxproduct-minproduct;
        return diff;
    }
};