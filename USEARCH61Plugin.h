#ifndef USEARCH61PLUGIN_H
#define USEARCH61PLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class USEARCH61Plugin : public Plugin
{
public: 
 std::string toString() {return "USEARCH61";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;

};

#endif
