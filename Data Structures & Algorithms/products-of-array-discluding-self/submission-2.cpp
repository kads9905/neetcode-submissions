class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // better - using division - o(n) o(1)
        int n = nums.size();
        int prod = 1, zeroCount = 0;
        for(int num : nums){
            if(num != 0){
                prod *= num;
            } else {
                zeroCount++;
            }
        }
        if(zeroCount > 1){
            // case 3: 2 or more zeroes 
            return vector<int>(n, 0);
        }
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            // case 1 : one zero
            if(zeroCount > 0){
            // Only the zero's position gets the product
            // of non-zero elements; all other positions are 0 
                res[i] = (nums[i] == 0) ? prod : 0;
            // case 2: no zero
            } else {
                res[i] = prod/nums[i];
            }
        }
        return res;
    }
};
