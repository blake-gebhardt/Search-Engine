//
// Created by Blake Gebhardt on 16.11.21.
//Iterating filesystem done by Eric Mao.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_DOCPARSER_H
#define INC_21F_FINAL_PROJ_TEMPLATE_DOCPARSER_H

#include <iostream>
#include "include/rapidjson/document.h"
#include <fstream>
#include "indexHandler.h"


#include "porter2_stemmer.h"
#include <sstream>

#include <iostream>
#include <fstream>
#include <dirent.h>
#include <filesystem>
#include <unordered_set>


#include "include/rapidjson/istreamwrapper.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/writer.h"



class docParser {

private:
        indexHandler dictionary;

        std::unordered_set<string> stops;


public:
    docParser();
    //construct a docParson with the indexHandler
    docParser(indexHandler& source);

    int wordCounter = 0;
    int orgCounter = 0;
    int perCounter = 0;



    inline void Parse(string& toParse);

    void readFromPers(fstream &persist);

    void accessEachFile(char * &path);

    //if word is in title, show those docs first

    unordered_set<string> search(const string& query);

    vector<string> searchPersons(const string& query);

    vector<string> searchOrgs(const string& query);

    void printLevels(fstream &save);

    void printFileData(string &x);




};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_DOCPARSER_H