class Solution {
public:
    int maxArea(vector<int>& heights) {
        // brute force - o(n2) o(1)
        int res = 0;
        // pick 1st bar
        for (int i = 0; i < heights.size(); i++) {
            // pick every bar after it
            for (int j = i + 1; j < heights.size(); j++) {
                // min(i,j) - max possible water height
                // j-i - width
                // int area = min(heights[i], heights[j]) * (j-i);
                // largest area found so far
                // res = max(res, area);
                res = max(res, min(heights[i], heights[j]) * (j-i));
            }
        }
        return res;
    }
};