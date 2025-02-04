/*
 * Link - https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
 * Given an array of positive integers arr[] and a value target, determine if there is a subset of the given array with sum equal to given target. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], target = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
 */

// O(2^N) time complexity and O(N) space complexity

public class RecursiveSubsetSum {
    class Solution {

        static Boolean isSubsetSum(int arr[], int target) {
            return solve(arr, arr.length - 1, target);
        }
        static Boolean solve(int[] arr, int idx, int tg){
            if ( tg == 0) return true;
            if(idx == 0)
            {
             return arr[0] == tg;
            }
            boolean notTake = solve(arr, idx - 1, tg);
            boolean take = false;
            if(tg >= arr[idx]){
                take = solve(arr, idx - 1, tg - arr[idx]);
            }
            return take || notTake;
        }
    }
}
