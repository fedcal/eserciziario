/*
Si realizzi un programma in linguaggio C che gestisca la base di dati di una centrale di gestione del
trasporto pubblico cittadino. Le informazioni sono contenute in un file il cui nome viene passato da
linea di comando. Ogni riga di tale file contiene le informazioni sulla posizione di un mezzo in un
determinato istante col seguente formato: il numero identificativo del mezzo pubblico, il numero
della linea che sta servendo, le coordinate spaziali in metri del mezzo (ascissa e ordinata) e
l�istante di tempo della rilevazione in secondi (istanti che appartengono tutti ad uno stesso giorno).
Ad esempio, il file pu� contenere:

2187   13     10   1003    18000
3002    4   5000      5    18100
2187   13    100   2030    18500
3002    4   5000   1100    18600
2187   13    300   3300    19200
3002    4   5000   2200    19200

Si facciano le seguenti ipotesi:
 [ ] Il numero di righe del file non � noto a priori e i campi sono separati da spazi;
 [ ] Il numero del mezzo pubblico � sempre specificato su 4 cifre;
 [ ] Il numero della linea � espresso con al massimo 2 cifre;
 [ ] L�azienda di trasporto pubblico possiede un numero massimo di 20 mezzi.
 [ ] Le coordinate spaziali sono indicate da due numeri interi positivi di massimo 5 cifre ciascuno;
 [ ] Il tempo � indicato dal numero intero di secondi trascorsi dall�inizio del giorno (max 5 cifre);
 [ ] Le righe sono ordinate secondo l�istante di tempo;
 [ ] Si ipotizzi che i mezzi siano sempre in movimento dall�istante della prima misurazione all�istante dell�ultima;
 [ ] Pi� righe possono riguardare lo stesso mezzo pubblico in istanti diversi;
*/


#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
