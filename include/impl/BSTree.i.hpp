/**
 * @author Elia Brentarolli, VR397594
 */
#pragma once

#include "../BTCell.hpp"
#include "../AbstractBTCell.hpp"
#include "../BSToperator.hpp"
#include <vector>
#include <algorithm>

template <typename T>
int BSTree<T>::_instancesNumber=0;  //inizializzazione numero di alberi
template <typename T>
BSTree<T>::BSTree(BTCell<T>& root){
    _root=root;
    _instancesNumber++;             //aumento numero di alberi ad ogni costruttore
}

template <typename T>
BSTree<T>::BSTree(std::vector<T>& values,std::string& insertionType){
    if(insertionType == "sorted"){              //ordianmento dei vettori
        std::sort(values.begin(),values.end());
        _root=new BTCell<T>(values[values.size()/2], nullptr, nullptr, nullptr); //creazione della radice come elemento
                                                                                // centrale della serie ordinata
        for(int i=values.size()/2-1; i>=0;i--) {
            insert(values[i]);                      //insserimento dei valori precedenti la radice
        }
        for(auto i=values.size()/2+1; i<values.size();i++) {
            insert(values[i]);                      //inserimento dei valori successivi alla radice
        }
    }
    else{
        _root=new BTCell<T>(values[0], nullptr, nullptr, nullptr);  //creazione della radice com il primo valore del vettore
        for(auto i : values) {
            insert(i);              //inserimento sequenzale dei valori
        }
    }
    _instancesNumber++; //aumento nuero di istanze
}

template <typename T>
BSTree<T>::BSTree(std::vector<T>& values){
    std::sort(values.begin(),values.end());
        _root=new BTCell<T>(values[values.size()/2], nullptr, nullptr, nullptr); //creazione della radice come elemento
                                                                                // centrale della serie ordinata
        for(int i=values.size()/2-1; i>=0;i--) {
            insert(values[i]);                      //insserimento dei valori precedenti la radice
        }
        for(auto i=values.size()/2+1; i<values.size();i++) {
            insert(values[i]);                      //inserimento dei valori successivi alla radice
        }
    _instancesNumber++; //aumento nuero di istanze
}

template <typename T>
BSTree<T>::~BSTree(){
    _root->destroy();       //distruzione dei sottoalberi
    delete _root;           //distruzione della radice
    _instancesNumber--;     //decremento numero di alberi
}
template <typename T>
void BSTree<T>::insert(T& value){
    if(search(value) == nullptr)    //verifica della presenza della nuova chiave
        _root->insert(new BTCell<T>(value,nullptr, nullptr, nullptr));  //chiave non presente: inserimento della nuova cella
    else std::cout<<"Impossibile inserire il valore specificato: chiave già presente\n"; //se esite già una chiave, l'operazione è rifiutata
}

template <typename T>
void BSTree<T>::remove(T& key){
    _root=remove(key, _root);   //assegnamento della nuova radice ottenuta dal metodo per la rimozione
}

template <typename T>
BTCell<T>* BSTree<T>::remove(T& key, BTCell<T>* node){
    if(node == nullptr)     //radice nulla: nessun risultatp
        return nullptr;
    if(key < node->getKey())    //ricerca nel sottalbero sinistro
        node->setLeft(remove(key, static_cast<BTCell<T>*>(node->getLeft())));
    else if(key > node->getKey())   //rierca nel sottoalbero destro
            node->setRight(remove(key, static_cast<BTCell<T>*>(node->getRight())));
    else {//eliminazione del nodo radice: aggiornamento dei puntatori
        if (node->getLeft() == nullptr) {   //figlio sinistro non esistente
            BTCell<T> *temp =  static_cast<BTCell<T>*>(node->getRight());
            delete node;
            return temp;
        }
        else if (node->getRight()== nullptr) {//filgio desrto non esistente
            BTCell<T> *temp =  static_cast<BTCell<T>*>(node->getLeft());
            delete node;
            return temp;
        }
        BTCell<T> *temp =  static_cast<BTCell<T>*>(node->getRight()->minSubTreeValue());
        node->setKey(temp->getKey());
        node->setRight(remove(temp->getKey(),static_cast<BTCell<T>*>(node->getRight())));
    }
    return node;

}

template <typename T>
const AbstractBTCell<T>* BSTree<T>::search(T& key){
    return _root->search(key);
}

template <typename T>
void BSTree<T>::print() {
    _root->print();
}

template <typename T>
void BSTree<T>::treeToVector(std::vector<T>& vect)const {
    _root->putInVector(vect);
}

template <typename T>
int BSTree<T>::treeNumbers(){
    return _instancesNumber;
}
