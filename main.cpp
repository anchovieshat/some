#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include "file.h"
#include "viewer.h"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv) {
	char command;
	int length;
	int width;
	std::string filepath;
	if(argc != 4) {
		std::cout << "Height of Viewer: ";
		std::cin >> length;
		std::cout << "Width of Text: ";
		std::cin >> width;
		if(std::cin.fail()) {
			std::cout << "Not a proper length or width" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			length = 25;
			width = 70;
		} else {
			if(length <= 0) {
				length = 1;
			}
			if(width <= 0) {
				width = 1;
			}
		}
	} else {
		length = atoi(argv[2]);
		width = atoi(argv[3]);
	}
	try {
		File file;
		if(argc != 1) {
			filepath = argv[1];
			file = File(filepath);
		}
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
					std::cout << "No link available for that value!" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				} else {
					try {
						File file(viewer.getLink(link));
						viewer.setFile(file);
					} catch (const std::invalid_argument &e) {
						std::cout << e.what() << endl;
					}
				}
			}
		}
	} catch ( const std::invalid_argument &e) {
		std::cout << e.what() << endl;
		return 1;
	}
	return 0;
}
