#ifndef VIEWER_H
#define VIEWER_H

#include <iostream>
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
};

#endif
