#include <fstream>
#include <stdexcept>
#include <iostream>
#include "file.h"
using std::string;
using std::ifstream;

File::File(const string &name) : name(name) {
	string templine;
	ifstream file(name);
	if(file.fail()) {
		throw std::invalid_argument("Error opening file!");
	}
	while(!file.eof()) {
		std::getline(file, templine);
		data.push_back(parseLinks(templine));
	}
	if (data.size() != 0 && data[data.size() - 1] == "") {
		data.pop_back();
	}
}

string File::parseLinks(string &line) {
	size_t loc;
	size_t end;
	if(((loc = line.find("<a ")) != string::npos) && ((end = line.find(">", loc)) != string::npos)) {
		string link = line.substr(loc+3, end-(loc+3));
		links.push_back(link);
		line = line.substr(0, loc) + link.substr(link.find(' ')+1) + line.substr(end+1);
        return line;
	}
	return line;
}
