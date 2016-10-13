#include "sudokuSolver.h"

int main(){
    vector<vector<int> > board;
    vector<int> X(N);
    for(int i=0;i<N;i++)board.push_back(X);
    
    // Take the board as input. 1-9 as given original numbers, and empty spaces represented by 0.
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
        }
    }
    // Output solution if it exists
    if(sudokuSolution(board)){
        cout<<"Solution: \n";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No solution exists.";
    }
}
