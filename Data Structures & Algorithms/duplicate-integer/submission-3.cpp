class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mpp; 
        for(int num: nums){
            if(mpp.count(num)){
                return true;
            }
            mpp.insert(num);
        }
        return false;
    }
};