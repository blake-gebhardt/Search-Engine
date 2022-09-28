//
// Created by Blake Gebhardt on 28.11.21.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_QUERYPROCESSOR_H
#define INC_21F_FINAL_PROJ_TEMPLATE_QUERYPROCESSOR_H

#include "docParser.h"


class queryProcessor {

private:



public:

    queryProcessor();



//will take in the entire line, tokenize, and decide what to return
    unordered_set<string> returnQuery(docParser &index, string &query);

    void showFullText(char* filePath);

    char* word_wrap (char* buffer, char* string, int line_width);
};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_QUERYPROCESSOR_H
