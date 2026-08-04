class Solution {
public:
    // brute approach - o(n2 * k log k) o(n)(vis arr + o/p)
    bool isAnagram(string s, string t){
        if (s.length() != t.length()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<bool> visited(n , false);
        vector<vector<string>> result;
        
        for(int i = 0; i < n; i++){
            if (visited[i])
                continue;
            vector<string> group;
            group.push_back(strs[i]);
            visited[i] = true;

            for(int j = i + 1; j < n; j++){
                if(!visited[j] && isAnagram(strs[i], strs[j])){
                    group.push_back(strs[j]);
                    visited[j] = true;
                }
            }
            result.push_back(group);
        }
        return result;
    }
};
