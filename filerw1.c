#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
int main()
{
     char sourceFile[100], destFile[100];
     int sourceFd, destFd;
     char buffer[BUFFER_SIZE];
     ssize_t bytesRead, bytesWritten;
     printf("Enter source file name: ");
     scanf("%s", sourceFile);
     sourceFd = open(sourceFile, O_RDONLY);

         if (sourceFd == -1){
             perror("Failed to open source file");
             exit(EXIT_FAILURE);
         }

     printf("Enter destination file name: ");
     scanf("%s", destFile);
     destFd = open(destFile, O_WRONLY | O_CREAT | O_TRUNC);

         if (destFd == -1){
             perror("Failed to create destination file");
             exit(EXIT_FAILURE);
         }

     while ((bytesRead = read(sourceFd, buffer, BUFFER_SIZE)) > 0){
         bytesWritten = write(destFd, buffer, bytesRead);
         if (bytesWritten != bytesRead){
             perror("Failed to write to destination file");
             exit(EXIT_FAILURE);
         }
     }

     if (bytesRead == -1){
         perror("Failed to read from source file");
         exit(EXIT_FAILURE);
     }

     if (close(sourceFd) == -1){
         perror("Failed to close source file");
         exit(EXIT_FAILURE);
     }

     if (close(destFd) == -1){
         perror("Failed to close destination file");
         exit(EXIT_FAILURE);
     }
        printf("File copied successfully!\n");
     return 0;
}
