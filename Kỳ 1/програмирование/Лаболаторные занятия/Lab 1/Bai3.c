#include <stdio.h>
int main(void) {
	char m[]="ITMO";
    int i=0,count=0;
    while(m[i++]){
        count++;
    }
    printf("%s\n",m);
    
    for(int i=0,j=count-1;i<count/2;i++,j--) {
        char tmp=m[i];
        m[i]=m[j];
        m[j]=tmp;
    }
    printf("%s",m);
	return 0;
}