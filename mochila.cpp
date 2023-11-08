#include <iostream>
#include <algorithm>
int** ganancia(int* v, int* w, int N, int M){
	int** m = new int*[N+1];
	for(int i = 0; i <= N; i++){
		m[i] = new int[M+1];
		m[i][0] = 0;
		if(i == 0){
			for(int j = 0; j <= M; j++){
				m[i][j] == 0;
			}
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(w[i-1] > j && i == 1){
				m[i][j] = 0;
			}
			else if(w[i-1] <= j && i == 1){
				m[i][j] = v[i-1];
			}
			else if(w[i-1] > j && j > 0 && i > 1){
				m[i][j] = m[i-1][j];
			}
			else if(w[i-1] <= j && i > 1){
				m[i][j] = std::max(m[i-1][j], v[i-1] + m[i-1][j-w[i-1]]);
			}
				
		}
	}
	return m;
}

int* vuelta(int* v, int* w, int N, int M, int** m){
	int i = N;
	int j = M;
	int* x = new int[N+1];
	for(int c = 0; c <= N; c++){
	       x[c] = 0;
	}	       
	while( i > 0 && j > 0){
		if(m[i][j] ==  v[i-1] + m[i-1][j-w[i-1]]){
			j-= w[i-1];
			x[i] = 1;
		}
		else if(i == 1 && m[i][j] == v[i-1]){
			x[i] = 1;
		}
		i--;
	}
	return x;
}

int main(){
	int N = 4;
	int M = 5;
	int p[] = {1,3,2,4};
	int b[] = {10,20,15,20};
	int** matrix = new int*[N+1];
	for(int i = 0; i <= N; i++){
	       matrix[i] = new int[M+1];
	}
	matrix = ganancia(b, p, N, M);
	for( int i = 0; i <= N; i++){
		for(int j = 0; j <= M; j++){
			std::cout<< " valor:" << matrix[i][j]; 
		}
		std::cout << std::endl;
	}
	int* x;
	x = vuelta(b, p, N, M, matrix);
	std::cout << "x = {";
	for(int i = 1; i <= N; i++){
		if( i == N){
			std::cout << x[i] << "}" << std::endl;
		}
		else{	
			std::cout << x[i] << ", ";
		}
	}
	return 0;
}

