class Solution {
public:
    int trap(vector<int>& height) {
        // using stack - o(n) o(n)
        if (height.empty()) {
            return 0;
        }

        // keep indices of bars in a decreasing-height stack
        stack<int> stk;
        int res = 0;

        for (int i = 0; i < height.size(); i++) {
            // if the current bar is smaller : push it
            // if current bar is taller/equal : 
            // current bar can act as a right boundary
            while (!stk.empty() && height[i] >= height[stk.top()]) {
                int mid = height[stk.top()];
                // pop the valley
                // the new stack top becomes the left boundary
                stk.pop();
                if (!stk.empty()) {
                    int right = height[i];
                    int left = height[stk.top()];
                    int h = min(right, left) - mid;
                    int w = i - stk.top() - 1;
                    res += h * w;
                }
            }
            stk.push(i);
        }

        return res;
    }
};