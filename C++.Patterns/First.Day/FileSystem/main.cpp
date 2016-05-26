#include <iostream>
#include <vector>
#include <memory>

#include <dirent.h>
#include <sys\stat.h>

#include "file.hpp"
#include "folder.hpp"

using namespace std;

const string toString(const char* str);

void tree(const shared_ptr<IItem>, const string);

int main(int argc, char** argv) {
    if (argc < 2) {
        return -1;
    }
    string dirpath = toString(argv[1]);

    shared_ptr<IItem> dir(new Folder(dirpath));
    tree(dir, dirpath);

    dir->draw();

    return 0;
}

const string toString(const char* str) {
    return string(str);
}

void tree(const shared_ptr<IItem> parent, const string dirpath) {
    vector<string> dirs, files;
    struct dirent* direntry;
    struct stat st;
    string filepath, filename;

    DIR* dir = opendir(dirpath.c_str());
    if (NULL != dir) {
        while (NULL != (direntry = readdir(dir))) {
            filename.assign(direntry->d_name);

            if (!filename.compare(".") || !filename.compare("..") ||
                !filename.substr(0, 1).compare(".")) {
                continue;
            }

            filepath.assign(dirpath);
            filepath.append("/");
            filepath.append(filename);

            stat(filepath.c_str(), &st);

            if (S_ISDIR(st.st_mode)) {
                dirs.push_back(filename);
            }
            if (S_ISREG(st.st_mode)) {
                files.push_back(filename);
            }
        }
    }
    closedir(dir);
    for (vector<string>::iterator it = dirs.begin(); it != dirs.end(); it++) {
        filepath.assign(dirpath);
        filepath.append("/");
        filepath.append(*it);

        shared_ptr<IItem> folder(new Folder(*it));
        parent->add(folder);
        tree(folder, filepath);
    }
    for (vector<string>::iterator it = files.begin(); it != files.end(); it++) {
        parent->add(shared_ptr<IItem>(new File(*it)));
    }
}