/*
Platform -> Code360
Playlist -> https://www.naukri.com/code360/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
Problem Statement: 
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3

Time Limit: 1 second
Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13
*/

/* Complexities -> 
Time Complexity -> 
Space Complexity -> 
*/


#include <bits/stdc++.h> 

int solve (vector<int> weight, vector<int> value, int index, int capacity){
	//Base case 
	//If only 1 item to steal, then just compare its weight with knapsack capacity

	if(index==0) {
		if(weight[0] <= capacity) {
			return value[0];
		} else {
			return 0;
		}
	}

	int include=0;
	if(weight[index]<=capacity) {
		include = value[index] + solve(weight, value, index-1, capacity-weight[index]);
	} 
	int exclude = 0+solve(weight, value,index-1, capacity);
	int ans = max(include, exclude);
	return ans;
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return solve(weight, value, n-1, maxWeight);
	
}