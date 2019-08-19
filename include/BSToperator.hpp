/**
 * @author Brentarolli Elia, VR397594
 * @brief Operatori su un albero binario di ricerca.
 * @details Overloading degli operatori '== 'e '+' su un albero binario di ricerca
 */
#pragma once

template <typename T>
struct BSTree;

template <typename T>
BSTree<T> operator+ (const BSTree<T>& ob1,const BSTree<T>& ob2);

template <typename T>
bool operator== (const BSTree<T>& ob1,const BSTree<T>& ob2);

#include "impl/BSToperator.i.hpp"