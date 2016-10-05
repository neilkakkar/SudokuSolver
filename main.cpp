#include "sudokuSolver.h"

int main(){
    vector<vector<int> > board;
    vector<int> X(N);
    for(int i=0;i<N;i++)board.push_back(X);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
        }
    }
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
