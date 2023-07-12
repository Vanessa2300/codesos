//LRU PAGE REPLACEMENT ALGORITHM
#include<stdio.h>
#include<conio.h>
int main()
{
        int i, j , k, min, rs[25], m[10], count[10], flag[25], n, f, pf=0, next=1;
        float rate;
        printf("Enter the length of reference string -- ");
        scanf("%d",&n);
        printf("Enter the reference string -- ");
             for(i=0;i<n;i++){
                    scanf("%d",&rs[i]);
                    flag[i]=0;
            }
        printf("Enter the number of frames -- ");
        scanf("%d",&f);

        for(i=0;i<f;i++){
            count[i]=0;
            m[i]=-1;
        }
        printf("\nThe Page Replacement process is -- \n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<f;j++){
                if(m[j]==rs[i]){
                    flag[i]=1;
                    count[j]=next;
                    next++;
                }
            }

            if(flag[i]==0){

                if(i<f){
                    m[i]=rs[i];
                    count[i]=next;
                    next++;
                }
                else{
                    min=0;
                    for(j=1;j<f;j++)
                    if(count[min] > count[j])
                        min=j;

                    m[min]=rs[i];
                    count[min]=next;
                    next++;


                }
                    pf++;
            }

            for(j=0;j<f;j++)
                printf("%d\t", m[j]);
            if(flag[i]==0)
                printf("PF No. -- %d" , pf);
                printf("\n");
        }
        rate = (float)pf/(float)n;
        printf("\nThe number of page faults using LRU are %d",pf);
        printf("\nPage Fault Rate: %f",rate);
       return 0;
}
/*
Enter the length of reference string -- 12
Enter the reference string -- 0 2 1 6 4 0 1 0 3 1 2 1
Enter the number of frames -- 3

The Page Replacement process is --
0       -1      -1      PF No. -- 1
0       2       -1      PF No. -- 2
0       2       1       PF No. -- 3
6       2       1       PF No. -- 4
6       4       1       PF No. -- 5
6       4       0       PF No. -- 6
1       4       0       PF No. -- 7
1       4       0
1       3       0       PF No. -- 8
1       3       0
1       3       2       PF No. -- 9
1       3       2

The number of page faults using LRU are 9
Page Fault Rate: 0.750000
Process returned 0 (0x0)   execution time : 7.943 s
*/
