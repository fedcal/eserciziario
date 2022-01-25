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

 Se l'utente inserisce -d  il programma deve stampare per ogni mezzo la distanza percorsa
durante la giornata (sulla base delle rilevazioni disponibili) ipotizzando che il mezzo si
muova in linea retta da un punto a un altro in metri (arrotondare all’intero più vicino).
Riportare la distanza in metri (arrotondare all’intero più vicino), indicando ora della prima
rilevazione e ora dell’ultima rilevazione (nel formato hh:mm:ss).

Se l'utente inserisce -v il programma deve stampare per ogni mezzo la velocità media tenuta nel
corso della giornata
*/


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

//Creiamo una struttura in cui memorizzare i dati che verranno letti dal file
struct file{
    int numero_mezzo;
    int numero_linea;
    int ascissa;
    int ordinata;
    int tempo;
    int distanza_percorsa;
}tipo_file[20]; //la dimensione massima delle linee è di 20, quindi in un dato istante si potrà avere la capienza massima

//Definiamo le variabili globali comuni alla funzione main e alle sotto funzioni
FILE *paf;
int numero_elementi;

// Adesso andiamo a definire i prototipi delle funzioni che ci serviranno per portare a termine il compito della traccia
void caricare_file(); //funzione per creare il file da 0 (consiglio di farlo solo la prima volta)
void ordinare_file(); //funzione per ordinare il file
void numero_elementi_file();
void ditanza_percorsa();
void velocita_media();

int main()
{
    char flag[3];
    caricare_file();
    numero_elementi_file();
    ordinare_file();

    flag="-c"
    do{
        printf("\n Inserire il flag desiderato: \n");
        scanf("%c", flag);
    }while(strcmp(flag,'-d')<0 && stcmp(flag,'-v')<0)//In questo modo riesco a sapere se l'utente inserisce un flag valido

    if(strcmp(flag,'-d')==0)
        distanza_percorsa();
    else
        velocita_media();

    return 0;
}

//Andiamo a sviluppare il corpo delle varie funzioni
void caricare_file(){
    paf=fopen("trasporti.txt","w");
    int numero_mezzo;
    int numero_linea;
    int ascissa;
    int ordinata;
    int tempo;
    int scelta;
    int elementi_rimasti;

    elementi_rimasti=20;
    scelta=1;
    numero_elementi=0;
    while(scelta==1 && numero_elementi<20){
        printf("\n Inserire il numero del mezzo: \n");
        scanf("%d", &numero_mezzo);
        printf("\n Inserire il numero del mezzo: \n");
        scanf("%d", &numero_linea);
        printf("\n Inserire il numero del mezzo: \n");
        scanf("%d", &ascissa);
        printf("\n Inserire il numero del mezzo: \n");
        scanf("%d", &ordinata);
        printf("\n Inserire il numero del mezzo: \n");
        scanf("%d", &tempo);
        do{
            printf("\n Inserire 1 per continuare e 2 per terminare: \n");
            scanf("%d",&scelta);
        }while(scelta!=1 && scelta!=2);
        elementi_rimasti--; //diminuisco di una unità la variabile
        numero_elementi++; //incremento di una unità la variabile
        printf("\n Puoi inserire ancora %d elementi\n",elementi_rimasti);
        fprintf(paf,"%d %d %d %d %d\n", numero_mezzo, numero_linea, ascissa, ordinata, tempo);
    }
    fclose(paf);
}
void ordinare_file(){
    paf= fopen("trasporti.txt", "r");
    numero_elementi=0;
    //In questo punto vado a leggere il file riga per riga fino a quando non termina, contemporaneamente mi salvo i valori nella struttura creata all'inizio e conto quanti elementi ci sono
    while(fscanf(paf, "%d %d %d %d %d", &tipo_file[numero_elementi].numero_mezzo,&tipo_file[numero_elementi].numero_linea, &tipo_file[numero_elementi].ascissa,&tipo_file[numero_elementi].ordinata,&tipo_file[numero_elementi].tempo)!=EOF)
        numero_elementi++;
    fclose(paf);
}
void numero_elementi_file(){
    //Algoritmo di ordinamento ingenuo, per praticità l'avevo già fatto
    int i,j;
    int x;
    i=0;
    while(i<numero_elementi-1)
    {
        j=0;
        while(j<numero_elementi)
        {
            if(tipo_file[i].tempo>tipo_file[j].tempo)
            {
                x=tipo_file[i].tempo;
                tipo_file[i].tempo=tipo_file[j].tempo;
                tipo_file[j].tempo=x;
                x=tipo_file[i].ascissa;
                tipo_file[i].ascissa=tipo_file[j].ascissa;
                tipo_file[j].ascissa=x;
                x=tipo_file[i].ordinata;
                tipo_file[i].ordianta=tipo_file[j].ordinata;
                tipo_file[j].ordianta=x;
                x=tipo_file[i].numero_linea;
                tipo_file[i].numero_linea=tipo_file[j].numero_linea;
                tipo_file[j].numero_linea=x;
                x=tipo_file[i].numero_mezzo;
                tipo_file[i].numero_mezzo=tipo_file[j].numero_mezzo;
                tipo_file[j].numero_mezzo=x;
            }
            j++;
        }
        i++;
    }
    paf=fopen("trasporti.txt"."w");
    i=0;
    while(i<numero_elementi)
    {
        fprintf(paf,"%d %d %d %d %d\n",tipo_file[i].numero_mezzo,tipo_file[i].numero_linea,tipo_file[i].ascissa,tipo_file[i].ordinata,tipo_file[i].tempo);
        i++;
    }
    fclose(paf);
}
void ditanza_percorsa(){
    int i,j;
    int somma_ordinate, somma_ascisse;
    int somma_quadrati;
    int quadrato_ascisse, quadrato_ordinate;
    float distanza;
    //Calcolo la distanza come distanza lineare tra due punti (rimando ai concetti di geometria analitica)
    i=0;
    while(i<numero_elementi){
        j=0;
        while(j<numero_elementi){
            if(tipo_file[i].numero_mezzo==tipo_file[j].numero_mezzo){
                somma_ascisse=tipo_file[j].ascissa-tipo_file[i].ascissa;
                somma_ordinate=tipo_file[j].ordinata - tipo_file[i].ordinata;
                quadrato_ascisse=somma_ascisse*somma_ascisse;
                quadrato_ordinate=somma_ordinate*somma_ordinate;
                somma_quadrati=quadrato_ascisse+quadrato_ordinate;
                distanza= sqrt(somma_quadrati)
                tipo_file[i].distanza_percorsa= distanza;
                printf("\n %d: %.2f m", tipo_file[i].numero_mezzo, tipo_file[i].distanza_percorsa)
            }
            j++;
        }
        i++;
    }
}
void velocita_media(){
    distanza_percorsa();
    //Ho lo spazio e il tempo per ogni mezzo, quindi...
    float velocita_veicolo;
    for(int i=0; i<numero_elementi; i++){
        velocita_veicolo=tipo_file[i].distanza_percorsa/tipo_file[i].tempo;
        printf("\n %d: %.2f m/s", tipo_file[i].numero_mezzo, velocita_veicolo);
    }
}
