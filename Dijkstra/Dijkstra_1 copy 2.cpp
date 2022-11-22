#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define inf 99999
#define N 6

using namespace std;
int W[N][N]={
    {0, 0, 0, 0, 0, 0},
    {0, 0, 7, 4, 6, 1},
    {0, inf, 0, inf, inf, inf},
    {0, inf, 2, 0, 5, inf},
    {0, inf, 3, inf, 0, inf},
    {0, inf, inf, inf, 1, 0}
};
vector<pair<int, int>> F;

// int W[N][N]={
//     {0, 0, 0, 0, 0, 0},
//     {0, 0, 2, 1, 3, 5},
//     {0, inf, 0, inf, 4, inf},
//     {0, inf, inf, 0, 1, 6},
//     {0, inf, inf, inf, 0, inf},
//     {0, inf, inf, inf, inf, 0}
// };

void dijkstra(int n, const int W[][N], vector<pair<int, int>> F){
    int i, vnear;
    pair<int,int> e;
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

    for(int c=0; c<=n-3; c++){ //n-1회
        int min=inf;
        for(i=2; i<=n-1; i++){
            if(length[i]>=0 && length[i]<=min){
                min=length[i];
                vnear=i;
            }
        }

        F.push_back(make_pair(touch[vnear],vnear));
        cout<<F.back().first<<"->"<<F.back().second<<endl;
        // e.first=c+1;
        // e.second=touch[vnear];
        // F.push_back(e);


        for(i=2; i<=n-1; i++){
            if(length[vnear]+W[vnear][i]<length[i]){
                length[i]=length[vnear]+W[vnear][i];
                touch[i]=vnear;
            }
        }
        length[vnear]=-1;
    }

    cout<<"final touch & lenght"<<endl;
    for(int i=2; i<=n-1; i++){
        cout<<touch[i]<<" ";
    }
    cout<<endl;

    for(int i=2; i<=n-1; i++){
        cout<<length[i]<<" ";
    }
    cout<<endl;
}

int main(void){
    // int V,E;
    // cout<<"Vertex : ";
    // cin>>V;
    // cout<<"Edge : ";
    // cin>>E;
    // for(int i=1; i<=E; i++){
    //     cout<<"Input Graph_Vertex_Vertex_Weight"<<endl;
    //     int v1, v2;
    //     cin>>v1>>v2v3;
    //     F.push_back(make_pair(v1,v2));
    // }


    dijkstra(N,W,F);

    for(int i=1; i<=N-2; i++){
        cout<<"test";
        //cout<<F.back().first<<"->"<<F.back().second<<endl;
    }
    cout<<endl;
}