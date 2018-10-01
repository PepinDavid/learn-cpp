#include <cstdint>
#include <vector>
#include "Block.h"

#ifndef DEF_BLOCKCHAIN
#define DEF_BLOCKCHAIN

using namespace std;

class Blockchain{
    private:
        uint32_t _nDifficulty;
        vector<Block> _vChain;
        Block _getLastBlock() const;
    public:
        Blockchain();
        void addBlock(Block nBlock);
};

#endif 