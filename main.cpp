#include <iostream>
#include <vector>
#include "Notes.h"
#include "Collezione.h"
#include "Displayer.h"
#include "Executive.h"


struct boolint{
    int count;
    bool found;
};

//funzione che cerca un titolo fornito in una collezione
boolint SeqSearch (std::vector<Collezione*> RC, int N, const std::string& TitoloCercato)
{
    boolint res{};
    res.found = false;
    res.count = 0;
    while ( res.count<= N-1 && !res.found)
    {
        if (RC[res.count]->getTitolo() == TitoloCercato)
            res.found = true;
        else
            res.count ++;
    }
    return res;
}

void CreazioneNota (Notes& NotaCostr){
    std::cout << "==== Creazione di una  nuova nota ===="<< std::endl;
    std::string TestoTemp;
    std::string TitoloTemp;
    int Lok;
    std::cout << "\nInserire il titolo della nota."<< std::endl;
    std::cin.ignore();
    std::getline(std::cin, TitoloTemp);
    NotaCostr.setTitle(TitoloTemp);
    std::cout << "\nInserire il testo della nota." << std::endl;
    std::getline(std::cin, TestoTemp);
    NotaCostr.setText(TestoTemp);
    std::cout << "\nDo you want to lock this note? (0=y or 1=n)" << std::endl;
    std::cin >> Lok;
    if (Lok == 0) {
        NotaCostr.setLocked(true);
    }
    else if (Lok == 1) {
        NotaCostr.setLocked(false);
    }
}

void SetNoteImportance (const Notes &n, Collezione &c, Executive &ctrl){
    int s;
    ctrl.setCol(&c);
    std::cout << "\nQuesta nota è importante? (0=yes / 1=no)" << std::endl;
    do {
        std::cin >> s;
    } while (s != 1 && s != 0);
    if (s == 0){
        ctrl.AddNote(n);
    }
}

