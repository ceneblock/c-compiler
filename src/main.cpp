#include "driver.h"
#include <iostream>

using namespace std;
using namespace frontend;

int main(int argc, char *argv[])
{
  int rv = EXIT_SUCCESS;
  driver d;
  d.addArgv(argv);
  d.parse();

  return rv;
}
