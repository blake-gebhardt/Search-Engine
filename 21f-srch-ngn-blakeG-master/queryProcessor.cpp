//
// Created by Blake Gebhardt on 28.11.21.
//

#include "queryProcessor.h"

queryProcessor::queryProcessor() {

}


unordered_set<string> queryProcessor::returnQuery(docParser &index, string &query) {
    unordered_set<string> queryDocs;
    vector<string> printVec;
    stringstream ss(query);
    string first;
    getline(ss, first, ' ');
    if ((first != "AND") && (first != "OR")) {
        cout << "We found: " << endl;
        int counter = 0;
        for (auto &x : index.search(first)) {
            if (counter < 15) {
                queryDocs.insert(x);
                printVec.emplace_back(x);
                counter++;
            }
        }

        int counter1 = 0;
        for (auto &x: printVec) {
            if (counter1 < 15) {
                index.printFileData(const_cast<string &>(x));
                counter++;
            }
        }
        cout << "Enter a number to read the text: \n";
        int read;
        cin >> read;
        switch (read) {
            case 1:
                showFullText(const_cast<char *>(printVec[0].c_str()));
                break;
            case 2:
                showFullText(const_cast<char *>(printVec[1].c_str()));
                break;
            case 3:
                showFullText(const_cast<char *>(printVec[2].c_str()));
                break;
            case 4:
                showFullText(const_cast<char *>(printVec[3].c_str()));
                break;
            case 5:
                showFullText(const_cast<char *>(printVec[4].c_str()));
                break;
            case 6:
                showFullText(const_cast<char *>(printVec[5].c_str()));
                break;
            case 7:
                showFullText(const_cast<char *>(printVec[6].c_str()));
                break;
            case 8:
                showFullText(const_cast<char *>(printVec[7].c_str()));
                break;
            case 9:
                showFullText(const_cast<char *>(printVec[8].c_str()));
                break;
            case 10:
                showFullText(const_cast<char *>(printVec[9].c_str()));
                break;
            case 11:
                showFullText(const_cast<char *>(printVec[10].c_str()));
                break;
            case 12:
                showFullText(const_cast<char *>(printVec[11].c_str()));
                break;
            case 13:
                showFullText(const_cast<char *>(printVec[12].c_str()));
                break;
            case 14:
                showFullText(const_cast<char *>(printVec[13].c_str()));
                break;
            case 15:
                showFullText(const_cast<char *>(printVec[14].c_str()));
                break;
        }




        return index.search(first);

    } else {
        string term;

        vector<string> termsVec;
        string person;
        string org;
        string nots = "a";
        while (
                getline(ss, term,' ')) {
            if (((first == "AND") || (first == "OR")) && ((term != "ORG") && (term != "PERSON") && (term != "NOT"))) {
                Porter2Stemmer::stem(term);
                termsVec.push_back(term);
            }
            if (term == "ORG") {
                getline(ss, term,' ');
                org = term;
            } else
            if (term == "PERSON") {
                getline(ss, term,' ');
                person = term;
            } else
            if (term == "NOT") {
                getline(ss, term,' ');
                nots = term;
            }

        }
//terms vec is now all of the things i need to intersect
//then run through terms vec and keep files with person and org (no orgs so just discard)
//remove things with nots in it

//need to grab the doc set of all the AND/OR items;


        if (first == "AND") {
//for every x codument in first term's set
            for (auto &x: index.search(termsVec[0])) {
//if x also exists in second term's set
                if (index.search(termsVec[1]).count(x) > 0) {
//add x to my AND set
                    queryDocs.insert(x);
                    printVec.emplace_back(x);
                }
            }
        }

        if (first == "OR") {
            for (auto &x: index.search(termsVec[0])) {
                queryDocs.insert(x);
                printVec.emplace_back(x);
            }
            for (auto &x: index.search(termsVec[1])) {
                queryDocs.insert(x);
                printVec.emplace_back(x);
            }
        }
    //notting, x is a document
    //for every document query, if x is also in nots documents
    //remove x
        for (auto &x: queryDocs) {
            if (index.search(nots).count(x) > 0) {
            //remove and
                queryDocs.erase(x);

            }
        }

        for (auto &x : index.searchPersons(person)) {
            queryDocs.insert(x);
            printVec.emplace_back(x);
        }


        cout << "We found: " << endl;
        int counter = 0;
        for (auto &x: printVec) {
            if (counter < 15) {
                index.printFileData(const_cast<string &>(x));
                counter++;
            }
        }

        termsVec.clear();
        queryDocs.clear();
    }


    cout << "Enter a number to read the text: \n";
    int read;
    cin >> read;
    switch (read) {
        case 1:
            showFullText(const_cast<char *>(printVec[0].c_str()));
            break;
        case 2:
            showFullText(const_cast<char *>(printVec[1].c_str()));
            break;
        case 3:
            showFullText(const_cast<char *>(printVec[2].c_str()));
            break;
        case 4:
            showFullText(const_cast<char *>(printVec[3].c_str()));
            break;
        case 5:
            showFullText(const_cast<char *>(printVec[4].c_str()));
            break;
        case 6:
            showFullText(const_cast<char *>(printVec[5].c_str()));
            break;
        case 7:
            showFullText(const_cast<char *>(printVec[6].c_str()));
            break;
        case 8:
            showFullText(const_cast<char *>(printVec[7].c_str()));
            break;
        case 9:
            showFullText(const_cast<char *>(printVec[8].c_str()));
            break;
        case 10:
            showFullText(const_cast<char *>(printVec[9].c_str()));
            break;
        case 11:
            showFullText(const_cast<char *>(printVec[10].c_str()));
            break;
        case 12:
            showFullText(const_cast<char *>(printVec[11].c_str()));
            break;
        case 13:
            showFullText(const_cast<char *>(printVec[12].c_str()));
            break;
        case 14:
            showFullText(const_cast<char *>(printVec[13].c_str()));
            break;
        case 15:
            showFullText(const_cast<char *>(printVec[14].c_str()));
            break;
    }
    printVec.clear();

    return queryDocs;
}

void queryProcessor::showFullText(char *filePath) {

    ifstream ifs(filePath);
    rapidjson::IStreamWrapper isw(ifs);

    rapidjson::Document document;
    document.ParseStream(isw);

    string titleName = document["title"].GetString();
    string body_text = document["text"].GetString();
    char out[10000];

    cout << "Full text of " << word_wrap(out, const_cast<char *>(body_text.c_str()), 80) << "." << endl;

}

//from https://www.cprogramming.com/snippets/source-code/word-wrap-in-c
char* queryProcessor::word_wrap (char* buffer, char* string, int line_width) {
    int i = 0;
    int k, counter;

    while(i < strlen( string ) )
    {
        // copy string until the end of the line is reached
        for ( counter = 1; counter <= line_width; counter++ )
        {
            // check if end of string reached
            if ( i == strlen( string ) )
            {
                buffer[ i ] = 0;
                return buffer;
            }
            buffer[ i ] = string[ i ];
            // check for newlines embedded in the original input
            // and reset the index
            if ( buffer[ i ] == '\n' )
            {
                counter = 1;
            }
            i++;
        }
        // check for whitespace
        if ( isspace( string[ i ] ) )
        {
            buffer[i] = '\n';
            i++;
        }
        else
        {
            // check for nearest whitespace back in string
            for ( k = i; k > 0; k--)
            {
                if ( isspace( string[ k ] ) )
                {
                    buffer[ k ] = '\n';
                    // set string index back to character after this one
                    i = k + 1;
                    break;
                }
            }
        }
    }
    buffer[ i ] = 0;

    return buffer;}
