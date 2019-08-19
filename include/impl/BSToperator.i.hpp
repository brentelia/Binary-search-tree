/**
 * @author Elia Brentarolli VR397594
 */

#pragma once

#include "../BSTree.hpp"
#include <algorithm>

template <typename T>
BSTree<T> operator+(const BSTree<T>& ob1,const BSTree<T>& ob2){
    std::vector<T> vect1= std::vector<T>();
    std::vector<T> vect2= std::vector<T>();
    ob1.treeToVector(vect1);                //conversione dei due alberi a vettori
    ob2.treeToVector(vect2);
    std::vector<T> vect3=std::vector<T>();
    for(auto &i: vect1)
        vect3.push_back(i);                 //fusione dei due vettori in un unico
    for(auto &i: vect2)
        vect3.push_back(i);
    return BSTree<T> (vect3);           //creazione di un nuovo albero a partire dal vettore creato
}

template <typename T>
bool operator== (const BSTree<T>& ob1,const BSTree<T>& ob2){
    std::vector<T> vect1= std::vector<T>();
    std::vector<T> vect2= std::vector<T>();
    ob1.treeToVector(vect1);                //conversione dei due alberi a vettori
    ob2.treeToVector(vect2);
    return vect1==vect2;                    //confronto tra i vettori
}
