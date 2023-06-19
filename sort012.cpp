// CODING NINJAS
// Problem Statement: Given an array consisting of only 0s, 1s, and 2s.
// Write a program to in-place sort the array without using inbuilt sort functions. 
// ( Expected: Single pass-O(N) and constant space)

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int x = 0, y = 0, z = 0;
   for(int i = 0; i < n; i++){
      if(arr[i] == 0){
         x++;
      }
      else if(arr[i] == 1){
         y++;
      }
      else{
         z++;
      }
   }
   int i = 0;
   while(x--){
      arr[i++] = 0;
   }
   while(y--){
      arr[i++] = 1;
   }
   while(z--){
      arr[i++] = 2;
   }
}