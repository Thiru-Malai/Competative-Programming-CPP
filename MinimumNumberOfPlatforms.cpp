// CODING NINJAS
// https://www.codingninjas.com/studio/problems/799400?topList=striver-sde-sheet-problems&leftPanelTab=1

// Problem Statement: We are given two arrays that represent the arrival and departure times of trains that stop at the platform. 
// We need to find the minimum number of platforms needed at the railway station so that no train has to wait.

// Examples 1:

// Input: N=6, 
// arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00} 
// dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}

// Output:3
// Explanation: There are at-most three trains at a time. 
// The train at 11:00 arrived but the trains which had arrived at 9:45 and 9:55 have still not departed. So, we need at least three platforms here.

#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    sort(at, at + n);
    sort(dt, dt + n);
    int i = 1, j = 0;
    int platform = 1, result = 1;
    while (i < n && j < n)
    {
        if (at[i] > dt[j])
        {
            platform--;
            j++;
        }
        else if (at[i] <= dt[j])
        {
            platform++;
            i++;
        }
        if (platform > result)
        {
            result = platform;
        }
    }
    return result;
}

int main()
{
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(dep) / sizeof(dep[0]);
    cout << "Minimum number of Platforms required " << calculateMinPatforms(arr, dep, n) << endl;
}