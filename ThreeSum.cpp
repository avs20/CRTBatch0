//LeetCode : https://leetcode.com/problems/3sum/
//Runtime 69ms : 97%ile - O(N^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        vector<vector<int>> triplets;
        if (nums.size() < 3)
            return triplets;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0 ; i < nums.size() - 2 ; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            if(nums[i] > 0)
                break;
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right){
                int currentSum = nums[i] + nums[left] + nums[right];
                
                if (currentSum == 0) {
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]){
                      left++;  
                    } 
                    while(left < right && nums[right] == nums[right-1]) {
                        right--;
                    }
                    left++;
                    right--;
                    
                }else if (currentSum < 0){
                    left++;
                }else{
                    right--;
                }
            }
                
        }
        
    return triplets;
    }
};
