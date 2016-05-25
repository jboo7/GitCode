#include <iostream>
#include <vector>
#include <dirent.h>
#include <sys\stat.h>
#include "file.hpp"
#include "folder.hpp"

using namespace std;

const string toString(char* str);

void toTree(shared_ptr<IFSItem>, const string);

int main(int argc, char** argv) {
    string dirpath("D:/GitCode");

    shared_ptr<IFSItem> root(new Folder("Root"));
    toTree(root, dirpath);

    root->draw();

    return 0;
}

const string toString(char* str) {
    return string(str);
}

void toTree(shared_ptr<IFSItem> parent, const string path) {
    struct stat s;
    struct dirent* entry;
    vector<string> dirs;
    vector<string> files;
    string filepath;

    DIR* dir = opendir(path.c_str());
    if (NULL != dir) {
        while (NULL != (entry = readdir(dir))) {
            string filename = toString(entry->d_name);

            if (!filename.compare("..") || !filename.compare(".") ||
                !filename.substr(0, 1).compare(".")) {
                continue;
            }
            filepath.clear();
            filepath.append(path);
            filepath.append("/");
            filepath.append(filename);

            stat(filepath.c_str(), &s);

            if (S_ISDIR(s.st_mode)) {
                dirs.push_back(filename);
            }
            if (S_ISREG(s.st_mode)) {
                files.push_back(filename);
            }
        }
    }
    closedir(dir);

    for (vector<string>::iterator it = dirs.begin(); it != dirs.end(); it++) {
        filepath.clear();
        filepath.append(path);
        filepath.append("/");
        filepath.append(*it);

        shared_ptr<IFSItem> child(new Folder(*it));
        parent->add(child);
        toTree(child, filepath);
    }
    for (vector<string>::iterator it = files.begin(); it != files.end(); it++) {
        shared_ptr<IFSItem> child(new File(*it));
        parent->add(child);
    }
}