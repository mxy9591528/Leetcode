class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i = 0; i<len-2 && nums[i] <= 0; ++i){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = len-1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] < 0)
                    l++;         
                else if(nums[i] + nums[l] + nums[r] > 0)
                    r--; 
                else{
                    res.push_back({nums[i], nums[l++], nums[r--]});
                    while (l < r && nums[l] == nums[l-1])  l++;
                    while (l < r && nums[r] == nums[r+1])  r--;
                }    
            }
        }
        return res;
    }
};
