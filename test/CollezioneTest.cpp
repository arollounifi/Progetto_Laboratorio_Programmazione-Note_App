#include "gtest/gtest.h"
#include "../Collezione.h"
#include "../Executive.h"


TEST(Collezione, ConstructorsTest) {
    Collezione colTest1("Titolo di prova");
    std::string TitoloProva = "Titolo Prova";
    Collezione colTest2(TitoloProva);
    //test per primo costruttore
    EXPECT_EQ("Titolo di prova", colTest1.getTitolo());
    EXPECT_EQ(0, colTest1.getTotalNotes());
    EXPECT_EQ(0, colTest1.getTotalLockedNotes());
    //test per secondo costruttore
    EXPECT_EQ("Titolo Prova", colTest2.getTitolo());
    EXPECT_EQ(0, colTest2.getTotalNotes());
    EXPECT_EQ(0, colTest2.getTotalLockedNotes());
}

TEST(Collezione, ClassFunctionsTest){
    Notes notaTest = Notes("Titolo nota 1", "Testo nota 1", false);
    auto* ColTest = new Collezione("Titolo di prova");
    auto* e = new Executive(ColTest);
    e->AddNote(notaTest);
    EXPECT_EQ(1, ColTest->CollectionSize());
    ASSERT_TRUE(nullptr != ColTest->getNote(0));
    EXPECT_EQ(1, ColTest->getTotalNotes());
    EXPECT_EQ(0, ColTest->getTotalLockedNotes());
}