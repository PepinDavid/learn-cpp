#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
}

string Block::getHash() {
    return _sHash;
}

void Block::mineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
 
    string str(cstr);
 
    do {
        _nNonce++;
        _sHash = _calculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);
 
    cout << "Block mined: " << _sHash << endl;
    cout << "Block mined nNonce: " << _nNonce << endl;
    cout << "previous Block mined: " << sPrevHash << endl;
}

inline string Block::_calculateHash() const {
    stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;
 
    return sha256(ss.str());
}