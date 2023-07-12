#include<stdio.h>
int main()
{
int i,j,n,a[50],frame[10],no,k,avail,count=0;
float rate;
            printf("\n ENTER THE NUMBER OF PAGES:\n");
scanf("%d",&n);
            printf("\n ENTER THE PAGE NUMBER :\n");
            for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
            printf("\n ENTER THE NUMBER OF FRAMES :");
            scanf("%d",&no);
for(i=0;i<no;i++)
            frame[i]= -1;
                        j=0;
                        printf("\tref string\t page frames\n");
for(i=1;i<=n;i++)
                        {
                                    printf("%d\t\t",a[i]);
                                    avail=0;
                                    for(k=0;k<no;k++)

                        if(frame[k]==a[i])
                                                avail=1;

                        if (avail==0)
                                    {
                                                frame[j]=a[i];
                                                j=(j+1)%no;
                                                count++;
                                                for(k=0;k<no;k++)
                                                printf("%d\t",frame[k]);
                                    }
                                    printf("\n");

}
                        rate = (float)count/(float)n;
                        printf("Page Fault Is %d",count);
                        printf("\nPage Fault Rate: %f",rate);
                        return 0;
}

/*

 ENTER THE NUMBER OF PAGES:
12

 ENTER THE PAGE NUMBER :
0 2 1 6 4 0 1 0 3 1 2 1

 ENTER THE NUMBER OF FRAMES :3
        ref string       page frames
0               0       -1      -1
2               0       2       -1
1               0       2       1
6               6       2       1
4               6       4       1
0               6       4       0
1               1       4       0
0
3               1       3       0
1
2               1       3       2
1
Page Fault Is 9
Page Fault Rate: 0.750000
Process returned 0 (0x0)   execution time : 17.650 s
*/
