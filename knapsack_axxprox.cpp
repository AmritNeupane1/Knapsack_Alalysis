#include <bits/stdc++.h>

using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
vector<bool> knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
      vector<vector<int>> K(n + 1, vector<int>(W + 1));
  
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + 
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int res= K[n][W];
    vector<bool>sol(n,false);
    w = W;
    for (i = n; i > 0 && res > 0; i--) {
         
        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if (res == K[i - 1][w])
            continue;   
        else {
            sol[i - 1]=1 ;
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    return sol;
}
    


int KnapsackApproximation(int W, int wt[], int val[], int n) {

		int P = 0;
		for (int i = 0; i < n; i++)
			if(val[i]>= P) P = val[i];
 
		//calculate scaling factor K
        float e=0.5;
		double K = (e * P) / n;
		// if(K < 1){
		// 	cout<<"Scaling factor K is too small: K=" <<K<< ". Need K > 1.";
		// 	return 0;
		// }
 
		//scale down profits
		int p_scaled[n];
		for(int i=0; i<n; i++)
			p_scaled[i] = (int) (val[i] / K);
 
		//solve scaled problem
		vector<bool>solution= knapSack(W, wt, p_scaled, n);
		int Z = 0;
		for(int i=0; i<n; i++)
			if(solution[i]) Z = Z + val[i];

        return Z;
 
	}//end method solve()

int main()
{
    clock_t start = clock();
	int n;
	cin>>n;
	int W;
	cin>>W;

	int wt[n];
    int val[n];
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
    
	cout << "Maximum value we can obtain = "
		<< KnapsackApproximation(W, wt, val, n);
    clock_t end = clock();
	double t = (double)(end-start)/CLOCKS_PER_SEC;
	printf("\nCompletion time: %fs.\n",t);
	return 0;
}