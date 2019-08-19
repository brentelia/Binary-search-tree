/**
 * @author Elia Brentarolli, VR397594
 * @brief Namespace che implementa alcune funzioni utili per il recupero dati da file
 * @ref ../src/FileIO.cpp
 */
#pragma once

#include <string>
#include <vector>


namespace fileIO{
    /**
     * @brief Legge il file e lo converte in una unica stringa
     * @param fileName nome del file da leggere
     * @return stringa con tutto il contenuto del file
     */
    std::string readFile(std::string& fileName);
    /**
     * @brief Converte una stringa in un vector in cui gli elementi sono porzioni della stringa fino al carattere
     * specificato come delimitatore
     * @param source la stringa di partenza
     * @param sep il separatore da usare
     * @return vector con gli elementi della stringa delimitati dal separatore
     */
    std::vector <std::string> stringToVector (std::string &source, char sep);
    /**
     * @brief Scrive su un file le stringhe contenute nell'array
     * @param fileName il file su cui scrivere
     * @param vector array con le stringhe da scrivere
     */
    void writeFile(std::string&fileName, std::vector<std::string>& args);

}

