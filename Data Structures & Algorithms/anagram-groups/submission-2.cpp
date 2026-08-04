class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // optimal - o(n * k) o(n * k)
        unordered_map<string, vector<string>> res;
        for(const auto& s: strs){
            vector<int> count(26, 0);
            for(char c : s){
                count[c - 'a']++;
            }
            // string key = to_string(count[0]; - first number is already added
            // for(i = 1) key += ','+ to_string(count[i]); - thats why start from 1
            // here nothing is added yet
            string key = "";
            for(int i = 0; i < 26; i++){
                key += "#" + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for(const auto& pair: res){
            result.push_back(pair.second);
        }
        return result;
    }
};
