#include <bits/stdc++.h>

using namespace std;

const int N = 9;

vector<int> possibleNums(vector<vector<int> >& board,int i,int j);

bool sudokuSolution(vector<vector<int> >& board);

pair<int,int> findEmptyIndex(vector<vector<int> >& board);

pair<int,int> findSmallestEmptyIndex(vector<vector<int> >& board);
