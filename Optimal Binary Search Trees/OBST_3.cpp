#include <iostream>
#include <algorithm> 
using namespace std;
#define INF  1000000;
int R[6][5];

void optsearchtree(int n, const float p[], float& minavg, int R[][5]) {
    int i, j = 0 , k, diagonal;

    float A[6][6];
    for (int i = 1; i <=5; i++)
    {
        for (int j = 1; j <= 5; j++)
            A[i][j] = INF;
    }

    for (i = 1; i <= n; i++)
    {
        A[i][i - 1] = 0;
        A[i][i] = p[i];
        R[i][i] = i;
        R[i][i - 1] = 0;
    }
    A[n + 1][n] = 0;
    R[n + 1][n] = 0;

    
    for (diagonal = 1; diagonal <= n - 1; diagonal++)
    {
        for (i = 1; i <= n - diagonal; i++)
        {
            j = i + diagonal;
            // A[i][j] = A[i][i-1] + A[i+1][j];
            // R[i][j] = k;
            for (k = i+1; k <= j; k++)
                if (A[i][j]>(A[i][k - 1] + A[k + 1][j]) )
                {
                    A[i][j] = (A[i][k - 1] + A[k + 1][j]);
                    R[i][j] = k;
                }
            for (int a = i; a <= j; a++) {
                A[i][j] += p[a];
            }
        }

    }
    minavg = A[1][n];
}
int main()
{
    float minavg = 0;
    float p[5] = { 0,0.375,0.375,0.125,0.125 };

    optsearchtree(4, p, minavg,R);
    cout << "Optimal : " << minavg;
    cout << endl;

}