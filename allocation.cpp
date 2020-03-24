#include<bits/stdc++.h>
using namespace std;


/*THIS IS A RECURSIVE FUNCTION DESIGNED TO COUNT THE
NUMBER OF HOUSES THE USER CAN PURCHASE IN THE GIVEN BUDGET*/

int allocate(int budget, int n, vector <int> &cost, int counter)
{
    /*BASE CONDITION*/
    /*EITHER NO MONEY IS LEFT WITH THE BUYER OR IF THE COST OF THE HOUSE
    EXCEEDS THE CURRENT BUDGET (INITIAL OR AFTER PURCHASING CERTAIN HOUSES) */

    if(budget==0 || cost.at(n-1)>budget)
    return counter;

    /*IF THE COST OF A HOUSE LIES WITHIN THE BUDGET*/

    if(cost[n-1]<=budget)
    {
        counter++;
        allocate(budget-cost[n-1],n-1,cost,counter); /* WHY (N-1) ? */
    }
}


/*DRIVER PROGRAM*/
int main()
{
	int t=0;
	cin>>t;
	while(t--)
	{
	    /*INITIALIZING VARIABLES REQUIRED*/

	    int b,n,m;

	    /*INTEGER VECTOR TO STORE THE COST OF EACH HOUSE*/

	    vector <int> a;

	    /*TAKING THE NUMBER OF HOUSES AND BUDGET AS INPUT*/

	    cin>>n>>b;

	    /*RECEIVING THE USER INPUT AS THE COST OF EACH HOUSE*/

	    for(int i=0;i<n;i++)
	    {
	        cin>>m;
	        a.push_back(m);
	    }

	    /*SORTING THE COST OF HOUSES IN DESCENDING ORDER*/

	    sort(a.begin(), a.end(), greater<int>());

            /*FUNCTION TO COUNT THE NUMBER OF HOUSES THE USER CAN PURCHASE IN THE GIVEN BUDGET*/

	    cout << allocate(b,n,a,0)  << endl;

	    /*INITIALLY THE COUNTER WILL BE ZERO HENCE THE FOURTH ARGUMENT IS PASSED ZERO*/
	}

	return 0;
}

