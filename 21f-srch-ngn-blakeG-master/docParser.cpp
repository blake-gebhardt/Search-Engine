//
// Created by Blake Gebhardt on 16.11.21.
//

#include "docParser.h"


docParser::docParser(indexHandler &source) {
    dictionary = source;
    //build unordered set of the stop words
    ifstream stop("stops.txt");
    string line;
    while (getline(stop, line)) {
        stops.insert(line);
    }
    stop.close();
}


void docParser::Parse(string &toParse) {
    //TO PARSE IS THE RELATIVE PATH, VERY NICE
    ifstream ifs(toParse);
    rapidjson::IStreamWrapper isw(ifs);

    rapidjson::Document document;
    document.ParseStream(isw);

    string titleName = document["title"].GetString();
    string body_text = document["text"].GetString();


    //stem and stop removal
    stringstream reader(body_text);
    string wordToStem;

    while (reader.good()) {
        reader >> wordToStem;
        Porter2Stemmer::trim(wordToStem);
        //check if wordToStem is stop
        if (stops.count(wordToStem) == 0) {
            //stem
            Porter2Stemmer::stem(wordToStem);
            dictionary.addWordOrDoc(wordToStem, toParse);
            wordCounter++;

        }
    }

    const auto &orss = document["organizations"];
    assert(orss.IsArray());
    for (rapidjson::SizeType i = 0; i < orss.Size(); i++) { // Uses SizeType instead of size_t
        //printf("a[%d] = %s\n", i, orss[i].GetString());
        dictionary.addOrgOrDoc(orss[i].GetString(), toParse);
        orgCounter++;
    }

    const auto &peeps = document["entities"]["persons"];
    assert(peeps.IsArray());
    for (rapidjson::SizeType i = 0; i < peeps.Size(); i++) { // Uses SizeType instead of size_t
        //printf("a[%d] = %s\n", i, peeps[i]["name"].GetString());
        dictionary.addPerOrDoc(peeps[i]["name"].GetString(), toParse);
        perCounter++;
    }


}

void docParser::accessEachFile(char *&path) {
    int counter = 0;
        for (const auto &over : std::filesystem::directory_iterator(path)) {
            if (over.is_directory()){
            for (const auto &file : std::filesystem::directory_iterator(over.path().c_str())) {
                string filename = file.path().c_str();
                Parse(filename);
                //scrolling bar
                if (counter % 100 == 0) {
                    cout << ".";
                    cout.flush();
                }
                if (counter % 5000 == 0) {
                    cout << endl;
                }
                //lines for proof of concept and teting on smalle data sets
//        if (counter == 1000) {
//            break;
//        }
                counter++;

            }
        }
        cout << "\nNext file...\n";
        }
        cout << "Parsed " << counter << " files.\n";
    }


unordered_set<string> docParser::search(const string &query) {
    unordered_set<string> docs = dictionary.getDocs(query);
    return docs;
}

void docParser::printLevels(fstream &save) {
    dictionary.saveIndex(save);
}

docParser::docParser() {
    indexHandler dict;
    dictionary = dict;
}

void docParser::readFromPers(fstream &persist) {
    dictionary.clear();
    string wordLine;
    while (getline(persist, wordLine)){
        getline(persist, wordLine, '\n');
    }

}

void docParser::printFileData(string& x) {
    const char* path = (x.c_str());
    ifstream ifs(path);
    rapidjson::IStreamWrapper isw(ifs);

    rapidjson::Document document;
    document.ParseStream(isw);

    string titleName = document["title"].GetString();
    string body_text = document["text"].GetString();
    string author = document["author"].GetString();
    string date = document["published"].GetString();
    string publication = document["url"].GetString();

    cout << titleName << endl;
    cout << "By: " << author << endl;
    cout << "Published: " << date << endl;
    cout << "URL: " << publication << endl;
    cout << "____________________" << endl;


}

vector<string> docParser::searchPersons(const string &query) {
    return vector<string>(dictionary.getDocsPer(query));
}

vector<string> docParser::searchOrgs(const string &query) {
    return vector<string>(dictionary.getDocsOrg(query));
}




