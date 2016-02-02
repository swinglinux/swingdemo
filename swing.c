#include<unistd.h>


int createarea(void ** addr, int * token, unsigned long len)
{
    long ret;
    ret = syscall(314,len);
	if(ret < 0)
		return -1;
	*addr = (void*)(ret &(~(0xfffL)));
	*token = (long)ret & 0xfff;
	return 0;
}

int hook(void ** addr, int * mytoken, int token)
{
	long ret;
	ret = syscall(315,token);
	if(ret < 0)
		return -1;

    *mytoken = (long)ret & 0xfff;
    *addr=(void*)((long)ret&(~(0xfffL)));
	return 0;
}

int enablehook(int token)
{
	return syscall(316,token,1);
}


int disablehook(int token)
{
	return syscall(316,token,0);
}
int releasearea(int token)
{
	return syscall(317,token);
}
