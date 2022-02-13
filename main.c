#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"
#include "operations.h"

char *inFile = "in/aes_sample.in\0";
int size = 4; /** This is Nk = Nb **/
int wordSize = 4; /* We consider words of 32 bits = 4 bytes */
int numRounds = 10; /* Number of rounds for AES-128 is 10 **/

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
    byte key[size*wordSize];
    fread(key, 1, size*wordSize, fp);

    /** We need to read the blocks to encrypt; Each block
     * is of 16 bytes size**/
    int readSize = 1;
    char block[size*wordSize];
    while (readSize){
        readSize = fread(block, 1, size*wordSize, fp);
        if (readSize){
            /* Here we need to apply the encryption and write it into
            the output file*/ 

        }
    };
}