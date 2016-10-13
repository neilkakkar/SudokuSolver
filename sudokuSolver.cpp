#include "sudokuSolver.h"


vector<int> possibleNums(vector<vector<int> >& board, pair<int,int> index){
    // generates the possible numbers that can be places at the given index.
    vector<int> ans;
    int i= index.first;
    int j= index.second;
    int poss[10]; //enumerates the 9 possibilities.
    for(int k=0;k<10;k++)poss[k]=0;
    //check row & column
    for(int k=0;k<N;k++){
        poss[board[i][k]]++;
        poss[board[k][j]]++;
    }
    //check square
    int I = i-i%3;
    int J = j-j%3;
    for(int k=I;k<I+2;k++){
        for(int l=J;l<J+2;l++){
            poss[board[k][l]]++;
        }
    }
    for(int k=1;k<10;k++){
        if(poss[k]==0)ans.push_back(k);
    }
    return ans;
}

pair<int,int> findEmptyIndex(vector<vector<int> >& board){
    // Finds the first empty index, which we will choose as the branch for inserting next number.
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==0)return make_pair(i,j);
        }
    }
    return make_pair(-1,-1);

}

pair<int,int> findSmallestEmptyIndex(vector<vector<int> >& board){
    // heuristic to speed up findEmptyIndex -> Finds the empty index with least number of possibilities.
    // TO DO : Can optimize this, right now uses a lot of unnecessary extra space -> The extra vectors being created for size.
    vector<pair<int,int> > possibleVals;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==0)possibleVals.push_back({i,j});
        }
    }
    int n = possibleVals.size();
    if(n==0) return make_pair(-1,-1); // Invalid

    int sizes[n];
    for(int i=0;i<n;i++){
        sizes[i] = possibleNums(board,possibleVals[i]).size();
    }
    int minSize =sizes[0];
    int minId =0;
    for(int i=1;i<n;i++){
        if(minSize > sizes[i]){
            minSize = sizes[i];
            minId =i;
        }
    }
    return possibleVals[minId];
}

bool sudokuSolution(vector<vector<int> >& board){
    // Final backtracking algorithm to find Sudoku solution
    //pair<int,int> index = findEmptyIndex(board); // Normal slow solution
    pair<int,int> index = findSmallestEmptyIndex(board);

    if(index.first==-1)return true;

    vector<int> possible = possibleNums(board,index);
    int x = index.first;
    int y = index.second;
    for(int i=0;i<possible.size();i++){
        board[x][y] = possible[i];
        if(sudokuSolution(board)) return true;
        board[x][y]= 0;
    }
    return false;
}
