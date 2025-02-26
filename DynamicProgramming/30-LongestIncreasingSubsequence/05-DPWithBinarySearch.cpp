/*
Platform: gfg
Problem Link: https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
Problam Statement:
Given an array arr[] of integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).

A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

Examples:

Input: arr[] = [5, 8, 3, 7, 9, 1]
Output: 3
Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.
Input: arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output: 6
Explanation: One of the possible longest strictly increasing subsequences is [0, 2, 6, 9, 13, 15], which has a length of 6.
Input: arr[] = [3, 10, 2, 1, 20]
Output: 3
Explanation: The longest strictly increasing subsequence could be [3, 10, 20], which has a length of 3.
Constraints:
1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 106
*/

/*
Time complexity -> O(nlog n)
Space complexity -> O(n)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public: 
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n==0) {
            return 0;
        } 
        
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1; i<n; i++) {
            if(arr[i]>ans.back()) {
                ans.push_back(arr[i]);
            } else {
                //find index of just largest elements in ans
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index]=arr[i];
            }
        } 
        return ans.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends