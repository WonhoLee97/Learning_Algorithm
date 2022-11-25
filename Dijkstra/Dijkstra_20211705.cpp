#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define inf 99999
#define N 6

using namespace std;
// int W[N][N]={ //교재 입력데이터
//     {0, 0, 0, 0, 0, 0},
//     {0, 0, 7, 4, 6, 1},
//     {0, inf, 0, inf, inf, inf},
//     {0, inf, 2, 0, 5, inf},
//     {0, inf, 3, inf, 0, inf},
//     {0, inf, inf, inf, 1, 0}
// };
vector<pair<int, int>> F;

int W[N][N]={ //자작 데이터
    {0, 0, 0, 0, 0, 0},
    {0, 0, 1, 7, 4, 5},
    {0, inf, 0, 1, inf, 3},
    {0, inf, inf, 0, 1, inf},
    {0, inf, inf, inf, 0, inf},
    {0, inf, inf, inf, 1, 0}
};

void dijkstra(int n, const int W[][N], vector<pair<int, int>> F){
    int i, vnear;
    int touch[n]; //2~n
    int length[n]; //2~n
    //F={}
    for(i=2; i<=n-1; i++){
        touch[i]=1;
        length[i]=W[1][i];
    }
    cout<<"first touch"<<endl;
    for(int i=2; i<=n-1; i++){
        cout<<touch[i]<<" ";
    }
    cout<<endl;
    cout<<"first length"<<endl;
    for(int i=2; i<=n-1; i++){
        cout<<length[i]<<" ";
    }
    cout<<endl;

    cout<<"Array F"<<endl;
    for(int c=1; c<n-1; c++){ //n-1회
        int min=inf;
        for(i=2; i<=n-1; i++){
            if(length[i]>=0 && length[i]<=min){
                min=length[i];
                vnear=i;
            }
        }

        F.push_back(make_pair(touch[vnear],vnear));
        cout<<F.back().first<<"->"<<F.back().second<<endl;


        for(i=2; i<=n-1; i++){
            if(length[vnear]+W[vnear][i]<length[i]){
                length[i]=length[vnear]+W[vnear][i];
                touch[i]=vnear;
            }
        }
        length[vnear]=-1;
    }
    cout<<"final touch"<<endl;
    for(int i=2; i<=n-1; i++){
        cout<<touch[i]<<" ";
    }
    cout<<endl;
    cout<<"final length"<<endl;
    for(int i=2; i<=n-1; i++){
        cout<<length[i]<<" ";
    }
    cout<<endl;
}

int main(void){
    dijkstra(N,W,F);
    cout<<endl;
}