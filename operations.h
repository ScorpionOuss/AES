void subBytes(byte *b);
void subWord(word *w);
void rotWord(word *w);
void wordXor(word *result, word *op1, word *op2);
void subBlock(byte* w);
void addRoundKey(int round);
void shiftRows(byte *block);