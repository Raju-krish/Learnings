#include <stdio.h>


void remove_duplicate(char *buf)
{
    int hash[127] = {0};
    int  i = 0, j = 0;
    
    while(buf[i] != '\0' ) {
        int idx = buf[i];
        if(hash[idx] == 0) {
            hash[idx] = 1;
            buf[j] = buf[i];
            j++;
        }
        i++;
    }
    buf[j] = '\0';
}

int main(int argc, char *argv[])
{
    char buf[] = "Rajagopala swamy M";
    remove_duplicate(buf);
    printf("After removing duplicates : %s\n", buf);
}
