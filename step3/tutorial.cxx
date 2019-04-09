// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#  include "MathFunctions.h"
#endif

#include <cmath>


//#include "TutorialConfig.h"

int main (int argc, char *argv[])
{
  if (argc < 2)
    {
    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
    }
  double inputValue = atof(argv[1]);
  
#ifdef USE_MYMATH
  double outputValue = mysqrt(inputValue);
  char origin[]="MYMATH";
#else
  double outputValue = sqrt(inputValue);
  char origin[] = "STANDARD";
#endif
  
  fprintf(stdout,"The square root of %g is %g\nOrigin:%s\n",
          inputValue, outputValue, origin);
  return 0;
}

