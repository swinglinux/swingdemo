#include<stdio.h>
#include<stdlib.h>
#include "swing.h"

int main()
{
    unsigned long i;
    int token=0;
    int mytoken=0;
    unsigned long len;
    char *p; 
    char command[10]="";
    char con[10];
	int ret;

	len=2*4096UL;

    printf("Input the token of the producer:\n");
    scanf("%d",&token);

    ret = hook((void**)&p, &mytoken, token);
	if(ret < 0)
	{
		printf("Hook failed.\n");
		exit(-1);
	}

    printf("Address:%p\n",p);
	printf("My token:%d\n",mytoken);

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
            scanf("%s",con);
            for(i=0;i<len;i=i+4096)
                p[i]=con[0];
        }
        else if(command[0]=='e')
            enablehook(mytoken);
        else if(command[0]=='d')
            disablehook(mytoken);
        else if(command[0]=='u')
            releasearea(mytoken);
    }
}
