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
     * TODO Controllare che rows e cols non siano negative (usare eccezione)
     * TODO Ritornare matrice 1*x per getCol e getRow [Matrix<int> e=a.getCol(1);]
     * DONE Sovraccaricare << per visualizzare matrice (cout << a)
     * TODO getValue e setValue dovrebbero essere booleani (oppure void e ritornano eccezioni?) (non devono ritornare
       TODO robe) --> i setter sono void, i getter ritornano un valore del tipo considerato
     * DONE Eliminare getSize
     * TODO Controllare warnings (a quanto pare potrebbero essere utili)
     * DONE Funzione friend per getMatrix? [SI]
     */

    Matrix<int> a(10, 10, 5);
    Matrix<int> b=a;
    cout << endl;
    Matrix<int> c(3, 3, 1);
    cout << b;
    c=a;
    Matrix<float> d(10,10,3);
    cout << d;

    return 0;
}