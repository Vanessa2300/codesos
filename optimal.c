#include<stdio.h>
int main()
{
    int n,pg[30],fr[10];
    int count[10],i,j,k,fault,f,flag,temp,current,c,dist,max,m,cnt,p,x;
    float rate;
        fault=0;
        dist=0;
        k=0;

        printf("Enter the total no pages:");
        scanf("%d",&n);
        printf("Enter the sequence:");

            for(i=0;i<n;i++){
                scanf("%d",&pg[i]);
            }

        printf("\nEnter frame size:");
        scanf("%d",&f);

        for(i=0;i<f;i++){
            count[i]=0;
            fr[i]=-1;
        }
    for(i=0;i<n;i++){
        flag=0;
        temp=pg[i];
        for(j=0;j<f;j++)
        {
            if(temp==fr[j])
            {
                flag=1;
                break;
            }
        }
        if((flag==0)&&(k<f)){
            fault++;
            fr[k]=temp;
            k++;
        }
        else if((flag==0)&&(k==f)){
            fault++;
            for(cnt=0;cnt<f;cnt++){
                current=fr[cnt];
                for(c=i;c<n;c++){
                    if(current!=pg[c])
                        count[cnt]++;
                    else
                        break;
                }
            }
            max=0;

            for(m=0;m<f;m++){
                if(count[m]>max){
                    max=count[m];
                    p=m;
                }
            }
            fr[p]=temp;
        }

        printf("\npage  %d  frame\t",pg[i]);

        for(x=0;x<f;x++){
            printf("%d\t",fr[x]);
        }
    }
    rate = fault/(float)n;
    printf("\nTotal number of faults=%d",fault);
    printf("\nPage Fault Rate: %f",rate);

    return 0;
}
/*
Enter the total no pages:12
Enter the sequence:0 2 1 6 4 0 1 0 3 1 2 1

Enter frame size:3

page  0  frame  0       -1      -1
page  2  frame  0       2       -1
page  1  frame  0       2       1
page  6  frame  0       6       1
page  4  frame  0       4       1
page  0  frame  0       4       1
page  1  frame  0       4       1
page  0  frame  0       4       1
page  3  frame  0       3       1
page  1  frame  0       3       1
page  2  frame  0       2       1
page  1  frame  0       2       1
Total number of faults=7
Page Fault Rate: 0.583333
Process returned 0 (0x0)   execution time : 10.420 s
*/
