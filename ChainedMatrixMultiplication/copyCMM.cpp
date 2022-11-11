#include<iostream>
 
using namespace std;
 
#define MIN(A, B) ((A)>(B)?(B):(A))
#define MAX_VALUE 9999999
#define MAX_SIZE 101
 
int M[MAX_SIZE][MAX_SIZE];
int d[MAX_SIZE];
int P[5][6]={0,};

void order(int i, int j){
    if(i==j){
        cout<<"A"<<i;
    }
    else{
        int k=P[i][j];
        cout<<"(";
        order(i,k);
        order(k+1,j);
        cout<<")";
    }
}
 
int main()
{
    int size = 6;
 
    d[0]=5; d[1]=2; d[2]=3; d[3]=4; d[4]=6; d[5]=7; d[6]=8;
 
    for (int diagonal = 1; diagonal < size; diagonal++)
    {
        for (int i = 1; i <= size - diagonal; i++)
        {
            int j = i + diagonal;
            if (j == i)
            {
                M[i][j] = 0;
                continue;
            }
            M[i][j] = MAX_VALUE;
            for (int k = i; k <= j - 1; k++){
                M[i][j] = MIN(M[i][j], M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]);
                P[i][j] = k;
            }
 
        }
    }
 
    /*결과 출력*/
    cout << M[1][size] << endl;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    order(2,6);
    return 0;
}