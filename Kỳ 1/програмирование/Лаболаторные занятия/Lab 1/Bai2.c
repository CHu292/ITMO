#include <stdio.h>
int main(void) {
	char m[]="ITMO";
    int i=0,count=0;
    while(m[i++]){
        count++;
    }
    printf("%s\n",m);
    printf("%d",count);
	return 0;
}