#include "gtest/gtest.h"
#include "../Collezione.h"
#include "../Notes.h"


class CollezioneTester : public ::testing::Test {
protected:
    Notes notaTest1 = Notes("Titolo nota 1", "Testo nota 1", false);
    Notes notaTest2 = Notes("Titolo nota 2", "Testo nota 2", false);
    Collezione ColTest = Collezione("Collezione di Prova");

    virtual void SetUp(){
        ColTest.AddNotes(notaTest1);
        ColTest.AddNotes(notaTest2);
    }
};

TEST_F(CollezioneTester, RemoveNoteTester){
    ColTest.RemoveNote(1);
    ASSERT_EQ(1, ColTest.CollectionSize());
}
