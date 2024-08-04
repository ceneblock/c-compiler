#include <driver.h>
#include <memory>

#include <iostream>
namespace frontend
{
  driver::driver()
  {
    argc = 0;
    argv = NULL;
    
    for(const auto &kv : optionMap)
    {
      longOptions.push_back(kv.second.o);
      getopt_string += kv.first;
      if(kv.second.o.has_arg)
      {
        getopt_string += ":";
      }
    }
  }

  void driver::addArgs(int argc, char *argv[])
  {
    this->argc = argc;
    this->argv = argv;
  }
  
  void driver::addOptions(std::string options)
  {
    this->options += " " + options;
  }

  bool driver::parse()
  {
    bool rv = true;
    int c = 0;
    if(argv)
    {
      while(1)
      {
        int option_index = 0;
        c = getopt_long(argc, argv, getopt_string.c_str(), &longOptions[0], &option_index);
        if(c == -1)
        {
          rv = false;
          break;
        }
        if(static_cast<char>(c) == '?')
        {
          std::cerr << "Unrecongized option\n";
          std::cerr << "option found: " << static_cast<char>(c) << std::endl;
          std::cerr << "option index: " << option_index << std::endl;
          continue;
        }
        
        if(DEBUG)
        {
          std::cout << "option found: " << static_cast<char>(c) << std::endl;
          std::cout << "option index: " << option_index << std::endl;
        }

        if(optionMap.at(static_cast<char>(c)).o.has_arg)
        {
          optionMap.at(static_cast<char>(c)).val << std::string(optarg);
        }
        else
        {
          optionMap.at(static_cast<char>(c)).val << true;
        }
      }

      for(auto &kv : optionMap)
      {
        if(kv.second.o.has_arg == required_argument && kv.second.val.str().empty())
        {
          rv = false;
        }
      }

    }
    return rv;
  }
}
