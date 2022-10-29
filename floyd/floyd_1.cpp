#include <iostream>
#define inf 99999
#define N 5


using namespace std;
int W[N][N];
int D[N][N];
int P[N][N];

void floyd(int n, const int W[][N], int D[][N], int P[][N]){
    int i, j, k;
    for(i=0; i<=n-1; i++)
        for(j=0; j<=n-1; j++)
            P[i][j]=0;
	
	for(i=0; i<=n-1; i++) //D=W;
		for(j=0; j<=n-1; j++)
			D[i][j]=W[i][j];
	
	for(k=0; k<=n-1; k++){
		for(i=0; i<=n-1; i++){
			for(j=0; j<=n-1; j++){
				if(D[i][k]+D[k][j]<D[i][j]){
					P[i][j]=k+1;
					D[i][j]=D[i][k]+D[k][j];
				}
			}
		}
	}

    
}

void print_all(int n, int array[][N]){
	for(int i=0; i<=n-1; i++){
		for(int j=0; j<=n-1; j++){
			cout<<array[i][j]<<'\t';
		}
		cout<<endl;
	}
	cout<<endl;
}

// void print_P(int n, int array[][N]){
// 	for(int i=0; i<=n-1; i++){
// 		for(int j=0; j<=n-1; j++){
// 			if(array[i][j]!=0){
// 				cout<<array[i][j]+1<<'\t';
// 			}
// 			else{
// 				cout<<array[i][j]<<'\t';
// 			}
// 		}
// 		cout<<endl;
// 	}
// 	cout<<endl;
// }

void path(int q, int r){
	int path_array[N][N];
	for(int i=0; i<=N-1; i++){
		for(int j=0; j<=N-1; j++){
			if(P[i][j]!=0){
				path_array[i][j]=P[i][j]-1;
			}
			else{
				path_array[i][j]=P[i][j];
			}
		}
	}
	print_all(N,path_array);
	cout<<endl;

	if(path_array[q-1][r-1]!=0){
		path(q-1,path_array[q-1][r-1]);
		cout<<" v"<<P[q-1][r-1];
		path(path_array[q-1][r-1],r-1);
	}
}

// void path(int q, int r){
// 	if(P[q][r]!=0){
// 		path(q,P[q][r]);
// 		cout<<" v"<<P[q][r];
// 		path(P[q][r],r);
// 	}
// }

int main(void){
    W[0][0]=0;
	W[0][1]=1;
	W[0][2]=inf;
	W[0][3]=1;
	W[0][4]=5;
	W[1][0]=9;
	W[1][1]=0;
	W[1][2]=3;
	W[1][3]=2;
	W[1][4]=inf;
	W[2][0]=inf;
	W[2][1]=inf;
	W[2][2]=0;
	W[2][3]=4;
	W[2][4]=inf;
	W[3][0]=inf;
	W[3][1]=inf;
	W[3][2]=2;
	W[3][3]=0;
	W[3][4]=3;
	W[4][0]=3;
	W[4][1]=inf;
	W[4][2]=inf;
	W[4][3]=inf;
	W[4][4]=0;
	cout<<"comple"<<endl;
	print_all(N,W);
	floyd(N,W,D,P);
	print_all(N,D);
	print_all(N,P);
	path(5,3);
	cout<<endl;
	return 0;
}