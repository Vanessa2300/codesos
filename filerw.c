#include <stdio.h>
#include <stdlib.h>
int main()
{
     FILE *file;
     char filename[100],data[100];
        printf("Enter the filename with extension to open for writing:");
        scanf("%s", filename);
     file = fopen(filename, "w");
         if (file == NULL){
             printf("Error opening the file.\n");
             exit(1);
         }
         printf("Enter data to write to the file: ");
         scanf(" %[^\n]s", data); //read a string of characters until a newline character (\n) is encountered.
         fprintf(file, "%s\n", data);
         printf("Data written to the file successfully.\n");
         fclose(file);
         printf("Enter the filename to open for reading: ");
         scanf("%s", filename);
         file = fopen(filename, "r");

         if (file == NULL{
         printf("Error opening the file.\n");
         exit(1);
         }
        printf("Data read from the file:\n");

     while (fgets(data, sizeof(data), file) != NULL){
        printf("%s", data);
     }
     fclose(file);
     return 0;
}
