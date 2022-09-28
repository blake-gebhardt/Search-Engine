//
// Created by Blake Gebhardt on 16.11.21.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_INDEXHANDLER_H
#define INC_21F_FINAL_PROJ_TEMPLATE_INDEXHANDLER_H

#include "avlTree.h"
#include "hashTable.h"
#include <string>
#include <unordered_set>
#include <iostream>
#include <fstream>

using namespace std;


class indexHandler {

private:
    avlTree<string, unordered_set<string>> index;
    hashTable<string, string> people;
    hashTable<string, string> orgs;

public:

    indexHandler();
    indexHandler(avlTree<string, unordered_set<string>> &source);

    void operator = (const indexHandler &copy );

    void clear();

    unordered_set<string> &addWordOrDoc(const string &newEntry, const string &doc);
    //willl call index.insert, then do addWord(<word>).emplace_back
    unordered_set<string> &getDocs(const string &word);


    vector<string> &addOrgOrDoc(const string &newOrg, const string &doc);
    vector<string> &addPerOrDoc(const string &newPer, const string &doc);

    vector<string> &getDocsOrg(const string &word);
    vector<string> &getDocsPer(const string &word);

    void saveIndex(fstream &save);

};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_INDEXHANDLER_H
