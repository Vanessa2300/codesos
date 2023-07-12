//final sjf
#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESS 100
struct process{
    int pid;
    int burst_time;
    int arrival_time;
    int turn_around_time;
    int wait_time;
    int processed;
};

typedef struct process Process;
void sort_process_by_arrival_time(Process p[], int n)
    {
        int i, j;
        Process temp;
        for( i=0; i<n-1; i++)
        {
            for ( j=0; j<n-i-1; j++)
            {
                if( p[j].arrival_time > p[j+1].arrival_time)
                {
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
void print_gantt_chart (Process p[], int n)
    {
        int i, j, timet = 0, end_time[10],sum_bt=0, smallest, current=100;
            for(i=0; i<n; i++)
                {
                end_time[i] = p[i].arrival_time;
                }
            for(i=0; i<n; i++)
            {
                sum_bt += p[i].burst_time;
            }

        for(timet=0; timet<=sum_bt; timet++)
        {
            smallest = 100;
            p[smallest].burst_time = 10;
                for(i=0; i<n; i++)
                {
                    if(p[i].arrival_time<=timet && p[i].processed!=1 && p[i].burst_time<p[smallest].burst_time)
                    {
                    smallest = i;
                    }
                }

            p[smallest].burst_time -= 1;
            if(current != smallest)
            {
                printf("|%d|", p[smallest].pid);
                p[smallest].wait_time += (timet - end_time[smallest]);
                end_time[smallest] = timet+1;
                current = smallest;
            }

            if(p[smallest].burst_time == 0)
            {
                p[smallest].turn_around_time = (timet+1)-p[smallest].arrival_time;
                p[smallest].processed = 1;
            }
        }
    }
void print_tat_wait_time(Process p[], int n)
    {
    int i = 0, total_TAT = 0, total_wait_time = 0 ;
    double avg_TAT = 0, avg_wait_time =0;
    printf(" \nJob | TAT | Wait time\n");
        for (i=0 ; i < n; i++)
        {
            printf("%d | %d | %d \n", p[i].pid, p[i].turn_around_time,p[i].wait_time);
            total_TAT = total_TAT + p[i].turn_around_time;
            total_wait_time = total_wait_time + p[i].wait_time;
        }
    avg_TAT = (double)total_TAT / (double)n;
    avg_wait_time = (double)total_wait_time /(double) n;
    printf("Average Turn aroud time = %f\n", avg_TAT);
    printf("Average waiting time = %f\n", avg_wait_time);
    }

int main()
{
    Process p[MAX_PROCESS];
    int n, i, j;
        printf("Enter total process\n");
        scanf("%d",&n);
        printf("Enter burst time and Arrival time for each process\n");
        for( i=0; i<n; i++)
        {
            printf("p[%d]: Burst time :", i+1);
            scanf("%d",&p[i].burst_time);
            printf("p[%d]: Arrival time :", i+1);
            p[i].pid = i+1;
            scanf("%d",&p[i].arrival_time);
            p[i].wait_time = 0;
        }

    sort_process_by_arrival_time(p,n);
    printf("\nGantt chart:\n");
    print_gantt_chart(p,n);
    print_tat_wait_time( p, n);
}

/*
Enter total process
4
Enter burst time and Arrival time for each process
p[1]: Burst time :5
p[1]: Arrival time :0
p[2]: Burst time :3
p[2]: Arrival time :1
p[3]: Burst time :8
p[3]: Arrival time :2
p[4]: Burst time :6
p[4]: Arrival time :3

Gantt chart:
|1||2||1||4||3||4|
Job | TAT | Wait time
1 | 8 | 3
2 | 3 | 0
3 | 20 | 12
4 | 11 | 5
Average Turn aroud time = 10.500000
Average waiting time = 5.000000

Process returned -1073741819 (0xC0000005)   execution time : 19.707 s
Press any key to continue.

*/
