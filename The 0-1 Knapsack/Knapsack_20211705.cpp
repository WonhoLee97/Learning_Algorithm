#include <iostream>
#include <algorithm>
#define N 4
// #define W 16 //교재 입력데이터
#define W 10 //자작 입력데이터

using namespace std;
typedef int index;

//교재 입력데이터
// int w[N+1]={0, 2, 5, 10, 5}; //weight
// int p[N+1]={0, 40, 30, 50, 10}; //profit

//자작 입력데이터
int w[N+1]={0, 3, 4, 6, 5}; //weight
int p[N+1]={0, 8, 9, 12, 10}; //profit

string bestset[N+1];
string include[N+1];
int maxprofit=0;
int numbest;

   
bool promising(index i, int profit, int weight){
    index j,k;
    int totweight;
    float bound;
    if(weight>=W)
        return false;
    else{
        j=i+1;
        bound=(float)profit;
        totweight=weight;
        while(j<=N and totweight+w[j]<=W){
            totweight=totweight+w[j];
            bound=bound+p[j];
            j++;
        }
        k=j;
        if(k<=N){
            bound=bound+(W-totweight)*p[k]/w[k];
        }
        return bound>maxprofit;
    }
}

void knapsack(index i, int profit, int weight){
    if(weight<=W and profit>maxprofit){
        maxprofit=profit;
        numbest=i;
        for(int c=0; c<=N; c++){ //배열 복사
            bestset[c]=include[c];
        }
    }

    if(promising(i,profit,weight)){
        include[i+1]="yes";
        knapsack(i+1, profit+p[i+1], weight+w[i+1]);
        include[i+1]="no";
        knapsack(i+1, profit, weight);
    }
}


    
int main(void){
    knapsack(0,0,0);
    cout<<"Maxprofit : "<<maxprofit<<endl;
    cout<<"Best set"<<endl;
    for(int c=1; c<=N; c++){
        cout<<c<<'\t'<<bestset[c]<<endl;
    }
    cout<<endl;

}