#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	char names[3][20], r_names[20];
	int i, fds[3], status;
	status = pipe(fds);
	if(status == -1){
		printf("Unable to create a pipe\n");
		return 1;
	}
	for(i=0; i<3; i++){
		scanf("%s", names[i]);
		printf("Writing name%d to pipe: %s\n", i+1, names[i]);
		write(fds[1], names[i], sizeof(names[i]));
		read(fds[0], r_names, sizeof(r_names));
		printf("Reading name%d to pipe: %s\n", i+1, r_names);
	}
	return 0;
}
