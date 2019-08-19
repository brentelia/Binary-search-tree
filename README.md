Elia Brentarolli

## DESCRIZIONE DEL PROGETTO:

Il progetto sviluppa una piccola libreria per l'implementazione delle componenti principali per la realizzazione di un albero binario.
La libreria si compone di una classe templatica virtuale AbstractBTCell che rappresenta un generico nodo in un albero binario e che, sebbene fornisca alcune componenti di base, lascia da implementare tutti i metodi che dipendono dal tipo di albero che si vuole implementare. La classe BTCell estende AbstractBTCell con lo scopo di implementare tutte le funzioni di un classico albero binario di ricerca. Infine la classe BTree raccoglie al suo interno le BTCell e fornisce un collegamento tra i singoli nodi, difficili da gestire singolarmente in un programma, e il resto del programma.

##INSTALLAZIONE:

dalla directory build eseguire ```cmake ../```

dopo questa operazione sarà generato un makefile con i seguenti target:

* make : compila il programma generando il file eseguibile BTreeTest (contenenete i test) e la libreria Bianry_Search_Tree.
* make install: copia il file eseguibile in bin/
* make install_and_move: sposta il file eseguibile in bin/
* make test: esegue tutti i test
* make valgrind: esegue valgrind sul programma
* make doc: genera la documentazione doxygen in formato html e latex nella directory doc 
