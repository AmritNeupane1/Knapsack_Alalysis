// C/C++ program to solve fractional Knapsack Problem
#include <bits/stdc++.h>

using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
struct Item
{
	int weight;
	int value;
};

// Comparison function to sort Item according to val/weight
// ratio
bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int n)
{
	// sorting Item on basis of ratio
	sort(arr, arr + n, cmp);

	// Uncomment to see new order of Items with their
	// ratio
	/*
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].value << " " << arr[i].weight << " :
	"
			<< ((double)arr[i].value / arr[i].weight) <<
	endl;
	}
	*/

	int curWeight = 0; // Current weight in knapsack
	double finalvalue = 0.0; // Result (value in Knapsack)

	// Looping through all Items
	for (int i = 0; i < n; i++) {
		// If adding Item won't overflow, add it completely
		if (curWeight + arr[i].weight <= W) {
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		}

		// If we can't add current Item, add fractional part
		// of it
	}

	// Returning final value
	return finalvalue;
}

// Driver code
int main()
{
     clock_t start = clock();
	int n;
	cin>>n;
	int W;
	cin>>W;

	Item arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].weight;
	}
	for(int i=0;i<n;i++){
		cin>>arr[i].value;
	}
	cout << "Maximum value we can obtain = "
		<< fractionalKnapsack(W, arr, n);
          clock_t end = clock();
	double t = (double)(end-start)/CLOCKS_PER_SEC;
	printf("\nCompletion time: %fs.\n",t);
	return 0;
}
