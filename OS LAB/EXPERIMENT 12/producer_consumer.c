#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int mutex = 1, empty = 10, x = 0, full = 1;
void producer(){
	--mutex;
	--empty;
	++full;
	x++;
	printf("Producer produces item %d\n", x);
	++mutex;
}
void consumer(){
	--mutex;
	++empty;
	--full;
	printf("Consumer consumes item %d\n", x);
	x--;
	++mutex;
}
int main(){
	int n, i;
	printf("1.Press 1 for producers\n2.Press 2 for consumers\nPress 3 for exit\n");
	for(i=1; i>0; i++){
		printf("Enter choice:");
		scanf("%d", &n);
		switch(n){
			case 1: if(mutex == 1 && empty != 0){
					producer();
				}
				else{
					printf("Buffer is full!\n");
				}
				break;
			case 2: if(mutex == 1 && full != 0){
					consumer();
				}
				else{
					printf("Buffer is empty!\n");
				}
				break;
			case 3: exit(0);
				break;
			
		}
		
	}
	return 0;
	
}

