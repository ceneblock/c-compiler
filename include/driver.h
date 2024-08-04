#ifndef DRIVER_H
#define DRIVER_H
#include <string>
#include <map>
#include <getopt.h>
#include <cstdint>
#include <cstddef>
#include <sstream>
#include <vector>
namespace frontend
{
  class driver
  {
    protected:
      //forward declaration
      typedef std::string description;

      struct optionMapValue
      {
        option o;
        description d;
        std::stringstream val;
        optionMapValue(option o, description d):
        o(o), d(d)
        {
          val.str(std::string()); //clear it to nothing
        }
        optionMapValue(const optionMapValue &source):
          o(source.o), d(source.d)
        {
          val << source.val.rdbuf();
        }
      };

    public:
      driver();
  
      void addOptions(std::string options);

      void addArgs(int argc, char *argv[]);

      bool parse();

      std::map<char, std::stringstream> getParseResults();

      std::map<char, optionMapValue> &getOptionMap() { return optionMap; }

    protected:
      
      std::string options;
      
      //using a char so switch(optionMap[X].first)
      //Not making this const so optionMapValue.val can store something, but
      //also don't be stupid
      std::map<char, optionMapValue> optionMap =
      {
        {'c', optionMapValue({"codegen", no_argument, 0, 'c'}, "Perform lexical parsing, and assembly generation, but stop before code emission")},
        {'h', optionMapValue({"help", no_argument, 0, 'h'}, "Prints this help message and exits")},
        {'l', optionMapValue({"lex", no_argument, 0, 'l'}, "Run the lexer, but stop before parsing")},
        {'p', optionMapValue({"parse", no_argument, 0, 'p'}, "Run the lexer and parser, but stop before assembly generation")}
      };

      std::vector<option> longOptions;

      int argc;
      char **argv; //args. Saving for potential debugging purposes
      std::string getopt_string = "";
      //TODO: make this a parameter
      bool DEBUG = true;
  };
}
#endif
