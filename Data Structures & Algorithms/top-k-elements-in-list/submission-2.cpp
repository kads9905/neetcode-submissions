class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // optimal - using bucket sort - o(n) o(n)
        unordered_map<int, int> count;
        for(int n : nums){
            count[n]++;
        }

        vector<vector<int>> freq(nums.size() + 1);
        for(const auto& i : count){
            freq[i.second].push_back(i.first);
        }

        vector<int> res;
        for(int i = nums.size(); i >=0; i--){
            if(freq[i].size() == 0) continue;
            for(int n : freq[i]){
                res.push_back(n);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};
