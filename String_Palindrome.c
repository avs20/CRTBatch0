#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/* Approach 1 
// Create a reversed Array 
// Time O(N) | Space O(N)
*/
// bool isPalindrome(char str[]){
//   int length = strlen(str);
//   char str2[length + 1];

//   for( int i = length - 1, j =0; i >= 0 ; i--, j++){
//     str2[j] = str[i];
//   }

//   str2[length] = '\0';

//   int result =strcmp(str, str2);
//   if (result == 0){
//     return true;
//   }
//   return false;

// }

/*
Take 2 pointers and go from left to right
matching each characters 
Time : O(N) | Space O(1)
*/
bool isPalindrome(char str[]){

  int left = 0 ; 
  int right = strlen(str)-1;

  while (left < right){
    if (str[left] != str[right]){
      return false;
    }
    left++;
    right--;
  }

  return true;

}

int main(void) {
  
  bool result = isPalindrome("ABCDCEBA");

  if (result){
    printf("String is Palindrome");
  }else{
    printf("string is NOT palindrome");
  }

  return 0;
}

/* solution in python
O(N) Time complexity 

+= O(N^2) time complexity
*/

chars = []
for i in reversed(range(len(str1))):
  chars.append(str1[i])

return str1 == "".join(chars)
