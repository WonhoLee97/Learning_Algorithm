#include <iostream>
#define inf 99999
using namespace std;

int P[5][6]={0,};
int d[6];

int minmult(int n, const int d[], int P[][6]){
    int i,j,k,diagonal;
    int M[n][n];
    for(i=1; i<=n; i++){ //주대각선 0채움
        M[i][i]=0;
    }
    for(diagonal=1; diagonal<=n; diagonal++){
        for(i=1; i<=n-diagonal; i++){
            j=i+diagonal;
            M[i][j]=inf;
            for(int k = i; k <= j - 1; k++){
                if(M[i][j]>M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j]){
                    M[i][j] = min(M[i][j], M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]);
                    P[i][j] = k;
                }
            }
        }
        for(int i=1; i<=6; i++){
        for(int j=1; j<=6; j++){
            cout<<M[i][j]<<'\t';
        }
        cout<<endl;
    }
    }
    return M[1][n];
}

void order(int i, int j){
    if(i==j){
        cout<<"A"<<i;
    }
    else{
        int k=P[i][j];
        cout<<"(";
        order(i,k);
        order(k+1,j);
        cout<<")";
    }
}

int main(void){
    d[0]=5; d[1]=2; d[2]=3; d[3]=4; d[4]=6; d[5]=7; d[6]=8;
    for(int i=1; i<=5; i++){
        for(int j=1; j<=6; j++){
            cout<<P[i][j]<<'\t';
        }
        cout<<endl;
    }
    //order(2,6);
    return 0;    
}