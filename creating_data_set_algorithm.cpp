#include <bits/stdc++.h>
using namespace std;
	void generateProblem(int n, int P){
 
		//knapsack capacity is a function of n
    cout<<n<<endl;
		int B = P*n/2;
     cout<<B<<endl;
 
		//sizes distributed between 20 and 400
		int s[n];
		for(int i=0; i<n; i++){
			s[i] = (int) (((float(rand())/RAND_MAX)*P) + 20);
            cout<<s[i]<<" ";
    }
    cout<<endl;
		//profits will be somewhat correlated with sizes
		int p[n];
		for(int i=0; i<n; i++){
			p[i] = (int) (10 + (((float(rand())/RAND_MAX)*P*s[i])/400));
             cout<<p[i]<<" ";
    }
    cout<<endl;
   
	}//end method

int main()
{
    int t;
    cin>>t;
    while(t--){
    int a,b;
    cin>>a>>b;
  generateProblem(a,b);
  cout<<endl;
    }

    return 0;
}