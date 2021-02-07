#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  
  unordered_map<string, int> subjects;

  // How to add in a map 
  subjects["Maths"] = 90;
  subjects["English"] = 88;
  subjects["Computers"] = 95;

  //how to use values
  cout << subjects["Maths"];

  // how to find in hashtable
  //use .find() 

  if(subjects.find("Computers") != subjects.end()){
    cout << "Value is found."<<subjects["Computers"] <<endl;
  }

  if(subjects.find("Hindi") == subjects.end()){
    cout << "Hindi" << " is not found" <<endl;
  }

  //how to delete values 
  subjects.erase("English");

  if(subjects.find("English") == subjects.end()){
    cout << "English" << " is not found" <<endl;
  }

}
