#include <iostream>
#include <limits>
#include <algorithm>
int** cambio(int* v, int N, int M){
	int** m = new int*[N];
	for( int i = 0; i < N; i++){
		m[i] = new int[M+1];
	}
	int infinito = std::numeric_limits<int>::max();
	for( int i = 0; i < N; i++){
		m[i][0] = 0;
	}
	for( int i = 0; i < N; i++){
		for(int j = 1; j < M+1; j++){
			m[i][j] = -1;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 1; j < M+1; j++){
			if(i == 0 && v[i] > j){
				m[i][j] = infinito;
			}
			else if(i == 0 && v[i] <= j){
				m[i][j] = 1 + m[0][j-v[i]];
			}
			if(i > 0 && v[i] > j && j > 0){
				m[i][j] = m[i-1][j];
			}
			else if(i > 0 && v[i] <= j){
				m[i][j] = std::min(m[i-1][j], 1 + m[i][j - v[i]]);

			}
		}
	}
	return m;
}

int* vuelta(int* v, int N, int M, int** m) {
	int* x = new int[N];
	for (int i = 0; i < N; i++) {
	        x[i] = 0;
	}
	int j = M;
	int i = N-1;		    
	while (i >= 0 && j >= 0) {
		if ((m[i][j] != 1 + m[i][j - v[i]]) || j - v[i] < 0) {
			i = i - 1;
		} else {
			x[i] = x[i] + 1;
			j = j - v[i];
		}
	}
	return x;
}


int main(){
	int v[] = {1,4,6};
	int N = sizeof(v)/sizeof(v[0]);
	std::cout <<"el valor de N = " << N << std::endl;
	int M = 8;
	int** matrix = new int*[N];
	for( int i = 0; i < N; i++){
		matrix[i] = new int[M+1];
	}
	matrix = cambio(v, N, M);
	for( int i = 0; i < N; i++){
		for(int j = 0; j < M+1; j++){
			std::cout<< " valor:" << matrix[i][j]; 
		}
		std::cout << std::endl;
	}

	int* x;
	x = vuelta(v, N, M, matrix);

	std::cout << "x = ";
	for(int i = 0; i < N; i++){
		std::cout << "[" << x[i] << "] ";
	}
	std::cout << std::endl;
	return 0;
}
