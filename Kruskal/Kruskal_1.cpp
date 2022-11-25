#include <iostream>
#include <vector>

#define inf
#define N 6

using namespace std;
vector<pair<int, int>> E;
vector<pair<int, int>> F;

// int W[N][N]={ //자작 데이터
//     {0, 0, 0, 0, 0, 0},
//     {0, 0, 1, 7, 4, 5},
//     {0, inf, 0, 1, inf, 3},
//     {0, inf, inf, 0, 1, inf},
//     {0, inf, inf, inf, 0, inf},
//     {0, inf, inf, inf, 1, 0}
// };

typedef int set_pointer;
struct nodetype{
    int parent;
    int depth;
};
typedef nodetype universe[N]; 
universe U;
void makeset(int i){
    U[i].parent=i;
    U[i].depth=0;
}
set_pointer find(int i){
    int j;
    j=i;
    while(U[j].parent!=j)
        j=U[j].parent;
    return j;
}
void merge(set_pointer p, set_pointer q){
    if(U[p].depth==U[q].depth){
        U[p].depth=+1;
        U[q].parent=p;
    }
    else if(U[p].depth<U[q].depth)
        U[p].parent=q;
    else
        U[q].parent=p;
}
bool equal(set_pointer p, set_pointer q){
    if(p==q)
        return true;
    else
        return false;
}
void initial(int n){
    int i;
    for(i=1; i<=n; i++)
        makeset(i);
}

void kruskal(int n, int m, vector<pair<int, int>> E, vector<pair<int, int>> F){
    int i, j;
    set_pointer p,q;
    pair<int,int> e;
    initial(n);
    while(n-1){
        e=make_pair(2,2);
        // i,j=
        p=find(i);
        q=find(j);
        if(!equal(p,q)){
            merge(p,q);
            F.push_back(e);
        }
    }
}

int main(void){
    kruskal(N,3,E,F);
}