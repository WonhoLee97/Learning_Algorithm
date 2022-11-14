#include <iostream>
#define inf 99999
using namespace std;
int main(void){
    int A[5][5]={1,};
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            cout<<A[i][j];
        }
        cout<<endl;
    }
}