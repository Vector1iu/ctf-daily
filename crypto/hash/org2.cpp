#include <stdio.h>
#include <openssl/md5.h>
//发送给服务器的密码是
//               ""adminadmin""
//               "\x80\x00\x00\x00\x00\x00\x00\x00"
//               "\x00\x00\x00\x00\x00\x00\x00\x00"
//               "\x00\x00\x00\x00\x00\x00\x00\x00"
//               "\x00\x00\x00\x00\x00\x00\x00\xC8"
//               "\x00\x00\x00\x00\x00\x00\x00"
//               ""J$ST""
int main(int argc,const char* argv[])
{
    MD5_CTX c;
    unsigned char buffer[MD5_DIGEST_LENGTH];
    int i;
    MD5_Init(&c);
    MD5_Update(&c,"123456789abcdef",15);
    MD5_Update(&c,"adminadmin"
                "\x80\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\xC8"
                "\x00\x00\x00\x00\x00\x00\x00"
            ,49);
    MD5_Update(&c,"J$ST",4);
    MD5_Final(buffer,&c);
    for(int i=0;i<16;i++){
        printf("%02x",buffer[i]);
    }
    printf("\n");
    return 0;
}
