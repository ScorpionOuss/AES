#include <stdio.h>
#include <stdlib.h>

#include "encrypt.h"

/** Global variables are initialized by the
 * compiler itself and should be initialized
 * by a constant value! **/


void main(int argc, char **argv){
    /**
     * @brief Main function
     * 
     */
    /** Open the in file **/
    FILE *fp = fopen(inFile, "r");
    /*** Extract the key ***/
    char key[size*wordSize];
    fread(key, sizeof(char), size, fp);
    printf("%lx\n", *((long unsigned int *) key));
    printf("%lx\n", *((long unsigned int *) key + 1));

    /** We need to read the blocks to encrypt; Each block
     * is 16 bytes **/
    int readSize = 1;
    char block[size*wordSize];
    while (readSize){
        readSize = fread(block, sizeof(char), size, fp);
        if (readSize){
            /* Here we need to apply the encryption and write it into
            the output file*/ 
            printf("%lx\n", *((long unsigned int *) block));
            printf("%lx\n", *((long unsigned int *) block + 1));
        }
    };
}