#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"
#include "operations.h"


struct aes runningAES;


void main(int argc, char **argv){
    /**
     * @brief Main test function
     * 
     */

    unsigned char key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 
    0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    memcpy(runningAES.key, (byte *) key, Nk*wordSize);
    printf("%lx\n", *((long unsigned int *) runningAES.key));
    printf("%lx\n", *((long unsigned int *) runningAES.key + 1));
    unsigned char in[16] = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30,
     0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};
    printf("key : %p , and state: %p\n", runningAES.key, runningAES.state);
    memcpy(runningAES.key, (byte *) in, Nb*wordSize);
    printf("%lx\n", *((long unsigned int *) runningAES.key));
    printf("%lx\n", *((long unsigned int *) runningAES.key + 1));
    // printf("Here is the state\n");
    // printf("First Half: %lx\n", *((long unsigned int *) runningAES.state));
    // printf("Second half: %lx\n", *((long unsigned int *) runningAES.state + 1));

    keyExpansion();
    // for (int i = 0; i < 1 + numRounds; i++){
    //     printf("First Half:%d  %lx\n", i, *((long unsigned int *) runningAES.w + 2*i));
    //     printf("Second half: %d %lx\n", i, *((long unsigned int *) runningAES.w + 2*i + 1));
    // }

    // printf("Here is the state\n");
    // printf("First Half: %lx\n", *((long unsigned int *) runningAES.state));
    // printf("Second half: %lx\n", *((long unsigned int *) runningAES.state + 1));
    // printf("ça commence\n");
    // addRoundKey(0);
    // printf("First Half: %lx\n", *((long unsigned int *) runningAES.state));
    // printf("Second half: %lx\n", *((long unsigned int *) runningAES.state + 1));
    // for (int i = 0; i < 1 + numRounds; i++){
    //     printf("First Half:%d  %lx\n", i, *((long unsigned int *) runningAES.w + 2*i));
    //     printf("Second half: %d %lx\n", i, *((long unsigned int *) runningAES.w + 2*i + 1));
    // }
}

void test(int argc, char **argv){
    /**
     * @brief Main function
     * 
     */
    /** Open the in file **/
    FILE *fp = fopen(inFile, "r");
    /*** Extract the key ***/
    byte key[Nk*wordSize];
    fread(key, 1, Nk*wordSize, fp);
    printf("%lx\n", *((long unsigned int *) key));
    printf("%lx\n", *((long unsigned int *) key + 1));
    /** We need to read the blocks to encrypt; Each block
     * is 16 bytes **/
    int readSize = 1;
    char block[Nb*wordSize];
    while (readSize){
        readSize = fread(block, 1, Nb*wordSize, fp);
        if (readSize){
            /* Here we need to apply the encryption and write it into
            the output file*/ 
            /*
            printf("%lx\n", *((long unsigned int *) block));
            printf("%lx\n", *((long unsigned int *) block + 1));
            */
        }
    };
    // word w[size*(numRounds + 1)];
    // keyExpansion(key, w, size);
    word w;
    strncpy((char *) &w, key, 4);
    // subWord(&w);
    // printf("What ?:%x\n", w);
    // rotWord(&w);
    printf("What ?:%x\n", w);
    word r;
    strncpy((char *) &r, key + 4, 4);
    printf("What ?:%x\n", r);
    wordXor(&w, &w, &r);
    printf("What ?:%x\n", w);
}