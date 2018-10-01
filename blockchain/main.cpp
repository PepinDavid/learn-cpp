#include <stdio.h>
#include "Blockchain.h"

int main(int argc, char **argv)
{
	Blockchain bChain = Blockchain();
 
    cout << "Mining block 1..." << endl;
    bChain.addBlock(Block(1, "Block 1 Data"));
    
    cout << "Mining block 2..." << endl;
    bChain.addBlock(Block(2, "Block 2 Data"));
 
    cout << "Mining block 3..." << endl;
    bChain.addBlock(Block(3, "Block 3 Data"));
    
    cout << "Mining block 4..." << endl;
    bChain.addBlock(Block(4, "Block 4 Data and after we have 5th"));
    
    cout << "Mining block 5..." << endl;
    bChain.addBlock(Block(5, "Block 5 and end"));
 
    return 0;
}
