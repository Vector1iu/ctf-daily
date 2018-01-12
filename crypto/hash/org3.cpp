#include <stdio.h>
#include <openssl/md5.h>
#include <arpa/inet.h>
int main(int argc,const char* argv[])
{
    MD5_CTX c;
    unsigned char buffer[MD5_DIGEST_LENGTH];
    MD5_Init(&c);
    MD5_Update(&c,
                "\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\xdd\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00"           
                ,64);
//    c.A=htonl(0x8179817a);
//    c.B=htonl(0x23a822de);
//    c.C=htonl(0xe4b09e4b);
//    c.D=htonl(0x35895acd);
//    34177e68e7cdff69b4f3642e37f795dd
    c.A=htonl(0x73cc6519);
    c.B=htonl(0x8b90b76c);
    c.C=htonl(0xd9e48ab4);
    c.D=htonl(0x477084bf);
    MD5_Update(&c,"J$ST",4);
    MD5_Final(buffer,&c);
    for(int i=0;i<16;i++){
        printf("%02x",buffer[i]);
    }
    printf("\n");
    return 0;
}
