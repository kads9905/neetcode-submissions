class Solution {
public:
    // First store the length of every string, separated by commas,then # and then the original string
    // o(m+n) o(m+n) for each encode and decode
    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        vector<int> sizes;  //sizes store the length of every string
        string res;  //final encoded string
        // store lengths
        for (string& s : strs) {
            sizes.push_back(s.size());
        }
        // convert to string and encode the lengths 
        for (int sz : sizes) {
            res.append(to_string(sz));
            res.push_back(',');
        }
        // mark the end of the length section
        res.push_back('#');
        // append actual string
        for (string& s : strs) {
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<int> sizes; //store the lengths
        vector<string> res; //final decoded string
        int i = 0; //position in encoded string
        // we keep reading until we reach #
        while (s[i] != '#') {
            // Starting at i, move j until we find ,
            int j = i;
            while (s[j] != ',') {
                j++;
            }
            //Convert length from string to integer
            sizes.push_back(stoi(s.substr(i, j - i)));
            // moves past the comma
            i = j + 1;
        }
        // move past # -> i points to beginning of actual string data 
        i++;
        // reconstruct the string
        for (int sz : sizes) {
            // extract the characters
            res.push_back(s.substr(i, sz));
            i += sz;
        }
        return res;
    }
};