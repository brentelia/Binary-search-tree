#pragma once
template <typename T>
BTCell<T>::BTCell(T &k, BTCell<T> *l, BTCell<T> *r,BTCell<T> *u):AbstractBTCell<T>(k,l,r,u){}

template<typename T>
BTCell<T>::~BTCell(){}

template <typename T>
void BTCell<T>::insert(AbstractBTCell<T>* cell) {
    auto newcell=static_cast<BTCell<T>*>(cell); //conversione della cella allo stesso tipo di quella corrente
    if (newcell->_key < this->_key) {   //inserimento nel sottoalbero sinistro
        if(this->_left== nullptr) {    //inserimento della cella come figlio sinistro diretto
            this->_left = newcell;
            newcell->_up=this;
        }
        else
            this->_left->insert(cell); //inserimento nel sottoalbero sinistro
    }
    else if(this->_right== nullptr) { //inserimento nel sottoalbero destro
            this->_right= newcell;
            newcell->_up=this;         //inserimento della cella come figlio destro diretto
        }
    else
        this->_right->insert(cell);     //inserimento nel sottoalbero destro
}


template <typename T>
int BTCell<T>::size(){
    int total=1;
    if(this->_left != nullptr)
        total+=this->_left->size();     //calcolo dimensione del sottoalbero sinistro e aggiunta al totale
    if(this->_right != nullptr)
        total+=this->_right->size();    //calcolo dimensione del sottoalbero destro e aggiunta al totale
    return total;
}
template <typename T>
int BTCell<T>::length() {
    int size=0;
    if(this->_left != nullptr)
        size=this->_left->length();     //calcolo dimensione del sottoalbero sinistro
    if(this->_right != nullptr){
        int temp=this->_right->length();//calcolo dimensione del sottoalbero destro e sostituzione del nuovo valore se
                                        //supera quello precedente
        if(temp>size)
            size=temp;
        }
    return size+1;
}


template <typename K>
const AbstractBTCell<K>* BTCell<K>::search(K& value){
    if(value==this->_key)       //chiave coincide con quella del nodo corrente
        return this;
    if (value<this->_key){      //ricerca nel sottoalbero sinistro se presente
        if(this->_left== nullptr)
            return nullptr;
        else return this->_left->search(value);
    }
    if(this->_right== nullptr) //ricerca nel sottoalbero destro se presente
        return nullptr;
    else return this->_right->search(value);
}


