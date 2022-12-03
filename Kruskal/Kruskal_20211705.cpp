#include <iostream>
#include <vector>
#include <tuple>

#define inf 99999
#define N 5

using namespace std;
vector<tuple<int, int, int>> E;
vector<tuple<int, int, int>> F;

typedef int index;
typedef index set_pointer;
struct nodetype{
    index parent;
    int depth;
};
typedef nodetype universe[N]; 
universe U;
void makeset(index i){
    U[i].parent=i;
    U[i].depth=0;
}
set_pointer find(index i){
    index j;
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
    index i;
    for(i=1; i<=n; i++)
        makeset(i);
}

void kruskal(int n, int m, vector<tuple<int, int, int>> E, vector<tuple<int, int, int>> F){
    index i, j;
    set_pointer p,q;
    int k=0;
    tuple<int,int,int> e;
    initial(n);

    while(F.size()<n-1){
        e=E[k];
        i=get<0>(e);
        j=get<1>(e);
        p=find(i);
        q=find(j);
        if(!equal(p,q)){
            merge(p,q);
            F.push_back(e);
            
        }        

        k++;
    }
    cout<<"Array F"<<endl;
    for(int i=0; i<F.size(); i++){
        cout<<get<0>(F[i])<<" -> "<< get<1>(F[i])<<"\t"<< get<2>(F[i]) << endl;
    } 
}

int main(void){
    //교재 입력데이터
    // E.push_back(make_tuple(1,2,1));
    // E.push_back(make_tuple(3,5,2));
    // E.push_back(make_tuple(1,3,3));
    // E.push_back(make_tuple(2,3,3));
    // E.push_back(make_tuple(3,4,4));
    // E.push_back(make_tuple(4,5,5));
    // E.push_back(make_tuple(2,4,6));

    //자작 입력데이터
    E.push_back(make_tuple(1,2,1));
    E.push_back(make_tuple(1,3,2));
    E.push_back(make_tuple(2,4,3));
    E.push_back(make_tuple(3,5,3));
    E.push_back(make_tuple(1,4,4));
    E.push_back(make_tuple(4,5,5));
    E.push_back(make_tuple(3,4,6));
    kruskal(N,7,E,F);
    return 0;
}