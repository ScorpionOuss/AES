#define Nb 4
#define Nk 4
#define wordSize 4
#define numRounds 10

typedef unsigned char byte;
typedef struct { byte x[wordSize]; } word;

struct aes {
    byte key[Nk*wordSize];
    byte state[Nb*wordSize];
    word w[Nb*(numRounds+1)];
    
};

struct aes runningAES;
// #define key runningAES.key
// #define w runningAES.expandedKey
// #define state runningAES.state

char *inFile;


void encrypt();