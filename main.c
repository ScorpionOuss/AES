#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"
#include "operations.h"

struct aes runningAES;


/** Global variables are initialized by the
 * compiler itself and should be initialized
 * by a constant value! **/


void main(int argc, char **argv){
    /**
     * @brief Main function
     * 
     */

    /*** Extract the key ***/
    byte key[Nk*wordSize];
    fread(key, 1, Nk*wordSize, stdin);
    memcpy(runningAES.key, (byte *) key, Nb*wordSize);
    /** We need to read the blocks to encrypt; Each block
     * is of 16 bytes size**/
    int readSize = 1;
    char block[Nb*wordSize];
    while (readSize){
        readSize = fread(block, 1, Nb*wordSize, stdin);
        if (readSize){
            /* Here we need to apply the encryption and write it into
            the output file*/
            memcpy(runningAES.state, (byte *) block, Nb*wordSize);
            encrypt();
            fwrite(runningAES.state, 1, Nb*wordSize, stdout);
        }
    };
}