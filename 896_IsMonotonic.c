// LEETCODE : 896 Is Monotonic 

bool isMonotonic(int* A, int ASize){
    
    bool isIncreasing = true;
    bool isDecreasing = true;
    
    for (int i = 1 ; i < ASize; i++){
        
        if (A[i]  <  A[i-1]){
            isIncreasing = false;
        }
        if (A[i] > A[i-1]){
            isDecreasing = false;
        }        
    }
    
    return isIncreasing || isDecreasing ; 
    

}
