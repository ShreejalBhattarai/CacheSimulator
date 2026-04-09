#include <vector>
using namespace std;

struct cacheLine {
    unsigned int tag;
    bool valid;
};

class DirectCache {
    private:
        std::vector<cacheLine> cache;
        int numLines;
        int hits;
        int misses;
    public:
        DirectCache (int size);
        bool accessCache (unsigned int address); // called every time a memory address is accessed. Returns true if hit, false if miss.
        int getHits();
        int getMisses();
};