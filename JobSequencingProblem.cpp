// CODING NINJAS
// https://www.codingninjas.com/studio/problems/job-sequencing-problem_1169460?topList=striver-sde-sheet-problems&leftPanelTab=0

// Problem Statement: You are given a set of N jobs where each job comes with a deadline and profit. 
// The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and the maximum profit that can be obtained.
// Each job takes a single unit of time and only one job can be performed at a time.

// Example 1:

// Input: N = 4, Jobs = {(4,20),(1,10),(1,40),(1,30)}

// Output: 2 60

// Explanation: The 3rd job with a deadline 1 is performed during the first unit of time .The 1st job is performed during the second unit of time as its deadline is 4.
// Profit = 40 + 20 = 60

// Example 2:

// Input: N = 5, Jobs = {(2,100),(1,19),(2,27),(1,25),(1,15)}

// Output: 2 127

// Explanation: The  first and third job both having a deadline 2 give the highest profit. 
// Profit = 100 + 27 = 127


#include <bits/stdc++.h>
using namespace std;
bool comparator(vector<int> j1, vector<int> j2) {
  return j1[1] > j2[1] || (j1[1] == j2[1] && j1[0] >= j2[0]);
}

int jobScheduling(vector<vector<int>> &jobs) {
  int n = jobs.size();
  int maxFinishTime = INT_MIN;
  sort(jobs.begin(), jobs.end(), comparator);
  for (int i = 0; i < n; i++) {
    if (jobs[i][0] > maxFinishTime) {
      maxFinishTime = jobs[i][0];
    }
  }

  int profits[maxFinishTime + 1] = {0};

  for (int i = 0; i < n; i++) {
    int finish = jobs[i][0]; // Finish Time
    int profit = jobs[i][1]; // Profit
    for (int j = finish; j > 0; j--) {
      if (profits[j] == 0) {
        profits[j] = profit;
        break;
      }
    }
  }
  int maxProfit = 0;

  for (int i = 1; i <= maxFinishTime; i++) {
    maxProfit += profits[i];
  }
  return maxProfit;
}


int main(){
   vector<vector<int>> jobs = {{4,20},{1,10},{1,40},{1,30}};
   cout<<"Maximum Profit: "<<jobScheduling(jobs); 
}