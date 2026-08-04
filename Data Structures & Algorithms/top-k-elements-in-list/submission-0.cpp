class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // o(n log n) o(n)
        unordered_map<int , int> count;
        for(int num : nums){
            count[num]++;
        }
        // we want to sort according to frequency
        // cant sort hash map directly so we copy it into vector
        vector<pair<int, int>> arr;
        for(const auto& p : count){
            arr.push_back({p.second, p.first});
        }
        // sort in descending order
        sort(arr.rbegin(), arr.rend());

        // store the first k frequent elements
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(arr[i].second);
        }
        return res;
    }
};
