class Solution {
    vector<int>v1,v2;
public:
    Solution(vector<int>& nums) {
        this->v1=nums;
        this->v2.resize(nums.size());
        copy(nums.begin(),nums.end(),v2.begin());
    }

    vector<int> reset() {
        copy(v2.begin(),v2.end(),v1.begin());
        return v1;
    }

    vector<int> shuffle() {
        for(int i=0;i<v1.size();i++)
        {
            int j=i+rand()%(v1.size()-i);
            swap(v1[i],v1[j]);
        }
        return v1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
