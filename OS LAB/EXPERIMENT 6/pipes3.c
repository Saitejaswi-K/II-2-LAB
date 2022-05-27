#include <stdio.h>
#include<unistd.h>
 
int main() {
   int fd1[2], fd2[2], status1, status2, id, i;
   char names[2][20], r_mess[20];
   for(i=0; i<2; i++){
	   printf("Message %d:", i+1);
	   scanf("%s",names[i]);
  }
   status1 = pipe(fd1);
   if (status1 == -1) {
      printf("Unable to create pipe 1 \n");
      return 1;
   }
   status2 = pipe(fd2);
   if (status2 == -1) {
      printf("Unable to create pipe 2 \n");
      return 1;
   }
   id = fork();
   if (id != 0){
      close(fd1[0]); 
      close(fd2[1]); 
      printf("In Parent: Writing to pipe1 – %s\n", names[0]);
      write(fd1[1], names[0], sizeof(names[0]));
      read(fd2[0], r_mess, sizeof(r_mess));
      printf("In Parent: Reading from pipe 2 - %s\n", r_mess);
   } 
   else { 
      close(fd1[1]); 
      close(fd2[0]); 
      read(fd1[0], r_mess, sizeof(r_mess));
      printf("In Child: Reading from pipe 1 –  %s\n", r_mess);
      printf("In Child: Writing to pipe 2 – %s\n", names[1]);
      write(fd2[1], names[1], sizeof(names[1]));
   }
   return 0;
}

