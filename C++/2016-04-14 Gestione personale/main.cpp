#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

/*
numeroPersone
numeroGiorni
id

giorno
mese
anno

oraIngressoMattina
minutoIngressoMattina

oraUscitaMattina
minutoUscitaMattina

oraIngressoPomeriggio
minutoIngressoPomeriggio

oraUscitaPomeriggio
minutoUscitaPomeriggio

giornoAnalizzato
contatore

minutiLavoroMattina
minutiLavoroPomeriggio
minutiLavoroGiorno

erroreIngressoMattina
erroreUscitaMattina

erroreIngressoPomeriggio
erroreUscitaPomeriggio

erroreMattina
errorePomeriggio

totaleErroriBadge
totaleErroriBadgeMattina
totaleErroriBadgePomeriggio
totaleErroriBadgeFerie

continuareInErroriBadge

errorePersonaDaAnalizzare

minutiLavoroMese
personaDaAnalizzare

*/

int main()
{
    ifstream file;
    file.open("OrariDipendenti.txt");
///---------------------------------------------------------------------------------- VARIABILI DA MODIFICARE
    int numeroPersone=20;
    int numeroGiorni=26;
///----------------------------------------------------------------------------------
    int id[numeroPersone];

    int giorno[numeroPersone][numeroGiorni];
    int mese[numeroPersone][numeroGiorni];
    int anno[numeroPersone][numeroGiorni];

    int oraIngressoMattina[numeroPersone][numeroGiorni];
    int minutoIngressoMattina[numeroPersone][numeroGiorni];

    int oraUscitaMattina[numeroPersone][numeroGiorni];
    int minutoUscitaMattina[numeroPersone][numeroGiorni];

    int oraIngressoPomeriggio[numeroPersone][numeroGiorni];
    int minutoIngressoPomeriggio[numeroPersone][numeroGiorni];

    int oraUscitaPomeriggio[numeroPersone][numeroGiorni];
    int minutoUscitaPomeriggio[numeroPersone][numeroGiorni];

    int giornoAnalizzato=0;
    int contatore=0;

    int minutiLavoroMattina[numeroPersone][numeroGiorni];
    int minutiLavoroPomeriggio[numeroPersone][numeroGiorni];
    int minutiLavoroGiorno[numeroPersone][numeroGiorni];
/*
    int erroreIngressoMattina[numeroPersone][numeroGiorni];
    int erroreUscitaMattina[numeroPersone][numeroGiorni];

    int erroreIngressoPomeriggio[numeroPersone][numeroGiorni];
    int erroreUscitaPomeriggio[numeroPersone][numeroGiorni];
*/
    int erroreMattina[numeroPersone][numeroGiorni];
    int errorePomeriggio[numeroPersone][numeroGiorni];

    int totaleErroriBadge=0;
    int totaleErroriBadgeMattina=0;
    int totaleErroriBadgePomeriggio=0;
    int totaleErroriBadgeFerie=0;

    char continuareInErroriBadge[10];

    int errorePersonaDaAnalizzare=0;

    int minutiLavoroMese[numeroPersone];
    int personaDaAnalizzare;

    for(int cicloPersone=1;cicloPersone<numeroPersone+1;cicloPersone++)///SONO DOVUTO PARTIRE OBBLIGATORIAMENTE DA 1 DATO CHE GLI I NUMERI DELLE PERSONE NON PARTONO DA 0
    {
        file>>id[cicloPersone];

        for(int cicloGiorni=1;cicloGiorni<numeroGiorni+1;cicloGiorni++)///SONO DOVUTO PARTIRE OBBLIGATORIAMENTE DA 1 DATO CHE GLI I NUMERI DELLE PERSONE NON PARTONO DA 0
        {
            contatore=contatore+1;
        ///giornata
            char dataGiornata[10];
            file>>dataGiornata;
            sscanf(dataGiornata,"%d/%d/%d",&giorno[cicloPersone][cicloGiorni],&mese[cicloPersone][cicloGiorni],&anno[cicloPersone][cicloGiorni]);
        ///mattinaIngresso
            char ingressoMattina[10];
            file>>ingressoMattina;
            sscanf(ingressoMattina,"%d:%d",&oraIngressoMattina[cicloPersone][cicloGiorni],&minutoIngressoMattina[cicloPersone][cicloGiorni]);

        ///mattinaUscita
            char uscitaMattina[10];
            file>>uscitaMattina;
            sscanf(uscitaMattina,"%d:%d",&oraUscitaMattina[cicloPersone][cicloGiorni],&minutoUscitaMattina[cicloPersone][cicloGiorni]);
        ///pomeriggioIngresso
            char ingressoPomeriggio[10];
            file>>ingressoPomeriggio;
            sscanf(ingressoPomeriggio,"%d:%d",&oraIngressoPomeriggio[cicloPersone][cicloGiorni],&minutoIngressoPomeriggio[cicloPersone][cicloGiorni]);
        ///pomeriggioUscita
            char uscitaPomeriggio[10];
            file>>uscitaPomeriggio;
            sscanf(uscitaPomeriggio,"%d:%d",&oraUscitaPomeriggio[cicloPersone][cicloGiorni],&minutoUscitaPomeriggio[cicloPersone][cicloGiorni]);
        }
    }
    file.close();

///CALCOLI

    ///CALCOLARE ORE DI LAVORO

    do
    {
        cout<<"Che persona vuoi analizzare? --> ";
        cin>>personaDaAnalizzare;

        if(personaDaAnalizzare>0 && personaDaAnalizzare<=numeroPersone)
        {
            errorePersonaDaAnalizzare=0;
            cout<<endl;
        }
        else
        {
            cout<<"id non valido reinserire l'id"<<endl;
            errorePersonaDaAnalizzare=1;
        }
    }while(errorePersonaDaAnalizzare!=0);

///----------------------------------------------------------------------------------

    for(int w=1;w<=numeroGiorni;w++) ///SONO DOVUTO PARTIRE OBBLIGATORIAMENTE DA 1 DATO CHE GLI I NUMERI DELLE PERSONE NON PARTONO DA 0
    {

///CALCOLO TEMPO DI MATTINA

        if(oraIngressoMattina[personaDaAnalizzare][w]==0){erroreMattina[personaDaAnalizzare][w]=1;}
        else if(oraUscitaMattina[personaDaAnalizzare][w]==0){erroreMattina[personaDaAnalizzare][w]=1;}
        else if(oraIngressoMattina[personaDaAnalizzare][w]<=8)
        {
            minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+((oraUscitaMattina[personaDaAnalizzare][w]-9)*60);
            minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-0);
        }
        else if(oraIngressoMattina[personaDaAnalizzare][w]==9)
        {
            minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+((oraUscitaMattina[personaDaAnalizzare][w]-oraIngressoMattina[personaDaAnalizzare][w])*60);
            if(minutoIngressoMattina[personaDaAnalizzare][w]==0){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-0);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<=5){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-minutoIngressoMattina[personaDaAnalizzare][w]);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<30){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-30);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<60){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-60);}
        }
        else if(oraIngressoMattina[personaDaAnalizzare][w]>=10)
        {
            minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+((oraUscitaMattina[personaDaAnalizzare][w]-oraIngressoMattina[personaDaAnalizzare][w])*60);
            if(minutoIngressoMattina[personaDaAnalizzare][w]==0){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-0);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<30){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-30);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<60){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-60);}
        }

