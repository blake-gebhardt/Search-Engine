//
// Created by Blake Gebhardt on 04.12.21.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_SEARCHER_H
#define INC_21F_FINAL_PROJ_TEMPLATE_SEARCHER_H

#include "docParser.h"
#include "queryProcessor.h"


class searcher {

private:

    docParser back;
    queryProcessor searchBar;

public:

    searcher(docParser &in, queryProcessor &en);

    void run(char* dataPath);


};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_SEARCHER_H
