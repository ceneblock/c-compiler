#include "config.h"

#include "driver.h"

#include <iostream>

using namespace std;
using namespace frontend;

void printHelp(string programName, driver &d)
{
  cout << endl;
  cout << PACKAGE << endl;
  cout << "---" << endl;
  //TODO: put this in config.h
  cout << "A primative c compiler based off of Nora Sandler's Writing a C Compiler ISBN: 978-1-7185-0042-6\n";
  cout << endl;
  const auto &m = d.getOptionMap();
  for(auto &x : m)
  {
    cout << " -" << static_cast<char>(x.second.o.val);
    if(x.second.o.name)
    {
      cout << " | --" << x.second.o.name;
    }

    switch(x.second.o.has_arg)
    {
      case no_argument:
        break;
      case required_argument:
        cout << " val";
        break;
      case optional_argument:
        cout << " [val]";
        break;
      default:
        cerr << "This should never be shown! " << __FILE__ << ":" << __LINE__ << " " << x.second.o.has_arg << endl;
    }
    cout << " -- " << x.second.d << endl;
  }
}

int main(int argc, char *argv[])
{
  int rv = EXIT_SUCCESS;
  driver d;
  d.addArgs(argc, argv);
  if(!d.parse())
  {
    printHelp(argv[0], d);
  }

  if(!d.getOptionMap().at('h').val.str().empty())
  {
    printHelp(argv[0], d);
  }


  return rv;
}
