#ifndef VIEWER_H
#define VIEWER_H

#include <iostream>
#include <string>
#include "file.h"

class Viewer {
	File file;
	int lineMarker;
	int length;
	int width;

	public:
	Viewer(File &, const int length, const int width);
	void render();
	char getInput();
	void setFile(File &file);
	void next();
	void prev();
	void nextLine(const std::string & line, const int lineNumber);
	std::string getLink(const int link);
	int getMax() {
    	return file.getIndex();
	}
};

#endif
