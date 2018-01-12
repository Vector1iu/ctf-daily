#include <stdio.h>
#include <openssl/md5.h>
//这部分程序模拟是服务器给的哈希值
int main(int argc,const char* argv[])
{
    MD5_CTX c;
    unsigned char buffer[MD5_DIGEST_LENGTH];
    int i;
    MD5_Init(&c);
    MD5_Update(&c,"123456789abcdef",15);//salt
    MD5_Update(&c,"adminadmin"      
            ,10);
    MD5_Final(buffer,&c);
    for(int i=0;i<16;i++){
        printf("%02x",buffer[i]);
    }
    printf("\n");
    return 0;
}
