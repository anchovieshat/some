#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>

class File {
	std::string name;
	std::vector<std::string> data;

	public:
	File(const std::string &);

	const std::vector<std::string> &getData() const {
		return data;
	}

	const std::string &getName() const {
		return name;
	}

};

#endif
