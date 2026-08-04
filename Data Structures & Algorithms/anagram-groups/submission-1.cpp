class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // better approacch - o(n * k log k) o(n * k)
        unordered_map<string, vector<string>> res;
        for(const auto& s: strs){
            // create a copy to store s
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            res[sortedS].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& pair: res){
            result.push_back(pair.second);
        }
        return result;
    }
};
