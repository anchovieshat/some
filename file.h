#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>

class File {
	std::string name;
	std::vector<std::string> data;
	std::vector<std::string> links;

	public:
	File(const std::string &);

	std::string parseLinks(std::string &);

	const std::vector<std::string> &getData() const {
		return data;
	}

	const std::vector<std::string> &getLinks() const {
		return links;
	}

	const std::string &getName() const {
		return name;
	}

};

#endif
