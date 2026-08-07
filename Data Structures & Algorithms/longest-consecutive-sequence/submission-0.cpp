class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // brute - o(n2) o(n)
        // using hashset - o(1) avg time
        int res = 0;
        unordered_set<int> store(nums.begin(), nums.end());

        for (int num : nums) {
            int streak = 0, curr = num;
            // store.fin(x) - o(1) avg time
            while (store.find(curr) != store.end()) {
                streak++;
                curr++;
            }
            res = max(res, streak);
        }
        return res;
    }
};