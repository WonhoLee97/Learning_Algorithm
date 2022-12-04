#include <iostream>
#include <algorithm>
#define N 4
using namespace std;

typedef int index;

int W=16; //무게의 합 최대
int w[N+1]={0, 2, 5, 10, 5}; //weight
int p[N+1]={0, 40, 30, 50, 10}; //profit
string bestset[N+1];
string include[N+1];
int maxprofit;
int numbest;
int weight;
int profit;
int totweight;
float bound;
   
bool promising(index i); //, int profit, int weight
void knapsack(index i, int profit, int weight){
    if(weight<=W and profit>maxprofit){
        maxprofit=profit;
        numbest=i;
        for(int c=0; c<=numbest; c++){ //배열 복사
            bestset[c]=include[c];
        }
    }

    if(promising(i)){
        include[i+1]="yes";
        knapsack(i+1, profit+p[i+1], weight+w[i+1]);
        include[i+1]="no";
        knapsack(i+1, profit, weight);
    }
}

bool promising(index i){//, int profit, int weight
    index j,k;
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
        if(k<=N)
            bound=bound+(W-totweight)*p[k]/w[k];
        return bound>maxprofit;
    }
}
    
int main(void){
    knapsack(0,0,0);
    cout<<"Best set"<<endl;
    for(int c=0; c<=N; c++){
        cout<<c<<'\t'<<bestset[c]<<endl;
    }
    cout<<endl;
    int price=0;
    for(int i=0; i<=numbest; i++){
        if(bestset[i]=="yes")
            cout<<i<<'\t'<<p[i]<<endl;
            price+=p[i];
    }
    cout<<"Result price : "<<price<<endl;

}