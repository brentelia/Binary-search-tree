#pragma once

#include <iostream>
template <typename T>
AbstractBTCell<T>::AbstractBTCell(T& value, AbstractBTCell<T>* l, AbstractBTCell<T>* r,AbstractBTCell<T>*u):
                    _key(value),_left(l),_right(r),_up(u){}

template <typename T>
AbstractBTCell<T>::~AbstractBTCell(){}

template <typename T>
void AbstractBTCell<T>::destroy() {
    if(_left!= nullptr){    //distruzione del sottoalbero sinistro
        std::cout<<"Eliminazione a sinistra di "<<_key<<"\n";
        _left->destroy();
        delete _left;       //eliminazione del nodo
    }
    if(_right!= nullptr){   //distruzione sottoalbero destro
        std::cout<<"Eliminazione a destra di "<<_key<<"\n";
        _right->destroy();
        delete _right;      //eliminazione nodo
    }
}


template <typename T>
void AbstractBTCell<T>::print(int tabulations){
    if(_left != nullptr) {              //stampa sottoalbero sinistro
        _left->print(tabulations + 1);
    }
    for(int i=0;i<tabulations;i++)      //stampa chiave
        std::cout<<"\t";
    std::cout<<_key<<"\n";
    if(_right != nullptr) {             //stampa sottoalbero destro
        _right->print(tabulations + 1);
    }
}

template <typename T>
T& AbstractBTCell<T>::getKey(){
    return _key;
}


template <typename T>
 AbstractBTCell<T>* AbstractBTCell<T>::getLeft() {
    return _left;
}

template <typename T>
 AbstractBTCell<T>* AbstractBTCell<T>::getRight() {
    return  _right;
}

template <typename T>
void AbstractBTCell<T>::setLeft(AbstractBTCell<T>* newLeft){
    _left=newLeft;
}
template <typename T>
void AbstractBTCell<T>::setRight(AbstractBTCell<T>* newRight){
    _right=newRight;
}

template <typename T>
void AbstractBTCell<T>::setKey(T &value) {
    _key=value;
}

template <typename K>
void AbstractBTCell<K>::putInVector(std::vector<K>& vect){
    if(_left!= nullptr)             //inserimento nel vettore del sottoablero sinistro
        _left->putInVector(vect);
    vect.push_back(_key);           //inserimento della chiave
    if(_right!= nullptr)            //inserimento nel vettore del sottoablero destro
        _right->putInVector(vect);
}

template <typename K>
AbstractBTCell<K>* AbstractBTCell<K>::minSubTreeValue(){
    auto temp=this;
    while(temp->_left!= nullptr){   //ricerca iterativa del minimo valore nel sottoablero sinistro
        temp=temp->_left;
    }
    return temp;
}

template <typename T>
constexpr int AbstractBTCell<T>::getChild_number(){
    return _child_number;
}