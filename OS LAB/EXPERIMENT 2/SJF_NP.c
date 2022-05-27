#include <stdio.h>
int main(){
	int n, i, j;
	printf("Enter no.of processors:\n");
	scanf("%d", &n);
	int at[n], bt[n], wt[n], tat[n], temp, p[n];
	float WT=0, TAT=0;
	printf("Enter the processors no:\n");
	for(i=0; i<n; i++){
		scanf("%d", &p[i]);
	}
	printf("Enter burst time of each processor:\n");
	for(i=0; i<n; i++){
		scanf("%d", &bt[i]);
	}
	printf("processors|Burst time\n");
	for(i=0; i<n; i++){
		printf("%d\t\t%d\n",p[i], bt[i]);
	}
	
	for(i=0; i<n-1; i++){
		for(j=1; j<n-i-1; j++){
			if(bt[j] > bt[j+1]){
				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	wt[0] = 0;
	for(i=0; i<n; i++){
		tat[i] = wt[i] + bt[i];
		wt[i+1] = tat[i];
		WT += wt[i];
		TAT += tat[i-1];
	}
	printf("processors|Burst time|Waiting time|Turn around time\n");
	for(i=0; i<n; i++){
		printf(" %d\t\t%d\t\t%d\t\t%d\n",p[i], bt[i], wt[i], tat[i]);
	}
	printf("Average waiting time = %f\nAverage turn around time = %f\n", WT/n,TAT/n);
}
