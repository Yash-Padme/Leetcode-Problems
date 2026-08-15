class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size() ;
        int totalXor = 0 ;
        bool has_non_zero = false ;

        for (int x : nums){
            totalXor ^= x ;
            if( x> 0 ){
                has_non_zero = true ;

            }
        }


        if(!has_non_zero){
            return 0;
        }

        if(totalXor != 0 ){
            return n ;
        }

        return n-1 ;
    }
};