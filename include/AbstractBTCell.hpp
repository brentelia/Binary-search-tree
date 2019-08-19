/**
 * @author Brentarolli Elia, VR397594
 */

#pragma once

#include "BTCell.hpp"
#include <vector>
/**
 * @brief Interfaccia per le celle di un qualsiasi albero binario.
 * @details La classe rappresenta un generico nodo di un albero binario con le funzioni ad essa connesse. Come ogni
 * nodo di un albero, questa classe possiede una chiave, il cui tipo è specificato dal template, due puntatori a due
 * nodi sottostanti, a destra e a sinistra, ed un eventuale puntatore al nodo padre.
 * La classe implementa svariate funzioni basilari per ogni nodo ma lascia da implementare quelle più importanti e che
 * variano a seconda del tipo di albero che si vuole creare.
 * @tparam K il tipo della chiave che la cella contiene.
 * @ref impl/Abstract.i.hpp
 */
template <typename K>
class AbstractBTCell{
public:

    /**
     * @brief Costruttore di classe.
     * @param value il valore da assegnare alla chiave.
     * @param l il puntatore al figlio sinistro del nodo.
     * @param r il puntatore al figlio destro del nodo.
     * @param up il puntatore al padre del nodo.
     */
    AbstractBTCell( K& value, AbstractBTCell<K>* l, AbstractBTCell<K>* r,AbstractBTCell<K>* up);
    /**
     * @brief Distruttore della classe.
     */
    virtual ~AbstractBTCell();
    /**
r    * @brief Metodo virtual per l'inserimento di una cella come filgia del nodo.
     * @param cell la cella da inserire come figlia.
     */
    virtual void insert(AbstractBTCell<K>* cell)=0;
    /**
     * @brief Metodo virtual per il ottenere del numero di nodi nel sottoalbero con radice il nodo corrente.
     * @return il numero di nodi nel sotoalbero con radice il nodo corrente.
     */
    virtual int size() =0;
    /**
     * @brief Metodo virtual per la ricerca di una chiave nel sottoalbero con radice il nodo corrente.
     * @param value la chiave da cercare.
     * @return il puntatore alla cella contenente la chiave, se presente.
     * @warning Se la chiave non è oresente viene ritornato nullptr.
     */
    virtual const AbstractBTCell<K>* search(K& value) =0;
    /**
     * @brief Metodo virtual per il ottenere la lunghezza massima del sottoalbero con radice il nodo corrente.
     * @return la lunghezza del massimo sottoalbero con radice il nodo corrente.
     */
    virtual int length()=0;

    /**
     *@brief Inserisce i nodi dell'albero nel vector specificato.
     *@param vect il vector in cui inserire i nodi.
     */
    void putInVector(std::vector<K>& vect);
    /**
     * @brief Invoca il metodo ricorsivamente sui sottoalberi destro e sinistro, distruggendoli.
     */
    void destroy() ;
    /**
     * @brief Stampa il contenuto del sottalbero sinistro, poi il contenuto del nodo ed infine il contenuto del
     * sottoalbero destro.
     * @param tabulations il numero di tabulazioni da usare per stampare la chiave.
     */
    void print(int tabulations =0);
    /**
     * @brief Ritorna la chiave del nodo.
     * @return la chiave del nodo.
     */
    K& getKey() ;
    /**
     * @brief Imposta la chiave del nodo.
     * @param value la nuova chiave del nodo.
     */
    void setKey(K& value);
    /**
     * @brief Ritorna il puntatore al nodo sinistro.
     * @return il puntatore al nodo sinistro.
     */
    AbstractBTCell<K>* getLeft();
    /**
     * @brief Imposta il figlio sinistro del nodo.
     * @param newLeft il nuovo figlio sinistro del nodo.
     */
    void setLeft(AbstractBTCell<K>* newLeft);
    /**
     * @brief Ritorna il puntatore al nodo destro.
     * @return il puntatore al nodo destro.
     */
    AbstractBTCell<K>* getRight();
    /**
     * @brief Imposta il figlio destro del nodo.
     * @param newRight il nuovo figlio destro del nodo.
     */
    void setRight(AbstractBTCell<K>* newRight);
    /**
     * @brief Ritorna il valore minimo presente nel sottoalbero sinistro.
     * @return il valore minimo presente nel sottoalbero sinistro.
     */
    AbstractBTCell* minSubTreeValue();
    /**
     * @brief Ritorna il numero massimo di filgi che il nodo può avere
     * @return
     */
    constexpr int getChild_number();

protected:
    K _key;                                 //chiave del nodo
    AbstractBTCell<K>* _left;               //filgio sinistro
    AbstractBTCell<K>* _right;              //filgio destro
    AbstractBTCell<K>* _up;                 //padre
    static constexpr int _child_number=2;
};

#include "impl/AbstractBTCell.i.hpp"