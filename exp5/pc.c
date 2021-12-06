#include <stdio.h>
#include <stdlib.h>
#define BUFFER 10

int buffer[BUFFER];
int iN = 0;
int out = 0;
int count=0;
void producer()
{
  int next_produced=count;
  while (count==BUFFER); // do nothing
    buffer[iN] = next_produced;
    iN = (iN + 1) % BUFFER;
    count=count+1;
    printf("Produced item %d\n\n",count);
  
}
void consumer()
{
  int next_consumed=count;
  
    while (count==0); // do nothing
      next_consumed = buffer[out];
      out = (out + 1) % BUFFER;
      printf("Consumed item %d\n\n",count);    
      count=count-1;  
}

int main()
{
    int n,num;
  
    while(1) {
  
    printf("Press 1 for Producer \tPress 2 for Consumer \tPress 0 for Exit \n");
        scanf("%d", &n);

        switch (n) {
        case 1: if (count < 10){
                  producer();
        }
            else 
                printf("Buffer is full!\n\n");
            break;
  
        case 2:if(count > 0 )
                consumer();

            else 
                printf("Buffer is empty!\n\n");
            break;
  
        case 0:
            exit(0);
            break;
        }
    }
}