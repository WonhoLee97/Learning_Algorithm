#include <iostream>
#include <vector>

#define N 4
#define W 16

using namespace std;

double maxprofit = 0.0;
int p[N+1] = {0, 40, 30, 50, 10};
int w[N+1] = {0, 2, 5, 10, 5};

vector<string> bestset(N+1);
vector<string> include(N+1);

bool promising(int i, int profit, int weight){
	int j, k;
	int totweight;
	double bound;

	if (weight >= W) return false;

	else {
		j = i+1;
		bound = profit;
		totweight = weight;

		while ((j <= N) && (totweight + w[j] <= W)){
			totweight = totweight + w[j];
			bound = bound + p[j];
			j++;
		}

		k = j;

		if (k <= N){
			bound = bound + (W-totweight)*p[k]/w[k];
		}
		return bound > maxprofit;
	}
}

void knapsack(int i, int profit, int weight){
	if ((weight <= W) && (profit > maxprofit)){
		maxprofit = profit;
		copy(include.begin(), include.end(), bestset.begin());
		// bestset.insert(bestset.begin(), include.begin(), include.end());
	}

	if (promising(i, profit, weight)){
		include[i+1] = "true";
		knapsack(i+1, profit+p[i+1], weight+w[i+1]);
		include[i+1] = "false";
		knapsack(i+1, profit, weight);
	}
}


int main (int argc, char* argv[]){
	// p = {100, 37, 35, 33};
	// w = {25, 10, 10, 10};

	knapsack(0, 0, 0);

	cout << "maxprofit is : " << maxprofit << endl;
	for (int i=0; i<N; i++){
		cout << "\t" << i+1 << " :\t" << bestset[i+1] << endl;
	}

	return 0;
}