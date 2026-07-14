#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void backtrack(vector<int>& arr, int idx, int tar, vector<vector<int>>& ans, vector<int>& combination) {
        if (tar == 0) {
            ans.push_back(combination);
            return;
        }
        
        for (int i = idx; i < arr.size(); i++) {
            // Skip duplicates to avoid duplicate combinations
            if (i > idx && arr[i] == arr[i - 1]) continue;
            
            // If the current element exceeds the target, no need to proceed further
            if (arr[i] > tar) break; 
            
            combination.push_back(arr[i]);
            backtrack(arr, i, tar - arr[i], ans, combination); // 'i' instead of 'i+1' because numbers can be reused
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        sort(arr.begin(), arr.end()); // Sorting ensures duplicates are easy to skip
        backtrack(arr, 0, target, ans, combination);
        return ans;
    }
};
