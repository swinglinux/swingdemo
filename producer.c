#include<stdlib.h>
#include<stdio.h>
#include "swing.h"

int main()
{
    unsigned long i;
    int token=0;
    unsigned long len;
    char *p;
	int ret;
	char command[10]="";
    char content[10];
	
	len =2*4096UL;

	ret = createarea((void**)&p, &token, len);
	if(ret<0)
	{
		printf("Create area failed.\n");
		exit(-1);
	}
	
	printf("Addr:%p\n",p);
	printf("Token:%d\n",token);


    while(command[0]!='q')
    {
        printf("Input a command: r, w, e, d, u, q:\n");
        scanf("%s",command);
        if(command[0]=='r')
        {
            for(i=0;i<len;i=i+4096)
            {
                printf("%c",p[i]);
            }
            printf("\n");
        }
        else if(command[0]=='w')
        {
            scanf("%s",content);
            for(i=0;i<len;i=i+4096)
                p[i]=content[0];
        }
        else if(command[0]=='e')
            enablehook(token);
        else if(command[0]=='d')
            disablehook(token);
        else if(command[0]=='u')
            releasearea(token);
    }
}
