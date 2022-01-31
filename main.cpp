#include <iostream>
#include "Notes.h"
#include "Collezione.h"
#include "Displayer.h"
#include <vector>

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

int main() {
    int scelta;
    int exit = 0;
    auto *Important = new Collezione("Important");
    auto *ImportantCounter = new Displayer(Important);
    std::vector<Collezione* > RaccoltaCollezioni;
    RaccoltaCollezioni.push_back(Important);

    do { //do per continuare a mostrare il menù dopo ogni azione
        //"GUI" menu
        std::cout << "\n \n \n =========MENU==========" << std::endl;

        std::cout << "=========AZIONI==========" << std::endl;
        std::cout << "1 - Crea una nuova collezione" << std::endl;
        std::cout << "2 - Crea una nuova nota" << std::endl;
        std::cout << "3 - Modifica una nota" << std::endl;
        std::cout << "4 - Leggi una nota" << std::endl;
        std::cout << "5 - Eliminare una nota" << std::endl;
        std::cout << "6 - Eliminare una collezione" << std::endl;
        std::cout << "0 - Exit" << std::endl;
        std::cout << "\nCollezioni: " << std::endl;

        //visualizzazione delle Collezioni e note
        if(ImportantCounter->getImpNotes()!=0)
            ImportantCounter->show();
        for (const auto itr : RaccoltaCollezioni) {
            std::cout << itr->getTitolo() << "\n" << std::endl;


            for (const auto& itr2 : itr->getCollection()) {
                std::cout << "    -" << itr2.getTitle() << "\n" << std::endl;
            }
        }
        do { //do per accettare solo valori validi come opzioni
            std::cin >> scelta;
        } while (scelta != 0 && scelta != 1 && scelta != 2 && scelta != 3 && scelta != 4 && scelta!=5 && scelta!=6);
        switch (scelta) {
            //creazione di una collezione
            case 1 : {
                auto* Col = new Collezione;
                RaccoltaCollezioni.push_back(Col);
                break;
            }

            //creazione di una nota
            case 2: {
                std::string Temp;
                auto *Not = new Notes;
                std::cout << "\nWhat collection does this note belong to?" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, Temp);
                auto res = SeqSearch(RaccoltaCollezioni, RaccoltaCollezioni.size(), Temp);
                if (res.found) {
                    int s;
                    RaccoltaCollezioni[res.count]->AddNotes(*Not);
                    //possibile aggiunta della nota appena creata anche alla collezione "Important"
                    std::cout << "\nIs this note important? (0=yes / 1=no)" << std::endl;
                    do {
                        std::cin >> s;
                    } while (s != 1 && s != 0);
                    if (s == 0){
                        Important->AddNotes(*Not);
                    }

                } else if (!res.found) { //se la collezione cercata non esiste è possibile crearne una nuova
                    int s;
                    std::cout << "\nLa collezione cercata non esiste. Crearne una nuova?(0=yes / 1=no)" << std::endl;
                    do {
                        std::cin >> s;
                    } while (s != 1 && s != 0);
                    if (s == 0) {
                        auto* NCol = new Collezione(Temp);
                        RaccoltaCollezioni.push_back(NCol);
                        NCol->AddNotes(*Not);
                        //possibile aggiunta della nota appena creata anche alla collezione "Important"
                        std::cout << "\nIs this note important? (0=yes / 1=no)" << std::endl;
                        do {
                            std::cin >> s;
                        } while (s != 1 && s != 0);
                        if (s == 0){
                            Important->AddNotes(*Not);
                        }
                    }
                }
                break;
            }

                //modifica di una nota
            case 3:{
                std::string Temp;
                boolint res{};
                res.found = false;
                do {
                    std::cout << "\nSelect a Collection" << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, Temp);
                    res = SeqSearch(RaccoltaCollezioni, RaccoltaCollezioni.size(), Temp);
                    if (res.found) {
                        int s;
                        std::cout << "\nE' stata selezionata la collezione " << RaccoltaCollezioni[res.count]->getTitolo() << ". Quale nota si vuole modificare?" << std::endl;
                        RaccoltaCollezioni[res.count]->View();
                        do{
                            std::cin >> s;
                        }while (s>0 && s<RaccoltaCollezioni[res.count]->getCollection().size());
                        RaccoltaCollezioni[res.count]->ModifyNote(s);
                    } else {
                        std::cout << "\nLa collezione cercata non esiste. Selezionarne un'altra\n" << std::endl;
                    }
                }while(!res.found);
                break;
            }

                //visualizzazione di una nota
            case 4: {
                std::string Temp;
                boolint res{};
                res.found = false;
                do {
                    std::cout << "\nSelect a Collection" << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, Temp);
                    res = SeqSearch(RaccoltaCollezioni, RaccoltaCollezioni.size(), Temp);
                    if (res.found) {
                        int s;
                        std::cout << "\nE' stata selezionata la collezione " << RaccoltaCollezioni[res.count]->getTitolo() << ". Quale nota si vuole eliminare?" << std::endl;
                        RaccoltaCollezioni[res.count]->View();
                        do{
                            std::cin >> s;
                        }while (s>0 && s<(RaccoltaCollezioni[res.count]->getCollection().size()-1));
                        RaccoltaCollezioni[res.count]->ViewNote(s);
                    } else {
                        std::cout << "\nLa collezione cercata non esiste. Selezionarne un'altra\n" << std::endl;
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
                    std::cout << "\nSelect a Collection" << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, Temp);
                    res = SeqSearch(RaccoltaCollezioni, RaccoltaCollezioni.size(), Temp);
                    if (res.found) {
                        int s;
                        std::cout << "\nE' stata selezionata la collezione " << RaccoltaCollezioni[res.count]->getTitolo() << ". Quale nota si vuole visualizzare?" << std::endl;
                        RaccoltaCollezioni[res.count]->View();
                        do{
                            std::cin >> s;
                        }while (s>0 && s<(RaccoltaCollezioni[res.count]->getCollection().size()-1));
                        RaccoltaCollezioni[res.count]->RemoveNote(s);
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
                    std::cout << "\nSelect a Collection" << std::endl;
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
                exit = 0;
                break;
            }
        }
    }while(exit != 1);

    return 0;
}