class Solution {
public:
    bool isAnagram(string s, string t) {
        // optimal-hashmap-2
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> freq;
        
        for(char ch: s){
            freq[ch]++;
        }

        for(char ch: t){
            freq[ch]--;
        }

        for(const auto& it: freq){
            if( it.second != 0 ) return false;
        }
        return true; 
    }
};
