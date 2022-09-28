//
// Created by Blake Gebhardt on 11.11.21.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_AVLTREE_H
#define INC_21F_FINAL_PROJ_TEMPLATE_AVLTREE_H


#include <algorithm>
#include <list>
#include <iostream>
#include <fstream>


template<typename K, typename V>
class avlNode {
public:
    K element;
    V extra;
    avlNode<K, V> *left;
    avlNode<K, V> *right;
    int height;


    //memberwise copy constructor
    avlNode<K, V>(const K &theElement, const V &theExtra, avlNode *lt, avlNode *rt, int h = 0) :
            element(theElement), extra(theExtra), left(lt), right(rt), height(h){}

    avlNode<K, V>(const K &theElement, avlNode *lt, avlNode *rt) {
        element = theElement;
        left = lt;
        right = rt;
        height = 0;

    }


    static avlNode<K, V> *copyNodes(avlNode<K, V> *&t) {
        if (t != nullptr) {
            avlNode<K, V> *left = copyNodes(t->left);
            avlNode<K, V> *right = copyNodes(t->right);
            return new avlNode(t->element, t->extra, left, right);
        } else {
            return nullptr;
        }
    }

};

template<typename K, typename V>
class
avlTree {
private:
    avlNode<K, V> *root;




     V &insert(const K &x, avlNode<K, V> *&t) {
        if (t == nullptr) {
            t = new avlNode<K, V>(x, nullptr, nullptr);
            nodes++;
            return t->extra;
        } else if (x < t->element) {
            V &temp = insert(x, t->left);
            balance(t);
            return temp;
        } else if (t->element < x) {
            V &temp = insert(x, t->right);
            balance(t);
            return temp;
        } else if (t->element == x) {
            return t->extra;
        }


    }

public:
    avlTree() : root(nullptr) {}
    int nodes = 1;

    avlTree& operator = (const avlTree<K,V> *&D ){
         root = copyNodes(D->root);
         return *this;
     }

    avlTree(const avlTree<K, V> *&rhs) {
        root = copyNodes(rhs->root);
    }

   inline ~avlTree() {
        makeEmpty(root);
    }

    inline int height(avlNode<K, V> *v) {
        //rather than just getting the height var, need to account for empties
        if (v == nullptr) {
            return -1;
        }
        return v->height;
    }

    int height() {
        //rather than just getting the height var, need to account for empties
        if (root == nullptr) {
            return -1;
        }
        return root->height;
    }

    inline void clear(){
        makeEmpty(root);
     }

    inline void makeEmpty(avlNode<K, V> *&breaker) {
        //use post order transversal to delete
        //children first
        //"Not just the men, but the women and children too." -Anakin Skywalker
        if (breaker != nullptr) {
            makeEmpty(breaker->left);
            makeEmpty(breaker->right);
            delete breaker;
        }
    }

    inline V &insert(const K &x) {
        nodes++;
        return insert(x, root);
    }


    inline void balance(avlNode<K, V> *&t) {
        if (t == nullptr) {
            return;
        }
        if (height(t->left) - height(t->right) > 1) {
            if (height(t->left->left) >= height(t->left->right)) {
                //handle case 1
                rotateWithLeftChild(t);
            } else {
                //handle case 2
                doubleWithLeftChild(t);
            }
        } else {
            if (height(t->right) - height(t->left) > 1) {
                if (height(t->right->right) >= height(t->right->left)) {
                    //handle case 4
                    rotateWithRightChild(t);
                } else {
                    //handle case 3
                    doubleWithRightChild(t);
                }
            }
        }

        t->height = std::max(height(t->left), height(t->right)) + 1;
    }

    //rotations!

    inline void rotateWithLeftChild(avlNode<K, V> *&k2) {
        avlNode<K, V> *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = std::max(height(k2->left), height(k2->right)) + 1;
        k1->height = std::max(height(k1->left), k2->height) + 1;
        k2 = k1;

    }

    inline void doubleWithLeftChild(avlNode<K, V> *&k3) {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);

    }

    inline void rotateWithRightChild(avlNode<K, V> *&k2) {
        avlNode<K, V> *k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = std::max(height(k2->left), height(k2->right)) + 1;
        k1->height = std::max(height(k1->right), k2->height) + 1;
        k2 = k1;
    }

    inline void doubleWithRightChild(avlNode<K, V> *&k3) {
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }

    //BORROWED FROM HERE
    //https://www.techiedelight.com/level-order-traversal-binary-tree/
    void levelOrderTraversal(std::fstream &save)
    {
        // base case
        if (this->root == nullptr) {
            return;
        }

        // create an empty queue and enqueue the root node
        std::list<avlNode<K, V>*> queue;
        queue.push_back(this->root);

        // pointer to store the current node
        avlNode<K, V>* curr = nullptr;

        // loop till queue is empty
        while (queue.size())
        {
            // process each node in the queue and enqueue their
            // non-empty left and right child
            curr = queue.front();
            queue.pop_front();

            save << curr->element << ", ";
            for (auto x : curr->extra){
                save << x << ", ";
            }
            save << std::endl;


            if (curr->left) {
                queue.push_back(curr->left);
            }

            if (curr->right) {
                queue.push_back(curr->right);
            }
        }
    }




};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_AVLTREE_H
