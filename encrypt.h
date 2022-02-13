#define Nb 4
#define Nk 4
#define wordSize 4
#define numRounds 10

typedef unsigned char byte;
typedef struct { byte x[wordSize]; } word;

struct aes {
    byte key[Nk];
    byte state[16];
    word w[44];
    
};

struct aes runningAES;
// #define key runningAES.key
// #define w runningAES.expandedKey
// #define state runningAES.state

char *inFile;

void keyExpansion();
void addRoundKey(int round);