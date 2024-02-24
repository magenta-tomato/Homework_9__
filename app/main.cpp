
#include "Bulk.h"

int main(int argc, char* argv[]) 
{
    int sz = std::stoi(argv[1]);

    Bulk b(sz);
    b.processLoop();

}