///CALCOLO TEMPO DI POMERIGGIO

        if(oraIngressoPomeriggio[personaDaAnalizzare][w]==0){errorePomeriggio[personaDaAnalizzare][w]=1;}
        else if(oraUscitaPomeriggio[personaDaAnalizzare][w]==0){errorePomeriggio[personaDaAnalizzare][w]=1;}
        else if(oraIngressoPomeriggio[personaDaAnalizzare][w]<=12)
        {
            minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+((oraUscitaPomeriggio[personaDaAnalizzare][w]-13)*60);
            minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-0);
        }
        else if(oraIngressoPomeriggio[personaDaAnalizzare][w]==13)
        {
            minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+((oraUscitaPomeriggio[personaDaAnalizzare][w]-oraIngressoPomeriggio[personaDaAnalizzare][w])*60);
            if(minutoIngressoPomeriggio[personaDaAnalizzare][w]==0){minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-0);}
            else if(minutoIngressoPomeriggio[personaDaAnalizzare][w]<30){minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-30);}
            else if(minutoIngressoPomeriggio[personaDaAnalizzare][w]<60){minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-60);}
        }
        else if(oraIngressoPomeriggio[personaDaAnalizzare][w]>=14)
        {
            minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+((oraUscitaPomeriggio[personaDaAnalizzare][w]-oraIngressoPomeriggio[personaDaAnalizzare][w])*60);
            if(minutoIngressoPomeriggio[personaDaAnalizzare][w]==0){minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-0);}
            else if(minutoIngressoPomeriggio[personaDaAnalizzare][w]<30){minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-30);}
            else if(minutoIngressoPomeriggio[personaDaAnalizzare][w]<60){minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-60);}
        }

