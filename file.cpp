#include <fstream>
#include <stdexcept>
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
		data.push_back(templine);
	}
	if (data.size() != 0 && data[data.size() - 1] == "") {
		data.pop_back();
	}
}
