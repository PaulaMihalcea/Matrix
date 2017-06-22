/* MATRIX
 * by Paula Mihalcea
 *
 * UniFi - Ingegneria Informatica
 * Laboratorio di programmazione
 */

#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {

    /* DONE L'operatore = non deve restituire una terza matrice
     * DONE Levare size / usare il size del vector
     * TODO Non usare gli stessi valori nei test (no matrici di tutti x)
     * DONE Usare eccezioni per ritornare messaggi di errore in tutte le funzioni
     * DONE Controllare che rows e cols non siano negative (usare eccezione out_of_range)
     * DONE Ritornare matrice 1*x per getCol e getRow [Matrix<int> e=a.getCol(1);]
     * DONE Sovraccaricare << per visualizzare matrice (cout << a)
     * DONETODO getValue e setValue dovrebbero essere booleani (oppure void e ritornano eccezioni?) (non devono ritornare robe) --> i setter sono void, i getter ritornano un valore del tipo considerato
     * DONE Eliminare getSize
     * DONE Controllare warnings (a quanto pare potrebbero essere utili)
     * DONE Funzione friend per getMatrix? [SI]
     * DONE Controllare return
     * TODO Controllare test per funzioni modificate
     * TODO Controllare commenti/testi vari (cleanup)
     */

    Matrix<int> a(3, 3, 2);
    Matrix<int> b(3, 3, 4);


    return 0;
}