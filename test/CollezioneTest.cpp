#include "gtest/gtest.h"
#include "../Collezione.h"
#include "../Notes.h"


TEST(Collezione, ConstructorsTest) {
    Collezione colTest("Titolo di prova");
    EXPECT_EQ("Titolo di prova", colTest.getTitolo());
}

TEST(Collezione, AddNoteTest){
    Notes notaTest = Notes("Titolo nota 1", "Testo nota 1", false);
    Collezione ColTest("Titolo di prova");
    int OriginalSize = ColTest.CollectionSize();

    ColTest.AddNotes(notaTest);
    ASSERT_FALSE(OriginalSize == ColTest.CollectionSize());
}