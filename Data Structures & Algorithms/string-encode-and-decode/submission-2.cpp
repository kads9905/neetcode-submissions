class Solution {
public:
    // For every string, store its length first, then #, then the actual string.
    // o(m + n) o(m + n) for each encode and decode func calls
    string encode(vector<string>& strs) {
        string res; //stores final encoded string
        for (const string& s : strs) {
            res.append(to_string(s.size())); //store length first
            res.push_back('#'); //then #
            res.append(s); //then the actual string
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res; //final decoded string
        int i = 0; //tells where the current encoded string starts
        while (i < s.size()) {
            // j is used to find #
            int j = i;
            // move j until we find #
            while (s[j] != '#') {
                j++;
            }
            // get the length
            int length = stoi(s.substr(i, j - i));
            //move i after # - i points to first character of the string
            i = j + 1;
            // calculate where string ends
            j = i + length;
            // extract the string
            res.push_back(s.substr(i, length));
            //move i - i is now pointing to next encoded length
            i = j;
        }
        return res;
    }
};
