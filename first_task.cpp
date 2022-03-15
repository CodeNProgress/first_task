#include <iostream>
#include <vector>
#include <omp.h>
#include <time.h>

using namespace std;

vector<int> A, B, C;
int M, K, N;

int main(){
	cin >> M >> K >> N;

	A.resize(M * K + 1);
	B.resize(K * N + 1);
	
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < K; ++j){
			cin >> A[i*K + j];
		}
	}
	
	for (int i = 0; i < K; ++i){
		for (int j = 0; j < N; ++j){
			cin >> B[i*N + j];
		}
	}
	
	C.resize(M * N);
    
	#pragma omp parallel for
	for (int i = 0; i < M; ++i){
		int a_helper = i*K;
		int c_helper = i*N;
		for (int j = 0; j < N; ++j){
			C[c_helper + j] = 0;
			for (int k = 0; k < K; ++k){
				C[c_helper + j] += A[a_helper + k] * B[k*N + j];
			}
 		}
 	}
 	
 	
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j){
			cout << C[i*N + j] << " ";
		}
		cout << endl;
	}
}

