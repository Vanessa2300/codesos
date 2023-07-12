#include <stdio.h>
void firstFit(int blockSize[], int m, int processSize[], int n){
     int i,j,allocation[n];

     for (i = 0; i < n; i++){
             allocation[i] = -1;
     }
         for (i = 0; i < n; i++){
             for (j = 0; j < m; j++){
                 if (blockSize[j] >= processSize[i]){
                     allocation[i] = j;
                     blockSize[j] -= processSize[i];
                     break;
                 }
             }
         }

     printf("\nProcess No.\tProcess Size\tBlock No.\n");

         for (i = 0; i < n; i++)
        {
             printf("%d\t\t%d\t\t", i + 1, processSize[i]);
                 if (allocation[i] != -1)
                    printf("%d\n", allocation[i] + 1);
                 else
                    printf("Not Allocated\n");
         }
    }
    int main(){
         int m, n,i;
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

         firstFit(blockSize, m, processSize, n);
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
1               212             2
2               417             5
3               112             2
4               426             Not Allocated
*/
