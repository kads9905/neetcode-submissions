class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            int currentNum = nums[i];
            int moreNeeded = target - currentNum;
            if(mpp.find(moreNeeded) != mpp.end()){
                return {mpp[moreNeeded] , i};
            }
            mpp[currentNum] = i;
        }
        return {};
    }
};
