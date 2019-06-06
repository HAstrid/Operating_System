#include<stdio.h>
#include<stdlib.h>

int main(int argc,char** argv)
{
    FILE *f1,*f2;
    char ch;

    if(argc != 3)
    {
        printf("Insufficiant number of arguments\n");
        return 0;
    }
    f1=fopen(argv[1],"r");
    f2=fopen(argv[2],"w");

    if((f1 == NULL) || (f2 == NULL))
    {
        printf("File does not exisits\n");
        return 0;
    }
    while((ch=fgetc(f1))!=EOF)
    {
        fputc(ch,f2);
    }
    fclose(f1);
    fclose(f2);
    printf("Content Copied\n");
    return 0;
}