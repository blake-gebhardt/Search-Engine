#include <iostream>
#include "include/rapidjson/document.h"
#include <fstream>
#include "catch_setup.h"
#include "docParser.h"
#include "indexHandler.h"
#include "searcher.h"


/*
 * SOME RELATIVE PATHS
 * /Users/blakegebhardt/Downloads/srch-ngn-data/size-10
 * /Users/blakegebhardt/Downloads/srch-ngn-data/size-221
 * /Users/blakegebhardt/Downloads/srch-ngn-data/size-6000
 * /Users/blakegebhardt/Downloads/srch-ngn-data/size-6000/2018_03_112b52537b67659ad3609a234388c50a
 * /Users/blakegebhardt/Desktop/jsons-for-search-engine
 */

//TAKES 8 MINUTES FOR THE FULL 306,000 docs


using namespace std;

int main(int argc, char **argv) {
    if (argc == 1) {
        runCatchTests();
    } else {


        indexHandler source;
        docParser test(source);
        queryProcessor qq;

        searcher google(test, qq);


        google.run(argv[1]);

        return 0;
    }
}