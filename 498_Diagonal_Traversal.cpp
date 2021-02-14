// Leet code 498 : Diagonal traversal
// https://leetcode.com/problems/diagonal-traverse/
// Time O(M*N) | Space O(M*N)
// M is the row size
// N is the column Size
// If n is total number of elements in matrix 
// Then Time O(n) Space O(n)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        //if empty matrix return empty array
        if (matrix.size() == 0 ){
            return {};
        }
        
        int height = matrix.size() - 1;
        int width = matrix[0].size() -1 ;
        
        vector<int> result = {};
        
        int row = 0 ;
        int col = 0 ;
        
        bool goingUp = true;
        
        while(!isOutOfBounds(row, col, height, width)){
            
            //if I am in loop, then the element is in correct position
            //add it to result
            result.push_back(matrix[row][col]);
            
            //now we need to find next element 
            
            if(goingUp){
                
                //if we are in first row or last column
                //then we need to change the direction
                if (row == 0 || col == width){
                    goingUp = false;
                    if (col == width){
                        //go down as we in last col
                        row++;
                    }else{
                        //go side. as we in top row
                        col++;
                    }
                } else {
                    //we are not in boundary case 
                    row--;
                    col++;
                    
                }
                
            }else{
                // we are in downward motion
                
                //check for boundary condition
                if (col == 0 || row == height){
                    goingUp = true;
                    
                    if (row == height) {
                        // need to go right side 
                        col++;
                    }else{
                        //need to go down 
                        row++;
                    }
                    
                    
                }else{
                    row++; //1 down
                    col--; // 1 left 
                }
            }
            
            
        }
        return result;
        
    }
    
    bool isOutOfBounds(int row, int col, int height, int width){
        return row < 0 || row > height || col < 0 || col > width;
    }
    
    
};
