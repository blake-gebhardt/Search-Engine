// TA Eric Miao

#include <iostream>
#include <fstream>
#include <dirent.h>
#include <filesystem>


#include "include/rapidjson/document.h"
#include "include/rapidjson/istreamwrapper.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/writer.h"

using namespace std;
namespace fs = std::filesystem;
using namespace rapidjson;

// absolute path to your dataset
char* path = "/Users/blakegebhardt/Desktop/jsons-for-search-engine";
char* filename = "/Users/blakegebhardt/Desktop/jsons-for-search-engine/jan/blogs_0000001.json";

// Using dirent to find and list all files in a directory
int open_dir_using_dirent(){
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (path)) != nullptr) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != nullptr) {
            printf ("%s\n", ent->d_name);
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        return EXIT_FAILURE;
    }
}



// Using C++ filesystem to find and list all files in a directory
void open_dir_using_filesystem(){
    for (const auto & entry : fs::directory_iterator(path)){
        string filenamer = entry.path().c_str();
        std::cout << filenamer << std::endl;

    }
}




void Parse(string& toParse){
    ifstream ifs(toParse);
    IStreamWrapper isw(ifs);

    Document document;
    document.ParseStream(isw);


    string paperID = document["uuid"].GetString();
    string titleName = document["title"].GetString();
    cout << "Paper id: " << paperID << endl;
    cout << "Title name: "<< titleName << endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
    string body_text = document["text"].GetString();

    cout << "\nBody text: \n" << body_text << endl;
    cout << endl;


}

void accessEachFile(){
    for (const auto & entry : fs::directory_iterator(path)){
        string filename = entry.path().c_str();
        cout << filename << endl;
        Parse(filename);

    }
}



