#include<stdio.h>
#include<stdlib.h>

void main(int argc,char** argv)
{
 FILE *f1,*f2;
 char ch;
 if( argc != 3 )
 {
   printf("Not sufficient arguments\n");
   return;
 }
 f1=fopen(argv[1],"r");
 f2=fopen(argv[2],"w");
 if( (f1 == NULL) || (f2 == NULL))
 {
   printf("File not exists");
   return;
 }
 while((ch = fgetc(f1)) != EOF)
 {
   fputc(ch,f2);
 }
 fclose(f1);
 fclose(f2);
 printf("File copied\n");
 return;
}
