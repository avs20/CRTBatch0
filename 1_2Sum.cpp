// Leet code 1 
// https://leetcode.com/problems/two-sum/

#include <unordered_map>

// O(N) time and O(N) Space
// left / right :  O(NlogN) Time | O (1) Space
// left right 
// build a hashtable : number : position  O(N) space 
// left right O(NlogN) Time
// 3rd : O ( NlogN)  time | O (N) space 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> traversed_values;
        
        for (int i =  0 ; i < nums.size() ; i++){
            
            int firstNum = nums[i];
            
            int toFind = target - firstNum;
            
            if(traversed_values.find(toFind) != traversed_values.end()){
             
                return vector<int> {i, traversed_values[toFind]};
                
            }else {
                //element not found so add to hash table 
                traversed_values[firstNum] = i;
            }
            
            
            
        }
        
     return {};   
    }
};
