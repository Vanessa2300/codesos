#include<stdio.h>
#include<string.h>
struct process
{
    char pnm[10];
    int alloc[10],max[10],need[10];
}p[10];

    int i=0,j=0,s=0,m,n,avail[10];
    char finish[10],safe_seq[10][10];

void accept()
    {
        printf("Enter the available Resources \n");
        for(i=0;i<m;i++)
        {
            scanf("%d",&avail[i]);
        }

        for(i=0;i<n;i++)
        {
            printf("\nEnter process name\n");
            scanf("%s",p[i].pnm);
                for(j=0;j<m;j++)
                 {
                    printf("Enter allocation \n");
                    scanf("%d",&p[i].alloc[j]);
                }
                for(j=0;j<m;j++)
                {
                    printf("Enter Max \n");
                    scanf("%d",&p[i].max[j]);
                }
        }
    }
void need()
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                p[i].need[j]=p[i].max[j]-p[i].alloc[j];
            }
        }
    }
void display()
    {
        printf("************************\nAvailable Resources \n");
            for(i=0;i<m;i++)
            {
                printf("\n%d\n",avail[i]);
             }
        printf("\tAllocation Matrix\t\t\tMax Matrix\n");
        for(i=0;i<n;i++)
        {
            printf("\n%s",p[i].pnm);
                for(j=0;j<m;j++)
                {
                    printf("\t%d",p[i].alloc[j]);
                }
                    printf("\t\t");
                for(j=0;j<m;j++)
                {
                    printf("\t%d",p[i].max[j]);
                }
        }
        printf("\n");
    }

void display_need()
    {
        printf("\n\tNeed Matrix\n");
        for(i=0;i<n;i++)
        {
            printf("\n%s",p[i].pnm);
            for(j=0;j<m;j++)
             {
                printf("\t%d",p[i].need[j]);
             }
        }
        printf("\n");
    }

void bankers()
    {
    int work[10],flag=0,fin_flag=0,x=1,i=0,j=0;
        for(j=0;j<m;j++)
        {
            work[j]=avail[j];
        }
    while(x<=2)
        {
            for(i=0;i<n;i++)
            {
                flag=0;
                if(finish[i]==0)
                {
                    for(j=0;j<m;j++)
                    {
                        if(work[j]>=p[i].need[j])
                        {
                            flag=1;
                        }
                        else
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1)
                    {
                        for(j=0;j<m;j++)
                        {
                            work[j]=work[j]+p[i].alloc[j];
                            finish[i]=1;
                        }
                        strcpy(safe_seq[s++],p[i].pnm);

                    }
                }
            }//end of for
            x++;
        }//end of while
    printf("\nFor process: %s\n",p[i].pnm);

    for(i=0;i<n;i++)
    {
        if(finish[i]==1)
        {
            fin_flag=1;
        }
        else
        {
            fin_flag=0;
            break;
        }
    }

    if(fin_flag==1)
    {
        printf("System is in safe state \n");

        printf("Safe sequence \n");
            for(i=0;i<s;i++)
            {
                printf("%s\t",safe_seq[i]);
            }
            printf("\n work\n");
            for(i=0;i<m;i++)
            {
                printf("%d\t",work[i]);
            }
        printf("\n");
    }
    else
    {
        printf("System is in unsafe state \n");
    }
}

void main()
{
    printf("Enter number of processes:\n");
        scanf("%d",&n);
    printf("Enter number of resources:\n");
        scanf("%d",&m);
        accept();
        display();
        need();
        display_need();
        bankers();
}
/*
Enter number of processes:
5
Enter number of resources:
3
Enter the available Resources
3 3 2

Enter process name
P0
Enter allocation
0
Enter allocation
1
Enter allocation
0
Enter Max
7
Enter Max
5
Enter Max
3

Enter process name
P1
Enter allocation
2
Enter allocation
0
Enter allocation
0
Enter Max
3
Enter Max
2
Enter Max
2

Enter process name
P2
Enter allocation
3
Enter allocation
0
Enter allocation
2
Enter Max
9
Enter Max
0
Enter Max
2

Enter process name
P3
Enter allocation
2
Enter allocation
1
Enter allocation
1
Enter Max
2
Enter Max
2
Enter Max
2

Enter process name
P4
Enter allocation
0
Enter allocation
0
Enter allocation
2
Enter Max
4
Enter Max
3
Enter Max
3
************************
Available Resources

3

3

2
        Allocation Matrix                       Max Matrix

P0      0       1       0                       7       5       3
P1      2       0       0                       3       2       2
P2      3       0       2                       9       0       2
P3      2       1       1                       2       2       2
P4      0       0       2                       4       3       3

        Need Matrix

P0      7       4       3
P1      1       2       2
P2      6       0       0
P3      0       1       1
P4      4       3       1

For process:
System is in safe state
Safe sequence
P1      P3      P4      P0      P2
 work
10      5       7

Process returned 10 (0xA)   execution time : 82.803 s
Press any key to continue.
*/
