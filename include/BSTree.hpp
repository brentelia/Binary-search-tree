/**
 * @author Elia Brentarolli, VR397594
 * @mainpage ALBERO BIANRIO DI RICERCA
 * @brief Struttura che rappresenta un albero binario di ricerca.
 * @details La struttura rappresenta un albero binario di ricerca. Presenta come attributi un nodo radice, al quale
 * sono collegati i sottoalberi, e un numero statico di instanze. La struttura implementa diversi metodi per eseguire le
 * operazioni basilari su un BSTree.
 * @ref impl/BSTree.i.hpp
 */
#pragma once

#include "BTCell.hpp"
#include <vector>
/**
 * @brief Struttura rappresentante un albero binario di ricerca.
 * @tparam T il tipo delle chiavi che i nodi dell'albero dovranno contenere.
 */
template <typename K>
struct BSTree{
public:
    /**
     * @brief Costruttore dell'albero a partire da un singolo nodo radice.
     * @param root Il nodo radice.
     */
    BSTree(BTCell<K>& root);

    /**
     * @brief Costruttore dell'albero ottenuto dagli elementi del vector passato come argomento
     * @details Il metodo construisce l'albero a partire dagli elementi nel vector. Esistono due modalità d'uso:
     * specificando come opzione 'unsorted' nel secondo parmetro il metodo non eseguirà l'ordinamento del vector e
     * inserirà i valori nell'albero nell'ordine in cui sono specificati. Se invece si specifica come opzione 'sorted'
     * (di default) allora il vector verrà ordinato e i nodi saranno inseriti in modo da non generare un albero troppo
     * sbilanciato. In ogni caso i valori duplicati vengono scartati.
     * @param values il vector con i valori da inserire.
     * @param insertionType il modo in cui i valori vanno inseriti nell'albero.
     */
    BSTree(std::vector<K>& values ,std::string& insertionType);
    /**
     * @brief Costruttore dell'albero ottenuto dagli elementi del vector passato come argomento
     * @details Il metodo construisce l'albero a partire dagli elementi nel vector. Esistono due modalità d'uso:
     * specificando come opzione 'unsorted' nel secondo parmetro il metodo non eseguirà l'ordinamento del vector e
     * inserirà i valori nell'albero nell'ordine in cui sono specificati. Se invece si specifica come opzione 'sorted'
     * (di default) allora il vector verrà ordinato e i nodi saranno inseriti in modo da non generare un albero troppo
     * sbilanciato. In ogni caso i valori duplicati vengono scartati.
     * @param values il vector con i valori da inserire.
     */
    BSTree(std::vector<K>& values);
    /**
     * @brief Distruttore della struttura.
     */
    ~BSTree();
    /**
     * @brief Inserisce un nodo con chiave value nell'albero,i valori duplicati vengono scartati.
     * @param value La nuova chiave da inserire.
     */
    void insert(K& value);

    /**
     * @brief rimuove un nodo con chiave value nell'albero.
     * @param value La nuova chiave da eliminare.
     * @warning Se si elimina l'ultimo nodo di un albero, il valore di _root sarà posto a nullptr.
     */
    void remove(K& key);

    /**
     * @brief Ricerca una chiave nell'albero.
     * @param key la chiave da cercare.
     * @return il puntatore al nodo con la chiave.
     * @warning Se la chiave non è presente, nullptr viene ritornato.
     */
    const AbstractBTCell<K>* search(K& key);
    /**
     * @brief Stampa l'albero
     */
    void print();

    /**
     * @brief Inserisce i valori dell'albero nel vector.
     * @param vect il vector in cui vanno inseriti le chiavi dell'albero.
     */
    void treeToVector(std::vector<K>& vect) const;
    /**
     * @brief Ritorna il numero di alberi attualmente attivi
     * @return il numero di alberi attualmente attivi
     */
    static int treeNumbers();

protected:
    BTCell<K>* _root;               //radice dell'abero
    static int _instancesNumber;    //numero di istanze attive

private:
    /**
     * @brief Rimuove la chive key dall'albero con radice node.
     * @param key la chiave da eliminare.
     * @param node la radice dell'albero.
     * @return la radice dell'albero modificato.
     */
    BTCell<K>* remove(K& key, BTCell<K>* node);

};
#include "impl/BSTree.i.hpp"
