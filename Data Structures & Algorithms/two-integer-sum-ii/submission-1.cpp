class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // using hashmap - o(n), o(n)
        unordered_map<int, int>mpp;
        int n = numbers.size();
        for(int i = 0; i < n; i++){
            int currentNum = numbers[i];
            int moreNeeded = target - currentNum;
            if(mpp.count(moreNeeded)){
                return{mpp[moreNeeded], i + 1};
            }
            mpp[currentNum] = i + 1;
        }
        return {};
    }
};
