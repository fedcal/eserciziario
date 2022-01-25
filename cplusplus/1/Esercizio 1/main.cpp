/*
Si realizzi un programma in linguaggio C che gestisca la base di dati di una centrale di gestione del
trasporto pubblico cittadino. Le informazioni sono contenute in un file il cui nome viene passato da
linea di comando. Ogni riga di tale file contiene le informazioni sulla posizione di un mezzo in un
determinato istante col seguente formato: il numero identificativo del mezzo pubblico, il numero
della linea che sta servendo, le coordinate spaziali in metri del mezzo (ascissa e ordinata) e
l’istante di tempo della rilevazione in secondi (istanti che appartengono tutti ad uno stesso giorno).
Ad esempio, il file può contenere:

2187   13     10   1003    18000
3002    4   5000      5    18100
2187   13    100   2030    18500
3002    4   5000   1100    18600
2187   13    300   3300    19200
3002    4   5000   2200    19200

Si facciano le seguenti ipotesi:
 [ ] Il numero di righe del file non è noto a priori e i campi sono separati da spazi;
 [ ] Il numero del mezzo pubblico è sempre specificato su 4 cifre;
 [ ] Il numero della linea è espresso con al massimo 2 cifre;
 [ ] L’azienda di trasporto pubblico possiede un numero massimo di 20 mezzi.
 [ ] Le coordinate spaziali sono indicate da due numeri interi positivi di massimo 5 cifre ciascuno;
 [ ] Il tempo è indicato dal numero intero di secondi trascorsi dall’inizio del giorno (max 5 cifre);
 [ ] Le righe sono ordinate secondo l’istante di tempo;
 [ ] Si ipotizzi che i mezzi siano sempre in movimento dall’istante della prima misurazione all’istante dell’ultima;
 [ ] Più righe possono riguardare lo stesso mezzo pubblico in istanti diversi;
*/


#include <iostream>

using namespace std;

//Creiamo una struttura in cui memorizzare i dati che verranno letti dal file
struct file{
    int numero_mezzo;
    int numero_linea;
    int ascissa;
    int ordinata;
    int tempo
}tipo_file[20]; //la dimensione massima delle linee è di 20, quindi in un dato istante si potrà avere la capienza massima

//Definiamo le variabili globali comuni alla funzione main e alle sotto funzioni
FILE *paf;
int numero_elementi;

// Adesso andiamo a definire i prototipi delle funzioni che ci serviranno per portare a termine il compito della traccia
void caricare_file(); //funzione per caricare il file
void ordinare_file(); //funzione per ordinare il file
void numero_elementi_file();
void ditanza_percorsa();
void velocita_media();

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
