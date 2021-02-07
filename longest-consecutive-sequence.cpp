// Leetcode : 128 
// https://leetcode.com/problems/longest-consecutive-sequence/
#include <unordered_map>


// time O(N) | Space O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int longestLength = 0;
        unordered_map<int, bool> numTable = {};
        
        
        
        //1. Create a hashtable and set the values to true
        
        for (int i = 0 ; i < nums.size() ; i++){
            numTable[nums[i]] = true;
        }
            
        
        //2. process the array 
        
        for (int i = 0 ; i < nums.size() ;i++){
            
            int currentVal = nums[i];
            //3. If the value in hashtable is tru then process it else move to next
            if (!numTable[currentVal]){
                continue;
            }
            
            //process the values 
            numTable[currentVal] = false;
            
            int currentLength = 1;
            int left = currentVal -1 ;
            int right = currentVal + 1;
            
            //4. First process right side : check in hash table 
            while(numTable.find(right) != numTable.end()){
                numTable[right] = false;
                currentLength++;
                right++;
            }
            
            //5. Then process left side and check in hash table 
            while(numTable.find(left) != numTable.end()){
                numTable[left] = false;
                currentLength++;
                left--;
            }
            
            //check if currentLenght > longestLength;
            if (currentLength > longestLength){
                longestLength = currentLength;
            }
        
        }
        
        return longestLength;
        
    }
};