///CALCOLO DEL TEMPO NEL GIORNO

        minutiLavoroGiorno[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+minutiLavoroPomeriggio[personaDaAnalizzare][w];

///CALCOLO TEMPO PER I 5 MINUTI SUPPLEMENTARI

        if(minutiLavoroGiorno[personaDaAnalizzare][w]==0){minutiLavoroGiorno[personaDaAnalizzare][w]=0;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<30){minutiLavoroGiorno[personaDaAnalizzare][w]=0;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<60){minutiLavoroGiorno[personaDaAnalizzare][w]=30;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<90){minutiLavoroGiorno[personaDaAnalizzare][w]=60;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<120){minutiLavoroGiorno[personaDaAnalizzare][w]=90;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<150){minutiLavoroGiorno[personaDaAnalizzare][w]=120;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<180){minutiLavoroGiorno[personaDaAnalizzare][w]=150;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<210){minutiLavoroGiorno[personaDaAnalizzare][w]=180;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<240){minutiLavoroGiorno[personaDaAnalizzare][w]=210;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<270){minutiLavoroGiorno[personaDaAnalizzare][w]=240;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<300){minutiLavoroGiorno[personaDaAnalizzare][w]=270;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<330){minutiLavoroGiorno[personaDaAnalizzare][w]=300;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<360){minutiLavoroGiorno[personaDaAnalizzare][w]=330;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<390){minutiLavoroGiorno[personaDaAnalizzare][w]=360;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<410){minutiLavoroGiorno[personaDaAnalizzare][w]=390;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<430){minutiLavoroGiorno[personaDaAnalizzare][w]=410;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<470){minutiLavoroGiorno[personaDaAnalizzare][w]=440;}
        else if(minutiLavoroGiorno[personaDaAnalizzare][w]<500){minutiLavoroGiorno[personaDaAnalizzare][w]=470;}

///500 E' IL TEMPO MASSIMO DI LAVORO IN UNA GIORNATA

///CALCOLO DEL TEMPO NEL MESE

        minutiLavoroMese[personaDaAnalizzare]=minutiLavoroMese[personaDaAnalizzare]+minutiLavoroGiorno[personaDaAnalizzare][w];

    } ///CHIUSURA DEL FOR PRINCIPALE DEI CALCOLI

///STAMPA DELLA DEL TOTALE DEI MINUTI DEL MESE

    cout<<"Totale minuti lavoro del mese: ";
    cout<<minutiLavoroMese[personaDaAnalizzare]<<endl<<endl;

///CALCOLO DEGLI ERRORI DI TIMBRO BADGE

    for(int w=1;w<=numeroGiorni;w++) ///SONO DOVUTO PARTIRE OBBLIGATORIAMENTE DA 1 DATO CHE GLI I NUMERI DELLE PERSONE NON PARTONO DA 0
    {
        if(erroreMattina[personaDaAnalizzare][w]==1){totaleErroriBadge=totaleErroriBadge+1;totaleErroriBadgeMattina=totaleErroriBadgeMattina+1;}
        if(errorePomeriggio[personaDaAnalizzare][w]==1){totaleErroriBadge=totaleErroriBadge+1;totaleErroriBadgePomeriggio=totaleErroriBadgePomeriggio+1;}

        if(erroreMattina[personaDaAnalizzare][w]==1 && errorePomeriggio[personaDaAnalizzare][w]==1){totaleErroriBadgeFerie=totaleErroriBadgeFerie+1;}

        ///QUESTA FORMULA NON FUNZIONA SENZA MOTIVO
    }

///STAMPA DEL NUMERO DI ERRORI

    cout<<"Sono stati trovati "<<totaleErroriBadge<<" errori"<<endl<<endl;
    cout<<"Vuoi vedere con precisione quando non e' stato timbrato il badge? y-n --> ";
    cin>>continuareInErroriBadge;cout<<endl;
    if(continuareInErroriBadge[0]=='n'){cout<<endl<<"PROGRAMMA TERMINATO"<<endl;}

///STAMPA DEGLI ERRORI NEL CASO IN CUI CI SIA STATO ESITO POSITIVO NELLA DOMANDA DI PRIMA

    else if(continuareInErroriBadge[0]=='y')
    {
        if(totaleErroriBadgeMattina>0)
        {
            cout<<"Di mattina non e' stato timbrato il badge nei giorni: ";
            for(int w=1;w<=numeroGiorni;w++) ///SONO DOVUTO PARTIRE OBBLIGATORIAMENTE DA 1 DATO CHE GLI I NUMERI DELLE PERSONE NON PARTONO DA 0
            {if(erroreMattina[personaDaAnalizzare][w]==1){cout<<w<<"  ";}}
            cout<<endl<<endl;
        }
        if(totaleErroriBadgePomeriggio>0)
        {
            cout<<"Di pomeriggio non e' stato timbrato il badge nei giorni: ";
            for(int w=1;w<=numeroGiorni;w++) ///SONO DOVUTO PARTIRE OBBLIGATORIAMENTE DA 1 DATO CHE GLI I NUMERI DELLE PERSONE NON PARTONO DA 0
            {if(errorePomeriggio[personaDaAnalizzare][w]==1){cout<<w<<"  ";}}
            cout<<endl<<endl;
        }
        if(totaleErroriBadgeFerie>0)
        {
            cout<<"Le ferie dell'impiegato sono avvenute nei giorni: ";
            for(int w=1;w<=numeroGiorni;w++) ///SONO DOVUTO PARTIRE OBBLIGATORIAMENTE DA 1 DATO CHE GLI I NUMERI DELLE PERSONE NON PARTONO DA 0
            {if(erroreMattina[personaDaAnalizzare][w]==1 && errorePomeriggio[personaDaAnalizzare][w]==1){cout<<w<<"  ";}}
            cout<<endl<<endl;
        }
    }

///IN CASO NELLA RICHIESTA SI SCRIVESSE QUALCOS ALTRO OLTRE A "n" O "y"

    else {cout<<"Inserire y oppure n correttamente"<<endl;}

///FINE PROGRAMMA
}
