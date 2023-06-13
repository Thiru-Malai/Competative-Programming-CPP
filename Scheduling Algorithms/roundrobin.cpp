// Round Robin
// is a CPU Scheduling algorithm where each process is assigned a fixed time slice / quantum in a cyclic manner.
// You are given time slice / quantum and a list of processes where 'PROCESS[ i ]' denotes the Burst time of the process 
// 'i'. Your task is to perform Round Robin scheduling and print a list of Waiting time where (i)th index of your 
// list denotes the waiting time for 'PROCESS[ i ]'.


#include <bits/stdc++.h> 
vector<int> roundRobin(vector<int> &process, int n, int quantum)
{
	int time = 0;
	vector<int> waitTime(n, 0);
	vector<int> burstTime(process.begin(), process.end());
	int i = 0, flag = 1;
	while(flag){
		flag = 0;
		for(i = 0; i < n; i++){
			// cout<<process[i]<<" ";
			if(process[i] >= quantum){
				process[i]-=quantum;
				time+=quantum;
			}
			else if(process[i] < quantum && process[i] > 0){
				time+=process[i];
				process[i] = 0;
			}
			if(process[i] != -1){
				flag = 1; 
			}
			if(process[i] == 0){
				waitTime[i] = (time - burstTime[i]);
				process[i] = -1;
			}
		}
	}
	return waitTime;
}
