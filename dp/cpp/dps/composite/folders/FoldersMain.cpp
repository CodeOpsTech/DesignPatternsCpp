#include "FoldersMain.h"

std::string FileItem::getName()
{
	return name;
}

void FileItem::setName(const std::string &name)
{
	this->name = name;
}

FileItem::~FileItem()
{
}

Folder::Folder(const std::string &name, const std::vector<FileItem*>& files)
{
	setName(name);
	this->files = files;
}

std::vector<FileItem*> Folder::getFiles()
{
	return files;
}

long long Folder::getSize()
{
	long long size = 0;
	for (int i = 0; i < files.size(); i++)
	{
		size += files[i]->getSize();
	}
	return size;
}

File::File(const std::string &name, long long size)
{
	setName(name);
	this->size = size;
}

long long File::getSize()
{
	return size;
}

ShortCut::ShortCut(const std::string &name, FileItem *item)
{
	setName(name);
	this->item = item;
}

long long ShortCut::getSize()
{
	return item->getSize();
}

