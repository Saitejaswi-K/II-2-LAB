#include <stdio.h>
int main(){
	int n;
	printf("Enter No.of cases: ");
	scanf("%d", &n);
	int processors[n], bt[n], tat[n], wt[n], i;
	float Atat=0, Awat=0;
	printf("Enter no.of processors in each case: ");
	for(i=0; i<n; i++){
		scanf("%d", &processors[i]);
	}
	printf("Enter burst time in each case: ");
	for(i=0; i<n; i++){
		scanf("%d", &bt[i]);
	}
	wt[0] = 0;
	for(i=0; i<n; i++){
		tat[i] = wt[i] + bt[i];
		wt[i+1] = tat[i];
	}
	printf("Processor | Burst time | Waiting time | Turn around time\n");
	for(i=0; i<n; i++){
		Atat += tat[i];
		Awat += wt[i];
		printf(" \%d\t\t%d\t\t%d\t\t%d\n", processors[i], bt[i], wt[i], tat[i]);
	}
	printf("Average Waiting time = %f\nAverage Turn around time = %f\n", Awat/n, Atat/n);
}
