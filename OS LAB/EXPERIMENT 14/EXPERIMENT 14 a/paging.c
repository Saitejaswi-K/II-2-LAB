#include<stdio.h> 
#include<conio.h> 
#include<math.h> 
int main() { 
    int size,m,n,pgno,pagetable[3]={8,9,10},i,j,frameno, ra=0,ofs; 
    double m1; 
    printf("Enter process size:");
    scanf("%d",&size); 
    m1=size/4; 
    n=ceil(m1); 
    printf("Total No. of pages: %d", n); 
    printf("\nEnter relative address \n"); 
    pgno=ra/1000;
    ofs=ra%1000; 
    printf("page no=%d\n",pgno); 
    printf("page table\n"); 
    for(i=0;i<n;i++){
        printf("%d [%d]\n",i,pagetable[i]); 
        frameno=pagetable[pgno]; 
        printf("Equivalent physical address : %d%d\n",frameno,ofs); 
    }
    getch(); 
}
