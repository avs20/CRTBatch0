
// LEETCODE 845
// https://leetcode.com/problems/longest-mountain-in-array/
int longestMountain(int* arr, int arrSize){
    
    if (arrSize < 3){
        return 0;
    }
    
    int longestMountainLength = 0;
    
    int i  = 1;
    
    while ( i < arrSize - 1) {
        bool isMountain = false;
        
        if ( (arr[i] > arr[i-1]) && (arr[i] > arr[i+1])){
                
                isMountain = true;
            
        }
        
        //if the current index is not a mountain, check next index
        if (!isMountain){
            i += 1;
            continue;
        }
        
        //if the current index is a mountain, calculate it's Length
        
        int leftIdx = i - 2;
        while (leftIdx >=0  && arr[leftIdx] < arr[leftIdx + 1]){
            leftIdx -= 1;
        }
        
        int rightIdx = i + 2; 
        while (rightIdx < arrSize && arr[rightIdx] < arr[rightIdx - 1]){
            rightIdx += 1;
        }
        
        int currentMountainLength = rightIdx - leftIdx - 1;
        
        if (currentMountainLength > longestMountainLength){
            longestMountainLength = currentMountainLength;
        }
        
        i = rightIdx;        
        
        
    }
    
    return longestMountainLength;
    

}
