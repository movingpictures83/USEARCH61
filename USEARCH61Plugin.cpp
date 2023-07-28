#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "USEARCH61Plugin.h"

void USEARCH61Plugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void USEARCH61Plugin::run() {}

void USEARCH61Plugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "pick_otus.py";
myCommand += " ";
myCommand += "-i";
myCommand += " "+std::string(PluginManager::prefix())+"/";
myCommand += parameters["fastafile"];
myCommand += " ";
myCommand += "-m";
myCommand += " ";
myCommand += "usearch61";
myCommand += " ";
myCommand += "--db_filepath=";
myCommand += parameters["database"];
myCommand += " -o";
myCommand += " ";
myCommand += file;
myCommand += " ";
myCommand += "--word_length";
myCommand += " ";
myCommand += parameters["wordlength"];
myCommand += " ";
system(myCommand.c_str());
std::cout << myCommand << std::endl;
}

PluginProxy<USEARCH61Plugin> USEARCH61PluginProxy = PluginProxy<USEARCH61Plugin>("USEARCH61", PluginManager::getInstance());
