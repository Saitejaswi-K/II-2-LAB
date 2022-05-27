#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	int i, status, fds[2], id;
	char name[3][20], r_name[20];
	status = pipe(fds);
	if(status == -1){
		printf("Unable to create a pipe\n");
		return 1;
	}
	for(i=0; i<3; i++){
		scanf("%s", name[i]);
	}
	id = fork();
	if(id==0){
		read(fds[0], r_name, sizeof(r_name));
		printf("Reading name1 from pipe: %s\n",r_name);
		read(fds[0], r_name, sizeof(r_name));
		printf("Reading name2 from pipe: %s\n", r_name);
		read(fds[0], r_name, sizeof(r_name));
		printf("Reading name3 from pipe: %s\n", r_name);
	}
	else{
		printf("Writing name1 to pipe: %s\n", name[0]);
		write(fds[1], name[0], sizeof(name[0]));
		printf("Writing name2 to pipe: %s\n", name[1]);
		write(fds[1], name[1], sizeof(name[1]));
		printf("Writing name3 to pipe: %s\n", name[2]);
		write(fds[1], name[2], sizeof(name[2]));
	}


	return 0;
}
