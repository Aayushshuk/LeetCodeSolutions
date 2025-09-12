class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n= board[0].size();
        int index =0;
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(word[index] == board[i][j]){
                    if(search(board, word,i, j ,index, m ,n)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool search(vector<vector<char>>& board, string word, int row, int col, int index, int m, int n){
        if(index == word.size()){
            return true;
        }

        if(row<0 || col<0|| row==m || col==n || board[row][col] != word[index] 
        or board[row][col] == '!'){
            return false;
        }
        char ch = board[row][col];
        board[row][col] ='!';

        bool top = search(board, word, row-1, col, index+1,m,n);
        bool right = search(board, word, row, col+1, index+1, m,n);
        bool bottom = search(board, word, row+1, col,index+1, m,n);
        bool left = search(board, word, row, col-1,index+1,m,n);
        
        board[row][col] =ch;

        return top || bottom || left || right;
    }
};