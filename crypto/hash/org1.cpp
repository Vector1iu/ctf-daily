#include <stdio.h>
#include <openssl/md5.h>

int main(int argc,const char* argv[])
{
    MD5_CTX c;
    unsigned char buffer[MD5_DIGEST_LENGTH];
    int i;
    MD5_Init(&c);
    MD5_Update(&c,"123456789abcdef",15);
    MD5_Update(&c,"adminadmin"
            ,10);
    MD5_Final(buffer,&c);
    for(int i=0;i<16;i++){
        printf("%02x",buffer[i]);
    }
    printf("\n");
    return 0;
}
