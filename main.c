#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int fn,nl;
    double avrmark;
    char name[100];
    printf("Faculty number is: ");
    scanf("%d",&fn);
    printf("The name is ");
    fflush(stdin);
    gets(name);
    nl= strlen(name);
    printf("The length of the name is: %d \n",nl);
    printf("Average mark is: ");
    scanf("%lf",&avrmark);
    FILE *fp;
    if((fp=fopen("tester.bin","ab"))==NULL)
    {
        printf("The file does not exist");
        exit(1);
    }
    if(fwrite(&fn,sizeof(int),sizeof(fn),fp)!=sizeof(fn))
    {
        printf("Error in writing in the file 1");
        exit(2);
    }
    if(fwrite(&nl,sizeof(int),sizeof(nl),fp)!=sizeof(nl))
    {
        printf("Error in writing in the file 2");
        exit(3);
    }
    if(fwrite(name,sizeof(char),strlen(name),fp)!=strlen(name))
    {
        printf("Error in writing in the file 3");
        exit(4);
    }
    if(fwrite(&avrmark,sizeof(double),sizeof(avrmark),fp)!=sizeof(avrmark))
    {
        printf("Error in writing in the file 4");
        exit(5);
    }
    fclose(fp);

    return 0;
}
