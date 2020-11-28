#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> twoNumberSum(vector<int> array, int target){


    for (int i = 0 ; i < array.size()  ; i++ ){
      int fNum = array[i];

      for (int j = i + 1 ; j < array.size() ; j++){
        int sNum = array[j];

        if ((fNum + sNum) == target){
            return vector<int>{fNum, sNum};
        }
      }
    }

    return {};
}



vector<int> twoNumberSumFast(vector<int> array, int target){

    //sort the array using in built algorithm
    sort(array.begin(), array.end());

    int left = 0 ;
    int right = array.size() - 1;

    while (left < right){

      int currentSum = array[left] + array[right];
      if( currentSum == target ) { 
        return vector<int>{array[left], array[right]};
      }else if ( currentSum < target ) {
        left++;
      }else {
        right--;
      }
      
    }

  return {};




}



int main(){

  vector<int> input = {16, 12, 31, 3, 19, 24};

  // vector<int> result = twoNumberSum(input, 14);

  // if (result.size() == 0){
  //   cout << " No pairs found"<<endl;
  //   return 0;
  // }

  // for (int i = 0 ; i < result.size() ; i++){
  //   cout << result[i] << "\t";
  // }

  vector<int> result = twoNumberSumFast(input, 22);


  if (result.size() == 0){
    cout << " No pairs found"<<endl;
    return 0;
  }

  for (int i = 0 ; i < result.size() ; i++){
    cout << result[i] << "\t";
  }

}



