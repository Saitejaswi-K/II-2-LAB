#include <stdio.h>

int main(){
    int base[1000], limit[1000], seg, ans, offset;
    printf("Enter segment table: \n");
    printf("Enter -1 for termination: \n");
    do{
        printf("Enter segment number: ");
        scanf("%d", &seg);
        if(seg != -1){
            printf("Enter base address value: ");
            scanf("%d", &base[seg-1]);
            printf("Enter limit of segment: ");
            scanf("%d", &limit[seg-1]);
        }
    }while(seg != -1);
    printf("Enter segment number");
    scanf("%d", &seg);
    printf("Enter offset: ");
    scanf("%d", &offset);
    if(offset < limit[seg-1]){
        printf("address in Physical memory %d: ", offset+base[seg-1]);
    }
    else{
        printf("Error");
    }
  return 0;
}
