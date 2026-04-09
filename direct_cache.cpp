#include <stdio.h>
#include <iostream>
#include "cache.h"
#include <vector>
#include <fstream>

using namespace std;

DirectCache::DirectCache( int size) : numLines (size), hits (0), misses (0) {
    cache.resize(size);
    for (int i = 0; i<size; i++) {
        cache[i].valid = false;
        cache[i].tag = 0;
    }
}

bool DirectCache::accessCache(unsigned int address) {
    int index = address % numLines;
    int tag   = address / numLines;
    if (cache[index].valid && cache[index].tag == tag) {
        hits++;
        return true;  // cache hit
    } else {
        misses++;
        cache[index].valid = true;
        cache[index].tag = tag;
        return false;  // cache miss
}
}

int DirectCache::getHits() {
    return hits;
}

int DirectCache::getMisses() {
    return misses;
}


int main () {
DirectCache cache(64); 
ifstream infile("memory_trace.txt");
infile >> std::hex;
unsigned int addr;

while (infile >> addr) {
    if (cache.accessCache(addr))
        cout << "Hit for address " << addr << "\n";
    else
        cout << "Miss for address " << addr << "\n";
}


std::cout << "Total Hits: " << cache.getHits() << "\n";
std::cout << "Total Misses: " << cache.getMisses() << "\n";

return 0;
}