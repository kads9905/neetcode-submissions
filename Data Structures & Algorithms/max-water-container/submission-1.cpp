class Solution {
public:
    int maxArea(vector<int>& heights) {
        // optimal - 2 pointers - o(n) o(1)
        int res = 0;
        int l = 0;
        int r = heights.size() - 1;

        while (l < r){

            int area = min(heights[l], heights[r]) * ( r - l);
            res = max(res, area);

            if(heights[l] <= heights[r]){
                l++;
            } else {
                r--;
            }
            // The height is limited by the shorter line, 
            // so to potentially increase the area, 
            // we must move the pointer at the shorter line inward.
            // Moving the taller line never helps because 
            // it keeps the height the same but reduces the width.
        }
        return res;
    }
};
