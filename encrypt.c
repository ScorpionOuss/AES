#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "encrypt.h"
#include "operations.h"



byte Rcon[10] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36};


void keyExpansion(){
    word temp;
    int i = 0;

    /* We copy the key into the first 4 bytes of w */
    memcpy((byte *) runningAES.w, (byte *) runningAES.key, Nk*wordSize);

    /*** The difference between strncpy and memcpy
     * strcpy copies C **Strings**, if you're copying bulk
     * memory with random bytes in it, strncpy is
     * just broken ***/
    
    //assert
    i = Nk;
    byte rcon[4] = {0, 0, 0, 0};
    while(i < Nb*(numRounds + 1)){
        temp = runningAES.w[i -1];
        if (i%Nk == 0){
            rcon[0] = Rcon[i/Nk - 1];
            rotWord(&temp);
            subWord(&temp);
            wordXor(&temp, &temp, (word *) rcon);
        } else if ((Nk > 6 ) & (i%Nk == 4)){
            subWord(&temp);
        }
        wordXor(runningAES.w + i, runningAES.w + i -Nk, &temp);
        i++;
    }
}

void cipher(){
    /**
     * @brief Encryption function
     * 
     */

    addRoundKey(0);

    for (int round = 1; round < numRounds; round++){
        subBlock(runningAES.state);
        shiftRows(runningAES.state);
        mixColumns(runningAES.state);
        addRoundKey(round);

    }
    subBlock(runningAES.state);
    shiftRows(runningAES.state);
    addRoundKey(numRounds);
}