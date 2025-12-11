#include "../../inc/FileParsing.hpp"

FileParsing::FileParsing(const char *path)
{
	this->path = std::string(path);
	std::ifstream myFile;
	this->openFile(myFile);
	this->readFile(myFile);
	this->closeFile(myFile);
}

std::unordered_map<std::string, std::vector<std::string>> FileParsing::getContent()
{
	return (this->content);
}

std::vector<std::string> FileParsing::getContentVector()
{
	return (this->contentVector);
}

void FileParsing::openFile(std::ifstream &myFile)
{
	myFile.open(this->path, std::ios::in);
	if (!myFile.is_open()) {
		std::cerr << "Error: File could not be opened" << std::endl;
		exit(1);
	}
}

void FileParsing::readFile(std::ifstream &myFile)
{
	std::string line = "";
	while(std::getline(myFile, line))
	{
		std::stringstream ss(line);
		std::string str, key;
		std::vector<std::string> values;
		while (ss >> str) {
			if (str[str.length() - 1] == ':')
				key = str.substr(0, str.length() - 1);
			else
				values.push_back(str);
		}
		content.insert({key, values});
	}
	if (myFile.bad())
	{
		std::cerr << "Error: Something happened while reading the file" << std::endl;
		exit(1);
	}
}

void FileParsing::closeFile(std::ifstream &myFile)
{
	myFile.close();
}