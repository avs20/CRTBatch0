//LEETCODE 54 :  Spiral Traverse
//https://leetcode.com/problems/spiral-matrix/submissions/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        if (matrix.size() == 0)
            return {};
        
        
        vector <int> result = {};
        
        int startRow = 0 ;
        int endRow = matrix.size() - 1;
        int startCol = 0 ;
        int endCol = matrix[0].size() - 1; //get the number of columns -1 
        
        while (startRow <= endRow && startCol <= endCol){
            
            // top row code 
            for (int col = startCol ; col <= endCol ; col++){
                result.push_back( matrix[startRow][col]);
            }
            
            // right col code 
            for (int row = startRow + 1; row <= endRow ; row++){
                result.push_back(matrix[row][endCol]);
            }
            
            //bottom row code 
            for (int col = endCol - 1 ; col >= startCol ; col--){
                //check the edge case of single row 
                //don't double count 
                if (startRow == endRow)
                    break;
                result.push_back(matrix[endRow][col]);                
            }
            
            for (int row = endRow -1 ; row >= startRow +  1; row--){
                //check for single column 
                if (startCol == endCol)
                    break;
                result.push_back(matrix[row][startCol]);
            }
            
            startRow++;
            startCol++;
            endRow--;
            endCol--;
            
        }
        
        return result;
        
    }
};
