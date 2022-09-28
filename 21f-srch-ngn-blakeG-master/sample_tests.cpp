//
// Created by Blake Gebhardt on 11.11.21.
//

/**
 * This file contains some simple tests.
 *
 * DO NOT add the #define CATCH_CONFIG_RUNNER to this file.
 * It is already in catch_setup.cpp
 *
 * Note that you can have more than one cpp file with tests in them.
 * For example, you could have a test file for your DSString and a
 * separate one for your DSVector.
 */

#include "catch.hpp"
#include "avlTree.h"
#include "indexHandler.h"
#include "hashTable.h"


using namespace std;

TEST_CASE("Hash", "Browns"){
    hashTable<string, string> maccas;
    string burger = "big";
    string borger = "mac";
    string whop = "whopper";

    string chicken = "chicken";
    string nugs = "mcnuggets";

    string ice = "oreo";
    string cream = "mcflurry";

    SECTION("Adding and Accessing"){
        maccas.add(burger, borger);
        maccas.add(burger, whop);
        maccas.add(chicken, nugs);
        maccas. add(ice, cream);

        REQUIRE(maccas.at("big").at(0) == "mac");
        REQUIRE(maccas.at("big").at(1) == "whopper");
        REQUIRE(maccas.at("oreo").at(0) == "mcflurry");
        REQUIRE(maccas.at("chicken").at(0) == "mcnuggets");
    }

}



TEST_CASE("Nodes", "Trees") {

    avlTree<string, vector<int>> siberia;
    string test1 = "moscow";
    string test2 = "st pete";
    string test3 = "kiev";

    siberia.insert(test1).emplace_back(1);
    siberia.insert(test1).emplace_back(2);
    siberia.insert(test1).emplace_back(3);

    siberia.insert(test2).emplace_back(2);
    siberia.insert(test2).emplace_back(3);
    siberia.insert(test2).emplace_back(4);

    siberia.insert(test3).emplace_back(3);
    siberia.insert(test3).emplace_back(4);
    siberia.insert(test3).emplace_back(5);

    SECTION("Adding things to tree") {


        REQUIRE(siberia.insert(test1).at(0) == 1);
        REQUIRE(siberia.insert(test1).at(1) == 2);
        REQUIRE(siberia.insert(test1).at(2) == 3);

        REQUIRE(siberia.insert(test2).at(0) == 2);
        REQUIRE(siberia.insert(test2).at(1) == 3);
        REQUIRE(siberia.insert(test2).at(2) == 4);

        REQUIRE(siberia.insert(test3).at(0) == 3);
        REQUIRE(siberia.insert(test3).at(1) == 4);
        REQUIRE(siberia.insert(test3).at(2) == 5);

    }

    string test4 = "omsk";
    string test5 = "volgograd";
    string test6 = "vladivostok";

    siberia.insert(test4);
    siberia.insert(test5);
    siberia.insert(test6);

    siberia.insert(test4).emplace_back(1);
    siberia.insert(test4).emplace_back(2);
    siberia.insert(test4).emplace_back(3);

    siberia.insert(test5).emplace_back(2);
    siberia.insert(test5).emplace_back(3);
    siberia.insert(test5).emplace_back(4);

    siberia.insert(test6).emplace_back(3);
    siberia.insert(test6).emplace_back(4);
    siberia.insert(test6).emplace_back(5);

    SECTION("Height func") {

        REQUIRE(siberia.height() == 2);

    }

    SECTION("Make sure it's balanced") {
        //should be st pete at root
        REQUIRE(siberia.insert(test2).at(0) == 2);
        REQUIRE(siberia.insert(test2).at(1) == 3);
        REQUIRE(siberia.insert(test2).at(2) == 4);
    }


}

TEST_CASE("index handler"){

    avlTree<string, unordered_set<string>> russia;

    indexHandler dexter(russia);

    dexter.addWordOrDoc("putin", "1");
    dexter.addWordOrDoc("putin", "2");
    dexter.addWordOrDoc("putin", "3");

    dexter.addWordOrDoc("stalin", "2");
    dexter.addWordOrDoc("stalin", "3");
    dexter.addWordOrDoc("stalin", "4");

    dexter.addWordOrDoc("lenin", "1");
    dexter.addWordOrDoc("lenin", "3");
    dexter.addWordOrDoc("lenin", "4");

    SECTION("Give word, return vect"){
        unordered_set<string> putinSet = {"1","2","3"};
        unordered_set<string> stalinSet = {"2","3","4"};
        unordered_set<string> leninSet = {"1","3","4"};

        REQUIRE(dexter.getDocs("putin") == putinSet);
        REQUIRE(dexter.getDocs("stalin") == stalinSet);
        REQUIRE(dexter.getDocs("lenin") == leninSet);
    }



}