#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "encrypt.h"
#include "operations.h"



unsigned char Rcon[10] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36};

void keyExpansion(byte *key, word *w, int nk){
    word temp;
    int i = 0;

    /* We copy the key into the first 4 bytes of w */
    memcpy((byte *) w, (byte *) key, nk*wordSize);

    /*** The difference between strncpy and memcpy
     * strcpy copies C **Strings**, if you're copying bulk
     * memory with random bytes in it, strncpy is
     * just broken ***/
    
    //assert
    i = nk;
    byte rcon[4] = {0, 0, 0, 0};
    while(i < size*(numRounds + 1)){
        temp = w[i -1];
        if (i%nk == 0){
            rcon[0] = Rcon[i/nk - 1]; 
            rotWord(&temp);
            subWord(&temp);
            wordXor(&temp, &temp, (word *) rcon);
        } else if ((nk > 6 ) & (i%nk == size)){
            subWord(&temp);
        }
        wordXor(w + i, w + i -nk, &temp);
        i++;
    }
}