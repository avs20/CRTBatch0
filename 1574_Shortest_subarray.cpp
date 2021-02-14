// Wrong solutions
//Leet Code 1574 : Shortest Subarray
//https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        
        //[1]
        if(arr.size() == 1){
            return 0;
        }
        
        int wrongElements = 0;
        
        for (int i = 0 ; i < arr.size() ; i++) {
            int num = arr[i];
            
            if(isOutOfOrder(i, num ,arr)) {
                wrongElements++;        
            }
        }
        
        //case of 5,4,3,2,1
        if (wrongElements == arr.size()){
            return arr.size() -1;
        }
        
        
        return wrongElements;
        
    }
    
    //i = index of number 
    //num = current number
    //arr current given array
    bool isOutOfOrder(int i, int num, vector<int> arr){
        //if i ==0, first element 
        //check if only < it's right neighour
        if (i == 0 ){
            return num > arr[i+1];
        }
        
        //if i== last element
        // check if only > left neightbour 
        if ( i == arr.size() - 1){
            return num < arr[i-1];
        }
        
        // general case 
        // check > left and < right neighbour
        return num > arr[i+1] || num < arr[i-1];
    }
};
