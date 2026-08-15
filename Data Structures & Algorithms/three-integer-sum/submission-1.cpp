class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // better using hashmap - fix i and j and use freq map - o(n2) o(n)
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> count;
        for(int num : nums){
            count[num]++;
        }
        // to store valid triplets
        vector<vector<int>> res;
        // choose the first number
        for(int i = 0; i < n; i++){
            // cnt-- cuz we have already used this as our first number
            count[nums[i]]--;
            // skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // choose the second number
            for (int j = i + 1; j < n; j++) {
                count[nums[j]]--;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int target = -(nums[i] + nums[j]);
                if (count[target] > 0) {
                    res.push_back({nums[i], nums[j], target});
                }
            }

            // restoring the map
            for (int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]++;
            }
        }

        return res;
    }
};