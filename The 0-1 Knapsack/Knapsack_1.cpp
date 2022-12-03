#include <iostream>
#define N 4
using namespace std;

typedef int index;

int W=16; //무게의 합 최대
int w[N+1]={0, 2, 5, 19, 5}; //weight
int p[N+1]={0, 40, 30, 50, 10}; //profit
int bestset[N];
string include[N];
int maxprofit=0;
int numbest=0;
int weight;
int profit;
   
bool promising(index i);
void knapsack(index i, int profit, int weight){
    if(weight<=W and profit>maxprofit){
        maxprofit=profit;
        numbest=i;
        //bestset=include; //배열복사
    }

    if(promising(i)){
        include[i+1]="yes";
        knapsack(i+1, profit+p[i+1], weight+w[i+1]);
        include[i+1]="no";
        knapsack(i+1, profit, weight);
    }
}

bool promising(index i){
    index j,k;
    int totweight;
    float bound;

    if(weight>=W)
        return false;
    else{
        j=i+1;
        bound=profit;
        totweight=weight;
        while(j<=N and totweight+w[j]<=W){
            totweight=totweight+w[j];
            bound=bound+p[j];
            j++;
        }
        k=j;
        if(i<=N)
            bound=bound+(W-totweight)*p[k]/w[k];
        return bound>maxprofit;
    }
}
    
int main(void){
    knapsack(N,0,0);
    for(int i=0; i<N-1; i++){
        cout<<bestset[i]<<endl;
    }
    

}