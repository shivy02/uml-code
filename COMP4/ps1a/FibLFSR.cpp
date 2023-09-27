/**
 * @file FibLFSR.cpp
 * @author Shivam Patel
 * @brief ps1 - defintions for FibLFSR member functions
 * Due Date: 2022-01-31
 * Course: Comp 4
 * @date 2022-01-31
 * 
 */
#include "FibLFSR.h"

int unstringify(char bit) {
    if (bit == '0') {
        bit = 0;
    } else if (bit == '1') {
        bit = 1;
    }
    return bit;
}

ostream& operator<<(ostream& out, const FibLFSR& l){
    out << l.getSeed() << " ";
    return out;
}


FibLFSR::FibLFSR(string seed){
    iseed = seed;
}

string FibLFSR::getSeed() const {
    return iseed;
}

int FibLFSR::step() {
    int counter;
    int bit;
    // extract the tap bits that we need
    char bit0 = iseed.at(0);
    char bit2 = iseed.at(2);
    char bit3 = iseed.at(3);
    char bit5 = iseed.at(5);

    // convert the string values to integer values
    bit = unstringify(bit0);
    counter = unstringify(bit2);
    // xor the first 2 tap postitions
    counter = counter ^ bit;

    // convert from string to integer
    bit = unstringify(bit3);
    // xor the tap bits
    counter = counter ^ bit;

    // convert from string to integer
    bit = unstringify(bit5);
    // xor the tap bits
    counter = counter ^ bit;

    // append the return value to the string and remove the first bit
    iseed.append(to_string(counter));
    iseed.erase(0, 1);

    return counter;
}

int FibLFSR::generate(int k) {
    const int accum = 2;
    int bin2num = 0;
    string val;
    // append the values returned by step k number of times to a string thats k bits long.
    for (int i = 0; i < k; i++) {
        val.append(to_string(this->step()));
    }

    // convert the generated binary string to a decimal value and return
    int j = 0;
    for (int x = k - 1; x > 0; x--) {
        if (val.at(x) == '1') {
            bin2num += pow(accum, j);
        }
        j++;
    }
    return bin2num;
}
