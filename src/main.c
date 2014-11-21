// a collection of first draft gps correlator code
// from raw gps data from gnss-sdr to the navigation message
// (hopefully)

#include <stdio.h> 

// read in the first 20ms of the file
// file is sampled at 4MHz (they call out 4000000 samples per second)
// so for 100 seconds there are a total of 400,000,000 samples
// we just want the first 20ms which is .02*409600000 = 81920 samples
// does this include I and Q both or just one? 
// the file is 16-bit integers 
int main(int argc, char *argv[]) {

}
