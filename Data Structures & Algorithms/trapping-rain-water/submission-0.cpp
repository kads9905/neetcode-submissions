class Solution {
public:
    int trap(vector<int>& height) {
        // brute force - o(n2) o(1)
        // For every bar, separately find the tallest bar 
        // on its left and the tallest bar on its right.
        // Then calculate how much water that particular bar can hold.
        if( height.empty()) return 0;
        int n = height.size();
        int res = 0;

        for(int i = 0; i < n; i++){
            int leftMax = height[i];
            int rightMax = height[i];

            // find tallest bar on left
            for(int j = 0; j < i; j++){
                leftMax = max(leftMax, height[j]);
            }
            // find tallest bar on right
            for(int j = i + 1; j < n; j++){
                rightMax = max(rightMax, height[j]);
            }
            res += min(leftMax, rightMax) - height[i];
        }
        return res;
    }
};
