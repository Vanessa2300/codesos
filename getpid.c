#include<stdio.h>
#include<stdlib.h>
//#include<sys/wait.h>
#include<unistd.h>
int main() {
 int pid = getpid();
 printf("Process id: %d", pid);
 return 0;
}
