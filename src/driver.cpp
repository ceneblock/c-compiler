#include <driver.h>
#include <memory>

namespace frontend
{
  driver::driver()
  {
    argv = NULL;
    
    for(const auto &kv : optionMap)
    {
      long_options.push_back(kv.second.o);
    }
  }

  void driver::addArgv(char *argv[])
  {
    this->argv = argv;
  }
  
  void driver::addOptions(std::string options)
  {
    this->options += " " + options;
  }

  bool driver::parse()
  {
    bool successful = false;
    if(argv)
    {
      while(1)
      {
        int option_index = 0;
      }
    }

    return successful;
  }
}
