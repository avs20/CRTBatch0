//LeetCode : https://leetcode.com/problems/3sum/
//Runtime 69ms : 97%ile - O(N^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> triplets;
        
        //edge case check 
        if (nums.size() < 3){
            return triplets;
        }
        
        //1. Sort the array 
        sort(nums.begin(), nums.end());
        
        //2.Start for loop with i 
        for (int i = 0 ; i < nums.size() - 2 ; i++){
            
            //fasting 
            if(nums[i] > 0)
                break;
            
            //for duplicates 
            if (i > 0 && (nums[i] == nums[i-1])){
                continue;
            }
            
            //3. Create left and right pointers
            int left = i + 1;  // element next to i 
            int right = nums.size() - 1; //last element of array
            
            //4. Start the loop 
            while (left < right){
                
                //5. Calculate currentSum
                int cS = nums[i]  + nums[left] + nums[right];
                
                //6. Compare cS with 0 
                if (cS == 0 ){
                    //insert the answer into array
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    
                    //to do for duplicate values in L and R 
                    while(left < right && (nums[left] == nums[left+1])) left++;
                    while(left < right && (nums[right] == nums[right-1])) right--;
                    
                    left++;
                    right--;                    
                }
                else if( cS < 0){
                    left++;
                }else{
                    right--;
                }
            }            
        }
        
        //7. Return triplets
        return triplets;
            
    }
};
