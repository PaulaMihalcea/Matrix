/* MATRIX
 * by Paula Mihalcea
 *
 * UniFi - Ingegneria Informatica
 * Laboratorio di programmazione
 */

#include <iostream>
#include "Matrix.h"

int main() {

    /* DONE L'operatore = non deve restituire una terza matrice
     * DONE Levare size / usare il size del vector
     * TODO Non usare gli stessi valori nei test (no matrici di tutti x)
     * TODO Usare eccezioni per ritornare messaggi di errore in tutte le funzioni
     * DONE Controllare che rows e cols non siano negative (usare eccezione out_of_range)
     * DONE Ritornare matrice 1*x per getCol e getRow [Matrix<int> e=a.getCol(1);]
     * DONE Sovraccaricare << per visualizzare matrice (cout << a)
     * DONETODO getValue e setValue dovrebbero essere booleani (oppure void e ritornano eccezioni?) (non devono ritornare robe) --> i setter sono void, i getter ritornano un valore del tipo considerato
     * DONE Eliminare getSize
     * TODO Controllare warnings (a quanto pare potrebbero essere utili)
     * DONE Funzione friend per getMatrix? [SI]
     * TODO Controllare return
     * TODO Controllare test per funzioni modificate
     * TODO Controllare commenti/testi vari (cleanup)
     */

    Matrix<int> a(3, 3, 2);
    //Matrix<int> b=a.getCol(4); // GETROW e GETCOL FUNZIONA tranne che per cout
    // cout << a.getCol(-956) << endl; // TODO GENERATES ERROR
    //a.getRow(-956);
    //cout << a << endl;
    //a.getRow(-956);
    Matrix<int> b(2, 2, 4);
    Matrix<int> c(3, 3, 1);
    cout << b-a << endl;
    cout << c-a << endl;

    return 0;
}