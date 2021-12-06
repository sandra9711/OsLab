#include <stdio.h>
#include <stdlib.h>


void bestFit(int blockSize[], int m, int processSize[], int n) 
    {
        // Stores block id of the block allocated to a process
        int allocation[n];
        int i,j;
       
        // Initially no block is assigned to any process
        for (int i = 0; i < n; i++)
            allocation[i] = -1;
       
     // pick each process and find suitable blocks according to its size ad assign to it
        for (i=0; i<n; i++)
        {
            // Find the best fit block for current process
            int bestIdx = -1;
            for (j=0; j<m; j++)
            {
                if (blockSize[j] >= processSize[i])
                {
                    if (bestIdx == -1)
                        bestIdx = j;
                    else if (blockSize[bestIdx] > blockSize[j])
                        bestIdx = j;
                }
            }
       
            // If we could find a block for current process
            if (bestIdx != -1)
            {
                // allocate block j to p[i] process
                allocation[i] = bestIdx;
       
                // Reduce available memory in this block.
                blockSize[bestIdx] -= processSize[i];
            }
        }
       
       printf("\nProcess No.\tProcess Size\tBlock no.");
        for (int i = 0; i < n; i++)
        {
           printf("%d %d \t" ,(i+1) ,processSize[i]);
            if (allocation[i] != -1)
               printf(allocation[i] + 1);
            else
               printf("Not Allocated");
           printf("\n");
        }
    }

    int main(){
      int n,m,i;
      int proc[n],holes[m];
      printf("Enter number of holes");
      scanf("%d",&m);
      printf("Enter holes sizes");
      for(i=0;i<m;i++){
        scanf("%d",&holes[i]);
      }
      printf("Enter number of processes");
      scanf("%d",&n);
      printf("Enter process sizes");
      for(i=0;i<n;i++){
        scanf("%d",&proc[i]);
      }
      bestFit(holes[],m,proc[],n);
      return 0;
    }