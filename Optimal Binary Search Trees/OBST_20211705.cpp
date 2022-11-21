#include <iostream>
#define inf 99999

using namespace std;

int R[6][5]={0,};
float minavg=0;
float p[5]={0, 0.2, 0.3, 0.1, 0.4}; //자작 데이터
//float p[5] = { 0,0.375,0.375,0.125,0.125 }; //예제 데이터
float A[6][6];

void optsearchtree(int n, const float p[], float& minavg, int R[][5]){
    int i,j,k,diagonal;
    

    for(i=1; i<=n; i++){
        A[i][i-1]=0;
        A[i][i]=p[i];
        R[i][i]=i;
        R[i][i-1]=0;
    }

    A[n+1][n]=0;
    R[n+1][n]=0;
    for(diagonal=1; diagonal<=n-1; diagonal++){
        for(i=1; i<=n-diagonal; i++){
            j=i+diagonal;
            for(k=i; k<=j; k++)
                if((A[i][k-1]+A[k+1][j])<A[i][j]){
                    A[i][j]=(A[i][k-1]+A[k+1][j]);
                    R[i][j]=k;
                }
            
            for (int a = i; a <= j; a++) {
                   A[i][j] += p[a];
            }

        }
    }
    minavg=A[1][n];
}

int main(void){
    
    for(int i=1; i<=5; i++){ //초기화
        for(int j=0; j<=4; j++){
            A[i][j]=inf;
        }
    }
    optsearchtree(4,p,minavg,R);
    cout<<"Optimal : "<<minavg<<endl<<endl;

    cout<<"Array A"<<endl;
    for(int i=1; i<=5; i++){
        for(int j=0; j<=4; j++){
            cout<<A[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    cout<<"Array R"<<endl;
    for(int i=1; i<=5; i++){
        for(int j=0; j<=4; j++){
            cout<<R[i][j]<<'\t';
        }
        cout<<endl;
    }

}