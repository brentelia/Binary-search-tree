/**
 * @author Elia Brentarolli,VR397594
 * @brief Classe che rappresenta un nodo in un albero bianrio di ricerca.
 * @details La classe rappresenta un nodo generico in un albero binario di ricerca, andando ad estendere la classe
 * templatica AbstractBTCell implementandone i metodi virtual.
 * @ref impl/BTCell.i.hpp
 */

#pragma once

#include "AbstractBTCell.hpp"
/**
 * @brief Classe che rappresenta un nodo in un albero bianrio di ricerca.
 * @tparam K tipo della chiave del nodo.
 */
template <typename K>
class BTCell:public AbstractBTCell<K> {
public:
    /**
     * @brief Costruttore di classe,
     * @param key chiave del nodo.
     * @param l figlio sinistro del nodo.
     * @param r figlio destro del nodo.
     * @param u padre del nodo.
     */
    BTCell(K& key, BTCell<K>*l, BTCell<K>*r,BTCell<K>* u);
    /**
     * @brief Distruttore di classe.
     */
    virtual ~BTCell();
    /**
     * @brief Inserimento di una cella nel sottoalbero.
     * @param cell la nuova cella da inserire.
     */
    void insert(AbstractBTCell<K>* cell) override;
     /**
     * @brief Metodo per il ottenere del numero di nodi nel sottoalbero con radice il nodo corrente.
     * @return il numero di nodi nel sotoalbero con radice il nodo corrente.
     * */
    int size() override ;
    /**
     * @brief Metodo per il ottenere la lunghezza massima del sottoalbero con radice il nodo corrente.
     * @return la lunghezza del massimo sottoalbero con radice il nodo corrente.
     */
    int length() override ;
    /**
    * @brief Metodo per la ricerca di una chiave nel sottoalbero con radice il nodo corrente.
    * @param value la chiave da cercare.
    * @return il puntatore alla cella contenente la chiave, se presente.
    * @warning Se la chiave non è oresente viene ritornato nullptr.
    */
    const AbstractBTCell<K>* search(K& value) override ;
};

#include "impl/BTCell.i.hpp"