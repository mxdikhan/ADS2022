#include <bits/stdc++.h>
using namespace std;

int rows, colm, cnt;

void dfs(char** matrix, int i, int j){
	if(i >= rows or j >= colm or i < 0 or j < 0 or matrix[i][j] == '0') return;
	matrix[i][j] = '0';
	dfs(matrix, i + 1, j); dfs(matrix, i - 1, j); dfs(matrix, i, j + 1); dfs(matrix, i, j - 1);
}

int main(){
	cin >> rows >> colm;
	char** matrix = new char* [rows];
	for(int i = 0; i < rows; i++){
		matrix[i] = new char[colm];
		for(int j = 0; j < colm; j++){
			cin >> matrix[i][j];
		}
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < colm; j++){
			if(matrix[i][j] == '1'){
				dfs(matrix, i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
