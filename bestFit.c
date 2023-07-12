#include <stdio.h>
void bestFit(int blockSize[], int m, int processSize[], int n)
{
     int i,j,allocation[n];
     for (i = 0; i < n; i++){
        allocation[i] = -1;
     }

     for (i = 0; i < n; i++)
    {
         int bestIndex = -1;
         for (j = 0; j < m; j++)
        {
             if (blockSize[j] >= processSize[i]){
                 if (bestIndex == -1 || blockSize[j] < blockSize[bestIndex]){
                     bestIndex = j;
                 }
             }
         }
         if (bestIndex != -1){
             allocation[i] = bestIndex;
             blockSize[bestIndex] -= processSize[i];
         }
     }

     printf("\nProcess No.\tProcess Size\tBlock No.\n");
     for (i = 0; i < n; i++){
         printf("%d\t\t%d\t\t", i + 1, processSize[i]);
             if (allocation[i] != -1)
                printf("%d\n", allocation[i] + 1);
             else
                printf("Not Allocated\n");
     }
}

int main()
{
     int i,m, n;
         printf("Enter the no. of memory blocks: ");
         scanf("%d", &m);
     int blockSize[m];
        printf("-----Enter the sizes of memory blocks-----\n");

         for (i = 0; i < m; i++){
             printf("Block %d: ", i + 1);
             scanf("%d", &blockSize[i]);
         }
         printf("Enter the no. of processes: ");
         scanf("%d", &n);
     int processSize[n];
        printf("-----Enter the sizes of processes-----\n");

         for (i = 0; i < n; i++){
             printf("Process %d: ", i + 1);
             scanf("%d", &processSize[i]);
         }

     bestFit(blockSize, m, processSize, n);
     return 0;
}
/*
Enter the no. of memory blocks: 5
-----Enter the sizes of memory blocks-----
Block 1: 100
Block 2: 500
Block 3: 200
Block 4: 300
Block 5: 600
Enter the no. of processes: 4
-----Enter the sizes of processes-----
Process 1: 212
Process 2: 417
Process 3: 112
Process 4: 426

Process No.     Process Size    Block No.
1               212             4
2               417             2
3               112             3
4               426             5
*/
