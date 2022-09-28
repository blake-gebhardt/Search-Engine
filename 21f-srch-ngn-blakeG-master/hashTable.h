//
// Created by Blake Gebhardt on 02.12.21.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_HASHTABLE_H
#define INC_21F_FINAL_PROJ_TEMPLATE_HASHTABLE_H


#include <vector>
#include <string>
using namespace std;

template<typename K, typename V>
class hashTable {

    //hash table is an array of vectors, a bucket is a vector of V
    //K is author
    //V is document


private:
    //table[K] = vector<V>
    vector<V> table[1000];
    int tableSize = 1000;



public:

    hashTable<K, V>() = default;

    hashTable& operator = (const hashTable<K,V> *&D ){
        table = D->table;
        return *this;
    }


    vector<V>& at(const K& key) {
        auto hash_val = hash<string>{}(key);
        int location = hash_val % tableSize;
        vector<V> &bucket = table[location];
        return bucket;
    }

    vector<V>& add(const K& key, const V& value) {
        auto hash_val = hash<string>{}(key);
        int location = hash_val % tableSize;
        vector<V> &bucket = table[location];
        bucket.emplace_back(value);
        return bucket;
    }


};




#endif //INC_21F_FINAL_PROJ_TEMPLATE_HASHTABLE_H
