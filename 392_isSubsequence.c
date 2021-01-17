// LEETCODE 392 : isSubsequence

bool isSubsequence(char * s, char * t){
    
    
    int tIdx = 0 ;
    int sIdx = 0 ;
    
    while (t[tIdx] != '\0' && s[sIdx] != '\0'){
        
        if ( t[tIdx] == s[sIdx]) {
            sIdx++;
        }
        
        tIdx++;        
    }
    
    if (s[sIdx] == '\0') return true;
    else return false;

}
