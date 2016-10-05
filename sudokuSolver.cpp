

vector<int> possibleNums(vector<vector<int> >& board, int i,int j){
    vector<int> ans;
    int poss[10];
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

bool sudokuSolution(vector<vector<int> >& board){

}
