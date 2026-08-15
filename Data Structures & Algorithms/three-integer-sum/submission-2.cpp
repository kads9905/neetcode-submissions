class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // using simple mathematics - o(n2 x log(no. of unique triplets))
        int n = nums.size();
        // to store unique triplets
        set<vector<int>> st;
        // check all possible triplets
        for(int i = 0; i < n; i++){
            // set to store elemenst seen so far in the loop
            set<int> hashset;
            for(int j = i + 1; j < n; j++){
                int third = -(nums[i] + nums[j]);
                // find if 3rd element exist in hashset
                if(hashset.find(third) != hashset.end()){
                    // found the triplet
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // insert current element into hashset for future checks
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};