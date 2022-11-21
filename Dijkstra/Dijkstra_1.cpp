#include <iostream>
#define inf 99999
#define N 6

using namespace std;
int F[N];
int W[N][N]={
    {0, 0, 0, 0, 0, 0},
    {0, 0, 7, 4, 6, 1},
    {0, inf, 0, inf, inf, inf},
    {0, inf, 2, 0, 5, inf},
    {0, inf, 3, inf, 0, inf},
    {0, inf, inf, inf, 1, 0}
};

void dijkstra(int n, const int W[][N], int F[]){
    int i, vnear, e;
    int touch[n]; //2~n
    int length[n]; //2~n
    //F={}
    for(i=2; i<=n; i++){
        touch[i]=1;
        length[i]=W[1][i];
    }
    for(int c=0; c<=n-2; c++){ //n-1회
        int min=inf;
        for(i=2; i<=n; i++){
            if(length[i]>=0 && length[i]<=min){
                min=length[i];
                vnear=i;
            }
        }
        e=touch[vnear];
        F[c]=e;
        for(i=2; i<=n; i++){
            if(length[vnear]+W[vnear][i]<length[i]){
                length[i]=length[vnear]+W[vnear][i];
                touch[i]=vnear;
            }
        }
        length[vnear]=-1;
    }
    for(int i=2; i<=n; i++){
        cout<<touch[i]<<" ";
    }
    cout<<endl;

    for(int i=2; i<=n; i++){
        cout<<length[i]<<" ";
    }
    cout<<endl;
}

int main(void){
    

    dijkstra(N,W,F);
    
    
    
    for(int i=0; i<=N; i++){
        cout<<F[i]<<" ";
    }
    cout<<endl;
}