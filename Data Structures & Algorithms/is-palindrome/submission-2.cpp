class Solution {
public:
    bool isPalindrome(string s) {
        // optimal - using 2 pointers - o(n) o(1)
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};