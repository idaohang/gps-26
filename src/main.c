// a collection of first draft gps correlator code
// from raw gps data from gnss-sdr to the navigation message
// (hopefully)

#include <stdio.h> 
#include <stdint.h>
// 2013_04_04_GNSS_SIGNAL_at_CTTC_SPAIN.dat
// actually trying out the _SMALL.dat
//
// downconverted at 1.575GHz
// $TYPE sampled at $RATE
// encoded $ENCODING 16-bit signed integers 
// no idea about I/Q format but assuming I/Q interleaved
//
// read in the first 20ms of the file
// file is sampled at 4MHz (they call out 4000000 samples per second)
// so for 100 seconds there are a total of 400,000,000 samples
// we just want the first 20ms which is .02*409600000 = 81920 samples
// does this include I and Q both or just one? 
// the file is 16-bit signed integers 

// now I gave up on that and this is apparently
// a 60-second capture 
// gps_4msps_complex.12Sep2005.dat  
// I only need the first 20ms
// jamey says:
//   downconverted from 1575.42 MHz,
//   quadrature sampled at 4MSPS,
//   encoded Intel endian, 32-bit floating point values
//   I, Q interleaved

int main(int argc, char *argv[]) {

  int i;
  if (argc != 2)
    printf("usage: ./main <filename>\n");

  float buffer[10] = {0};
  FILE *infile;
  infile = fopen("gps.dat","rb");
  fread(buffer,sizeof(float),10,infile);
  fclose(infile);

  printf("sizeof(float) = %d\n",sizeof(float));
  printf("sizeof(int) = %d\n",sizeof(int));
  printf("sizeof(double) = %d\n",sizeof(double));

  for (i = 0; i < 10; i++)
    printf("%.2f\n",buffer[i]);

  return(0);
}
