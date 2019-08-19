/**
 * @author Elia Brentarolli, VR397594
 */
#include "../include/FileIO.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

namespace fileIO {

    string readFile(string &fileName) {

        string in;
        string result;
        ifstream file;

        file.open(fileName);
        while (file.good()) {
            getline(file, in);
            result += in + "\n";    //aggiunta della stringa letta al risultato finale
        }
        file.close();
        return result;
    }

    vector<string> stringToVector(string &source, char sep) {
        vector<string> result = vector<string>();
        string item;
        for (char i : source) {
            if (i != sep)
                item += i;          //aggiunta del carattere alla stringa
            else {
                result.push_back(item); //inserimento della stringa nel vector
                item.clear();           //rimozione degli elementi dalla stringa di supporto
            }
        }
        if (!item.empty())
            result.push_back(item); //inserimento dei valori restanti del vector

        return result;
    }


    void writeFile(string &fileName, std::vector<std::string>& args) {
        ofstream file;
        file.open(fileName);
        for (auto &i:args)
            file<<i;
        file.close();
    }
}
