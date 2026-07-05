class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int a = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            if(s.find(nums[i]) != s.end()){
                a = nums[i];
                return a;
            }
            s.insert(nums[i]);
        }
  return -1;
    }
};