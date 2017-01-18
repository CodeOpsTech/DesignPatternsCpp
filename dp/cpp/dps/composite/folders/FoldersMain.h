#ifndef FOLDERSMAIN
#define FOLDERSMAIN

#include <string>
#include <vector>
#include <iostream>

class FileItem
{
private:
	std::string name;
public:
	virtual std::string getName();
	virtual void setName(const std::string &name);
	virtual long long getSize() = 0;
	virtual ~FileItem(); 
};

class Folder : public FileItem
{
public:
	std::vector<FileItem*> files;
	Folder(const std::string &name, const std::vector<FileItem*>& files);
	virtual std::vector<FileItem*> getFiles();
	virtual long long getSize() override;
};

class File : public FileItem
{
private:
	long long size = 0;
public:
	File(const std::string &name, long long size);
	virtual long long getSize() override;
};

class ShortCut : public FileItem
{
public:
	FileItem *item;
	virtual ~ShortCut()
	{
		delete item;
	}

	ShortCut(const std::string &name, FileItem *item);
	virtual long long getSize() override;
};

#endif	//#ifndef FOLDERSMAIN
