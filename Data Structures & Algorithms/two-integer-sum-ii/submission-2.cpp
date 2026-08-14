class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // using 2 pointers - o(n) o(1)
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right){
            int currSum = numbers[left] + numbers[right];
            // if sum is too big, move right pointer left to make it smaller
            if (currSum > target) {
                right--;
            // if sum is too small, move left pointer right to make it larger
            } else if (currSum < target) {
                left++;
            } else {
                return { left + 1, right + 1};
            }
        }
        return {};
    }
};
