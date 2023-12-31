#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX 10


void *mult(void* arg){
    int *data = (int *)arg;
    int k = 0, i = 0;

    int x = data[0];
    for (i = 1; i <= x; i++)
        k += data[i]*data[i+x];

    int *p = (int*)malloc(sizeof(int));
        *p = k;
    pthread_exit(p);
}

int main(){

    int matA[MAX][MAX];
    int matB[MAX][MAX];


    int r1, c1, r2, c2, i, j, k, max;

        printf("Enter no.of rows: ");
        scanf("%d", &r1);

        printf("Enter no.of columns: ");
        scanf("%d", &c1);

    printf("Matrix A input\n");
        for (i = 0; i < r1; i++){
            for (j = 0; j < c1; j++){
                printf("Enter value: ");
                scanf("%d",&matA[i][j]);
            }
        }


    printf("Matrix B input\n");
        for (i = 0; i < r1; i++){
            for (j = 0; j < c1; j++){
                printf("Enter value: ");
                scanf ("%d",&matB[i][j]);
            }
        }

    printf("matrix a\n");
        for (i = 0; i < r1; i++){
            for(j = 0; j < c1; j++)
            printf("%d ",matA[i][j]);
            printf("\n");
        }

    printf("matrix b\n");
        for (i = 0; i < r1; i++){
            for(j = 0; j < c1; j++)
            printf("%d ",matB[i][j]);
            printf("\n");
        }


    max = r1*c1;

    pthread_t *threads;
    threads = (pthread_t*)malloc(max*sizeof(pthread_t));

    int count = 0;
    int* data = NULL;
    for (i = 0; i < r1; i++){
        for (j = 0; j < c1; j++){

            data = (int *)malloc((20)*sizeof(int));
            data[0] = c1;

            for (k = 0; k < c1; k++)
                data[k+1] = matA[i][k];

            for (k = 0; k < r1; k++)
                data[k+c1+1] = matB[k][j];

            pthread_create(&threads[count++], NULL,
            mult, (void*)(data));

        }
    }

    printf("RESULTANT MATRIX IS :- \n");
    for (i = 0; i < max; i++){
        void *k;

        pthread_join(threads[i], &k);


        int *p = (int *)k;
            printf("%d ",*p);
        if ((i + 1) % c1 == 0)
            printf("\n");
    }

    return 0;
}

