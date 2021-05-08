#include <stdio.h>
#include <stdlib.h>

// O(N) time | O(N) Space 
int main(void) {

  int a[6] = {-5, -3 , 0, 1, 2, 7};

  //output array 
  int output[6];

  int left = 0 ;
  int right  = 6-1;

  // position to insert in output array 
  int toInsert = 5;

  while (left <= right){

    if (abs(a[left]) < abs(a[right])){
      output[toInsert] = a[right] * a[right];
      right--;
    }else{
      output[toInsert] = a[left] * a[left];
      left++;
    }

    toInsert--;

  }

  //print output array
  for (int i = 0 ; i < 6; i++){
    printf("%d\t", output[i]);
  }

 
}
