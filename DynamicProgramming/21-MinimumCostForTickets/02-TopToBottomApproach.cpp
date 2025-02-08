/*
Platform: Code360
Problem Link: https://www.naukri.com/code360/problems/minimum-coins_2180776?leftPanelTab=0&leftPanelTabValue=PROBLEM
Problem statement:
Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 365
1 <= DAYS[i] <= 365

Time Limit: 1 sec
*/

/*
Complexities ->
Time Complexity -> O(n).
Space Complexity -> O(n).
*/

int calculateMinimumCoins(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dynamicArray) {

    //Base case
    if(index>=n) {
        return 0;
    }

    //Step-2
    if(dynamicArray[index]!=-1) {
        return dynamicArray[index];
    }

    //Step-3
    //1-day pass
    int opt1 = cost[0]+calculateMinimumCoins(n, days, cost, index+1, dynamicArray);

    //7-day pass
    int i;
    for(i=index; i<n && days[i]<days[index]+7;i++);
    int opt2 = cost[1]+calculateMinimumCoins(n, days, cost, i, dynamicArray);

    //30-day pass
    for(int i=index; i<n && days[i]<days[index] + 30;i++);
    int opt3 = cost[2]+calculateMinimumCoins(n, days, cost, i, dynamicArray);

    dynamicArray[index] = min(opt1, min(opt2, opt3));

    return dynamicArray[index];

}

int minimumCoins(int n, vector<int> days, vector<int> cost) {
    vector<int> dynamicArray(n+1, -1); 
    return calculateMinimumCoins(n, days, cost, 0, dynamicArray);

}