int main() {
    int scelta;
    int exit = 0;
    auto *Important = new Collezione("Important");
    auto *Ctrl = new Executive(Important);
    auto *Disp = new Displayer(Ctrl);
    std::vector<Collezione* > RaccoltaCollezioni;
    RaccoltaCollezioni.push_back(Important);

    //TODO risistema interfaccia grafica
    do { //do per continuare a mostrare il menù dopo ogni azione
        //"GUI" menu
        std::cout << "\n\n================MENU'================\n\n" << std::endl;
        std::cout << "#==============AZIONI==============#" << std::endl;
        std::cout << "#  1 - Crea una nuova collezione   #" << std::endl;
        std::cout << "#  2 - Crea una nuova nota         #" << std::endl;
        std::cout << "#  3 - Modifica una nota           #" << std::endl;
        std::cout << "#  4 - Leggi una nota              #" << std::endl;
        std::cout << "#  5 - Eliminare una nota          #" << std::endl;
        std::cout << "#  6 - Eliminare una collezione    #" << std::endl;
        std::cout << "#  0 - Exit                        #" << std::endl;
        std::cout << "#==================================#" << std::endl;
        Disp->ShowTotal();
        std::cout << "\nCollezioni: " << std::endl;

        //visualizzazione delle Collezioni e note
        for (const auto itr : RaccoltaCollezioni) {
            Ctrl->setCol(itr);
            Ctrl->ViewCol();
            Disp->ShowCol();
        }

        do { //do per accettare solo valori validi come opzioni
            std::cin >> scelta;
        } while (scelta != 0 && scelta != 1 && scelta != 2 && scelta != 3 && scelta != 4 && scelta!=5 && scelta!=6);
        switch (scelta) {
            //creazione di una collezione
            case 1 :{
                std::string t;
                std::cout << "\n==== Creazione di una  nuova Collezione ====" << std::endl;
                std::cout << "\n \nInserire il titolo della Collezione:"<< std::endl;
                std::cin.ignore();
                std::getline(std::cin, t);
                auto* Col = new Collezione(t);
                RaccoltaCollezioni.push_back(Col);
                break;
            }

            //creazione di una nota
            case 2: {
                std::string Temp;
                auto *Not = new Notes;
                CreazioneNota(*Not);
                std::cout << "\nA quale collezione deve appartenere la nota?" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, Temp);
                auto res = SeqSearch(RaccoltaCollezioni, RaccoltaCollezioni.size(), Temp);
                if (res.found) {
                    Ctrl->setCol(RaccoltaCollezioni[res.count]);
                    Ctrl->AddNote(*Not);
                    //possibile aggiunta della nota appena creata anche alla collezione "Important"
                    SetNoteImportance(*Not, *Important, *Ctrl);

                } else{ //se la collezione cercata non esiste è possibile crearne una nuova
                    int s;
                    std::cout << "\nLa collezione cercata non esiste. Crearne una nuova?(0=yes / 1=no)" << std::endl;
                    do {
                        std::cin >> s;
                    } while (s != 1 && s != 0);
                    if (s == 0) {
                        auto* NCol = new Collezione(Temp);
                        RaccoltaCollezioni.push_back(NCol);
                        Ctrl->setCol(NCol);
                        Ctrl->AddNote(*Not);
                        //possibile aggiunta della nota appena creata anche alla collezione "Important"
                        SetNoteImportance(*Not, *Important, *Ctrl);
                    }
                }
                break;
            }

            //modifica di una nota
            case 3:{
                std::string Temp;
                boolint res{};
                res.found = false;
                int mod;
                std::string TestoTemp = " ";
                bool ModSuccess;
                do {
                    std::cout << "\nSeleziona una collezione" << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, Temp);
                    res = SeqSearch(RaccoltaCollezioni, RaccoltaCollezioni.size(), Temp);
                    if (res.found) {
                        int s;
                        std::cout << "\nQuale nota si vuole modificare della collezione (selezionare una nota non bloccata)" << std::endl;
                        Ctrl->setCol(RaccoltaCollezioni[res.count]);
                        Ctrl->ViewCol();
                        do{
                            std::cin >> s;
                        }while (s>0 && s<RaccoltaCollezioni[res.count]->CollectionSize());
                        std::cout << "Selezionare cosa si vuole modificare:" << std::endl;
                        std::cout << "1) Titolo" << std::endl;
                        std::cout << "2) Testo" << std::endl;
                        std::cout << "3) Sicurezza" << std::endl;
                        do{
                            std::cin >> mod;
                        }while (mod != 1 && mod != 2 && mod != 3);
                        if(mod != 3){
                            std::cout << "Inserire il nuovo Titolo/Testo" << std::endl;
                            std::cin.ignore();
                            std::getline (std::cin,TestoTemp);
                            ModSuccess = Ctrl->ModifyNote(s, mod, TestoTemp);
                        }
                        else{
                            ModSuccess = Ctrl->ModifyNote(s, mod, TestoTemp);
                        }
                        if (ModSuccess){
                            std::cout << "La modifica e` avvenuta con successo!" << std::endl;
                        }
                        else{
                            std::cout << "La modifica non e` avvenuta dato che e` stata selezionata una nota bloccata..." << std::endl;
                        }
                    } else {
                        std::cout << "\nLa collezione cercata non esiste.\n" << std::endl;
                    }
                }while(!res.found);
                break;
            }

            //visualizzazione di una nota
            case 4: {
                std::string Temp;
                boolint res{};
                res.found = false ;
                do {
                    std::cout << "\nSeleziona una collezione" << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, Temp);
                    res = SeqSearch(RaccoltaCollezioni, RaccoltaCollezioni.size(), Temp);
                    if (res.found) {
                        int s;
                        std::cout << "\nQuale nota si vuole visualizzare della collezione " << std::endl;
                        Ctrl->setCol(RaccoltaCollezioni[res.count]);
                        Ctrl->ViewCol();
                        do{
                            std::cin >> s;
                        }while (s>0 && s<(RaccoltaCollezioni[res.count]->CollectionSize()-1));
                        Ctrl->ViewNote(s);
                    } else {
                        std::cout << "\nLa collezione cercata non esiste.\n" << std::endl;
                    }
                }while(!res.found);
                break;
            }

            //eliminare una nota
            case 5:{
                std::string Temp;
                boolint res{};
                res.found = false;
                do {
                    std::cout << "\nSeleziona una collezione" << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, Temp);
                    res = SeqSearch(RaccoltaCollezioni, RaccoltaCollezioni.size(), Temp);
                    if (res.found) {
                        int s;
                        std::cout << "\nQuale nota si vuole eliminare della collezione " << std::endl;
                        Ctrl->setCol(RaccoltaCollezioni[res.count]);
                        Ctrl->ViewCol();
                        do{
                            std::cin >> s;
                        }while (s>0 && s<(RaccoltaCollezioni[res.count]->CollectionSize()-1));
                        Ctrl->RemoveNote(s);
                    } else {
                        std::cout << "\nLa collezione cercata non esiste. Selezionarne un'altra\n" << std::endl;
                    }
                }while(!res.found);
                break;
            }

            //eliminare una collezione
            case 6:{
                std::string Temp;
                boolint res{};
                res.found = false;
                do {
                    std::cout << "\nSeleziona una collezione" << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, Temp);
                    res = SeqSearch(RaccoltaCollezioni, RaccoltaCollezioni.size(), Temp);
                    if (res.found) {
                        RaccoltaCollezioni[res.count]->~Collezione();
                    } else {
                        std::cout << "\nLa collezione cercata non esiste. Selezionarne un'altra\n" << std::endl;
                    }
                }while(!res.found);
                break;
            }

            //exit
            case 0:
            {
                exit = 1;
                break;
            }

            default:{
                std::cout << "I seriously have no idea how you managed to execute this line of code" << std::endl;
                exit = 0;
                break;
            }
        }
    }while(exit != 1);

    return 0;
}