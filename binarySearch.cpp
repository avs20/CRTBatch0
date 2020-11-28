#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int> array, int target){

  int start = 0 ;
  int end  = array.size() - 1;

  while (start <= end ){
    int mid = (start + end) / 2;

    if( array[mid] == target ){
      return true;
    }
    else if ( array[mid] < target) {
      start = mid + 1;
    }else{
      end = mid - 1;
    }
  }
  return false;
}

int main(){
  vector<int> input = { 3, 12, 16, 19, 24, 31};

  bool result = binarySearch(input, 108);

  cout<<result<<" ";
}
