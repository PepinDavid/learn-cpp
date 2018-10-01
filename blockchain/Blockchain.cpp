#include "Blockchain.h"

Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 1;
}

void Blockchain::addBlock(Block nBlock){
    nBlock.sPrevHash = _getLastBlock().getHash();
    nBlock.mineBlock(_nDifficulty);
    _vChain.emplace_back(nBlock);
}

Block Blockchain::_getLastBlock() const{
    return _vChain.back();
}