/*
Platform : Leetcode
Problem Link: https://leetcode.com/problems/minimum-sideway-jumps/description/
Problem Statement : 
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.

*/

/*
Time Complexity -> O(n^2).
Space Complexity -> O(n).
*/
class Solution {
    public:
        int calculateMinSideJumps(vector<int>& obstacles, int currentLane, int currentPosition) {
            //Base case
            int n = obstacles.size()-1;//as obstacles+1 is the length
            if(currentPosition == n) {
                return 0;
            } 
    
            if(obstacles[currentPosition+1] != currentLane) {
                return calculateMinSideJumps(obstacles, currentLane, currentPosition+1);
            } else {
                //sideways jump
                int ans = INT_MAX;
                for(int i=1; i<=3; i++) {
                    if((currentLane != i) && (obstacles[currentPosition] != i)) {
                        ans = min(ans, 1+calculateMinSideJumps(obstacles, i, currentPosition));
                    }
                } 
                return ans;
            } 
            
        } 
        int minSideJumps(vector<int>& obstacles) {
            return calculateMinSideJumps(obstacles, 2, 0); //As given question, frog is starting from middle lane and first position.
        }
    };