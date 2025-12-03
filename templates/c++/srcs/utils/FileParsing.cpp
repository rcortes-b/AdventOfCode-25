#include "../../inc/FileParsing.hpp"

FileParsing::FileParsing(char *path)
{
	this->path = std::string(path);
	std::ifstream myFile;
	this->openFile(myFile);
	this->readFile(myFile);
	this->closeFile(myFile);
}

std::string FileParsing::getContent()
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
		this->contentVector.push_back(line);
	}
	if (myFile.bad())
	{
		std::cerr << "Error: Something happened while reading the file" << std::endl;
		exit(1);
	}
	if (this->contentVector.size() == 1)
		this->content = this->contentVector.at(0);
	else
		this->content = "\0";
}

void FileParsing::closeFile(std::ifstream &myFile)
{
	myFile.close();
}