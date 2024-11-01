#include <stdio.h>

int main(){
    int n = 128;
    printf("%d \n", n);
    if (n&(n-1))
        printf("no \n");  
    else printf("yes \n");

    char m[]="ITMO";
    int i=0,count=0;
    while(m[i++]){
        count++;
    }
    printf("%s\n",m);
    printf("%d\n",count);
 
    for(int i=0,j=count-1;i<count/2;i++,j--) {
        char tmp=m[i];
        m[i]=m[j];
        m[j]=tmp;
    }
    printf("%s\n",m);

    return 0;
}
