#include <cstdint>
#include <sstream>
#include <iostream>

#ifndef DEF_BLOCK
#define DEF_BLOCK

using namespace std;

class Block{
    private: 
        uint32_t _nIndex; //numero de block
        int64_t _nNonce; //
        string _sData; //data contenu dans le block
        string _sHash; //valeur hashé du block
        time_t _tTime; //date de l'insertion du block
        
        string _calculateHash() const; //calcul du hash
    public:
        string sPrevHash; 
        Block(uint32_t nIndexIn, const string &sDataIn);
        string getHash();
        void mineBlock(uint32_t nDifficulty);
};

#endif