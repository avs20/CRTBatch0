//Leet code  238 : Product of array except self 
// Follow up 
// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        //create a vector with all values intialized to 1 
        vector<int> products(nums.size(), 1);
        
        // vector<int> leftProducts(nums.size(), 1);
        // vector<int> rightProducts(nums.size(), 1);
        
        int leftRunningProduct  = 1;
        for(int i = 0; i < nums.size() ; i++ ){
            products[i] = leftRunningProduct;
            leftRunningProduct = leftRunningProduct * nums[i];
        }
        
        int rightRunningProduct  = 1;
        for(int i = nums.size() - 1; i >=0  ; i-- ){
            products[i] = products[i] * rightRunningProduct;
            rightRunningProduct = rightRunningProduct * nums[i];
        }
        
        // for(int i = 0 ; i < nums.size() ;i++){
        //     products[i] = leftProducts[i] * rightProducts[i];
        // }
        
        
        return products;
    }
};
