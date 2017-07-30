class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ctr = 0;
        int N = board.size();
        int M = board[0].size();
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if( board[i][j] == 'X' && !( i > 0 && board[i-1][j] == 'X') && !( j > 0 && board[i][j-1] == 'X') )
                    ctr++;
        return ctr;
    }
};
