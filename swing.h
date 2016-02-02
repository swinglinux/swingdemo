int createarea(void ** addr, int * token, unsigned long len);
int hook(void ** addr, int * mytoken, int token);
int enablehook(int token);
int disablehook(int token);
int releasearea(int token);
