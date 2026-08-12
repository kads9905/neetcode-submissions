class Solution {
public:
    bool isPalindrome(string s) {
        // brute - o(n) o(n)
        string newStr = "";
        for(char c : s){
            if (isalnum(c)){
                newStr += (tolower(c));
            }
        }
        return newStr == string(newStr.rbegin(), newStr.rend());

    }
};
