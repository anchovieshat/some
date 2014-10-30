#include <iostream>
#include <string>
#include <stdexcept>
#include "file.h"
#include "viewer.h"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv) {
	char command;
	int length;
	int width;
	if(argc < 2) {
		cerr << "Needs 1 or more argument(s)" << endl;
		return 1;
	}
	if(argc != 4) {
		std::cout << "Height of Viewer: ";
		std::cin >> length;
		std::cout << "Width of Text: ";
		std::cin >> width;
	} else {
		length = atoi(argv[2]);
		width = atoi(argv[3]);
	}
	try {
		File file(argv[1]);
		Viewer viewer(file, length, width);
		while(1) {
			viewer.render();
			command = viewer.getInput();
			if(command == 'q') {
				break;
			} else if(command == 'n') {
				viewer.next();
			} else if(command == 'p') {
				viewer.prev();
			} else if(command == 'o') {
				std::cout << "file: ";
				std::string name;
				std::cin >> name;
				try {
					File file(name);
					viewer.setFile(file);
				} catch (const std::invalid_argument &e) {
					std::cout << e.what() << endl;
				}
			} else if(command == 'g') {
				std::cout << "link number: ";
				int link;
				std::cin >> link;
				if(link > viewer.getMax() || link <= 0 || std::cin.fail()) {
					std::cin.clear();
					std::cout << "No link available for that value!" << std::endl;
				} else {
					File file(viewer.getLink(link));
					viewer.setFile(file);
				}
			}
		}
	} catch ( const std::invalid_argument &e) {
		std::cout << e.what() << endl;
		return 1;
	}
	return 0;
}
