//https://leetcode.com/problems/3sum/?fbclid=IwAR2ayuxE0A8W3RaMxOpykeBXlA7_a9I7adyuV43NGaBHwg7A-T7Kpjb0sGA

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        set<vector<int>> unique_ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n - 2; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i]; // a + b + c = 0 => b + c = - a;
            int left = i + 1, right = n - 1;

            while(left < right) {
                int sum = nums[left] + nums[right];

                if(sum < target)
                    ++left;
                else if(sum > target)
                    --right;
                else {
                    unique_ans.insert({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;

                    while(left < right && nums[left] == nums[left - 1]) ++left;
                    while(left < right && nums[right] == nums[right + 1])
                        --right;
                }
            }
        }

        vector<vector<int>> ans(unique_ans.begin(), unique_ans.end());
        return ans;
    }
};