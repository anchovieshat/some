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
	Viewer(const File &, const int length, const int width);
	void render();
	char getInput();
	void setFile(const File &file) {
		this->file = file;
		lineMarker = 0;
		if(length > (int)file.getData().size())
			length = file.getData().size();
	}
	void next();
	void prev();
	void nextLine(const std::string & line, const int lineNumber);
};

#endif
