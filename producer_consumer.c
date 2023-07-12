#include<stdio.h>
#include<conio.h>
int S=1,full=0,empty=3,x=0;
int main()
    {
        int n;
        void producer();
        void consumer();
        int wait(int);
        int signal(int);
        printf("1.Producer\n2.Consumer\n3.Exit");
        while(1)
        {
            printf("\nEnter your choice:");
            scanf("%d",&n);
            switch(n)
             {
                case 1:
                    if((S==1)&&(empty!=0))
                        producer();
                    else
                        printf("Buffer is full!!");
                    break;

                case 2:
                    if((S==1)&&(full!=0))
                        consumer();
                    else
                        printf("Buffer is empty!!");
                    break;

                case 3:
                    exit(0);
                    break;
             }
         }
        return 0;
    }

int wait(int s)
    {
        return (--s);
    }

int signal(int s)
    {
        return(++s);
    }

void producer()
    {
        S=wait(S);
        full=signal(full);
        empty=wait(empty);
        x++;
        printf("\nProducer produces item %d",x);
        S=signal(S);
    }

void consumer()
    {
        S=wait(S);
        full=wait(full);
        empty=signal(empty);
        printf("\nConsumer consumes item %d",x);
        x--;
        S=signal(S);
    }

    /*
    1.Producer
2.Consumer
3.Exit
Enter your choice:1

Producer produces item 1
Enter your choice:1

Producer produces item 2
Enter your choice:1

Producer produces item 3
Enter your choice:2

Consumer consumes item 3
Enter your choice:2

Consumer consumes item 2
Enter your choice:2

Consumer consumes item 1
Enter your choice:2
Buffer is empty!!
Enter your choice:1

Producer produces item 1
Enter your choice:2

Consumer consumes item 1
Enter your choice:3

Process returned 0 (0x0)   execution time : 37.892 s
Press any key to continue.

    */
