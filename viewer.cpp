#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "viewer.h"

Viewer::Viewer(File &file, const int length, const int width) : file(file), lineMarker(0), length(length), width(width) {
	setFile(file);
}

void Viewer::render() {
	std::string name = file.getName();
	std::cout << name.substr(name.rfind('/')+1) << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	for(int i = 0; i < length; i++) {
		nextLine(file.getData()[i+lineMarker], i+lineMarker+1);
	}
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "  next  previous  open  go  quit" << std::endl;
	std::cout << "-------" << std::endl;
}

void Viewer::setFile(File &file) {
	this->file = file;
	lineMarker = 0;
	if(length > (int)file.getData().size())
		length = file.getData().size();
	auto data = file.getLinks();
	for(int i = 0; i < (int) data.size(); i++) {
		std::cout << data[i] << " [" << (i+1) << "]" <<  std::endl;
	}
	std::cout << std::endl;
}

char Viewer::getInput() {
	std::cout << "command: ";
	char command;
    std::cin >> command;
	return command;
}

void Viewer::next() {
	if((lineMarker + length*2) >= int(file.getData().size())) {
		lineMarker = int(file.getData().size()) - length;
	} else {
		lineMarker += length;
	}
}

void Viewer::prev() {
	if((lineMarker - length) > 0) {
		lineMarker -= length;
	} else {
		lineMarker = 0;
	}
}

void Viewer::nextLine(const std::string &line, const int lineNumber) {
	if(line.length() <= uint(width)) {
		if (lineNumber == 0) {
			std::cout << "   " << line << std::endl;
		} else {
			std::cout << std::setw(floor(log10(file.getData().size()))+1) << lineNumber << " " << line << std::endl;
		}
	} else {
		if(line[width] == ' ') {
			nextLine(line.substr(0,width), lineNumber);
			nextLine(line.substr(width+1), 0);
		} else {
			size_t split_point = line.rfind(' ', width);
			if (split_point == std::string::npos) {
				split_point = line.find(' ');
				if(split_point == std::string::npos) {
					std::cout << "    " << line << std::endl;
					return;
				}
			}
			nextLine(line.substr(0, split_point), lineNumber);
			nextLine(line.substr(split_point+1), 0);
		}
	}
}

std::string Viewer::getLink(const int link) {
	std::string line = file.getLinks()[link-1];
	line = line.substr(0, line.find(' '));
	return line;
}

