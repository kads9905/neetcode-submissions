class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // brute force - o(n3) o(m) + space used by sorting algorithm
        int n = nums.size();
        // set to not store dupe triplets
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n ; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if ( nums[i] + nums[j] + nums[k] == 0){
                        res.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
