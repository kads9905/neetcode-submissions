class Solution {
public:
    int trap(vector<int>& height) {
        // 2 pointers - o(n) o(1)
        if (height.empty()) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        // tallest wall seen from left and right side 
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while (l < r) {
            // is the left wall shorter? if yes left wall controls the water
            if (leftMax < rightMax) {
                l++;
                // is the new bar taller than the tallest bar we have seen?
                leftMax = max(leftMax, height[l]);
                // space between current bar and left wall
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};