//
// Created by Blake Gebhardt on 16.11.21.
//

#include "indexHandler.h"

 unordered_set<string> &indexHandler::addWordOrDoc(const string &newEntry, const string &doc) {

    index.insert(newEntry).insert(doc);
    return index.insert(newEntry);
}



unordered_set<string> &indexHandler::getDocs(const string &word) {
    return index.insert(word);
}

vector<string> &indexHandler::addOrgOrDoc(const string &newOrg, const string &doc) {
    return orgs.add(newOrg, doc);
}

vector<string> &indexHandler::addPerOrDoc(const string &newPer, const string &doc) {
    return people.add(newPer, doc);
}

void indexHandler::operator=(const indexHandler &copy) {
    index = copy.index;
    people = copy.people;
    orgs = copy.orgs;

}

indexHandler::indexHandler(avlTree<string, unordered_set<string>> &source) {

}
//use a level order traversal to save the index, no rotations necessary to read back in
void indexHandler::saveIndex(fstream &save) {
    index.levelOrderTraversal(save);
}

vector<string> &indexHandler::getDocsOrg(const string &word) {
    return orgs.at(word);
}

vector<string> &indexHandler::getDocsPer(const string &word) {
    return people.at(word);
}

void indexHandler::clear() {
    index.clear();
}


indexHandler::indexHandler() = default;




