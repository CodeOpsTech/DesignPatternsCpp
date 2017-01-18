#include "FoldersMain.h"

int main(int argc, const char** argv)
{
	File *fileOne = new File("File1", 100);
	Folder *folderTwo = new Folder("folder1", std::vector<FileItem*> {new File("File2", 200)});
	File *fileThree = new File("File3", 300);
	ShortCut *fileThreeAlias = new ShortCut("FileThreeAlias", fileThree);
	std::vector<FileItem*> fileItems = {fileOne, folderTwo, fileThreeAlias};
	FileItem *f = new Folder("Folder", fileItems);
	std::cout << std::string("Folder size: ") << f->getSize() << std::endl;
}
