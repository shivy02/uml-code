/**
 * @file FibLFSR.h
 * @author Shivam Patel
 * Due Date: 2022-01-31
 * Course: Comp 4
 * @date 2022-01-31
 * 
 */
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class FibLFSR {
    public:
        FibLFSR(string seed);           // constructor to create LFSR with
        int step();                     // the given initial seed
        int generate(int k);
        string getSeed(void) const;     // simulate one step and return the
                                        // new bit as 0 or 1
                                        // simulate k steps and return
                                        // k-bit integer
    private:
    string iseed;
};

int unstringify(char bit);
ostream& operator<<(ostream& out, const FibLFSR& l);