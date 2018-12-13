#include<stdio.h>

int main(){
    int incoming, outgoing, buck_size, n, store = 0;
    printf("Enter bucket size, outgoing rate and no of inputs: ");
    scanf("%d %d %d", &buck_size, &outgoing, &n);

    while (n != 0) {
        printf("Enter the incoming packet size : ");
        scanf("%d", &incoming);
        printf("Incoming packet size %d\n", incoming);
	
        if (incoming <= (buck_size)){
            store += incoming;
            printf("Bucket buffer size %d out of %d\n", store, buck_size);
        } else {
            printf("Dropped as size greater than that of bucket %d",buck_size);
           
            store = 0;
        }
store = store - outgoing;
	while(store>0)
{
        
        printf("After outgoing %d,%d packets left out of %d\n",outgoing, store, incoming);
store = store - outgoing;}
store=store+outgoing;
if(store !=0)
{
printf("After outgoing %d,%d packets left out of %d\n", store,0, incoming);
store=0;
}
printf("now remaining: %d",store);
        n--;
    }
}
