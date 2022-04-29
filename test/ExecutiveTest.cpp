#include "gtest/gtest.h"
#include "../Executive.h"

TEST(Executive, ConstructorTest){
    auto* c = new Collezione("Collezione Prova");
    Executive e(c);
    EXPECT_TRUE(c == e.getCol());
    EXPECT_EQ(0, e.getColNotesCount());
    EXPECT_EQ(0, e.getColLockNotesCount());
    EXPECT_EQ(0, e.getTotNotesCount());
    EXPECT_EQ(0, e.getTotLockNotesCount());
}

TEST(Executive, GetterSetterTest){
    auto* c1 = new Collezione("Collezione Prova 1");
    auto* c2 = new Collezione("Collezione Prova 2");
    Notes n("NotaTest", "TestoTest", true);
    Executive e(c1);
    e.setCol(c2);
    e.AddNote(n);
    EXPECT_EQ(c2, e.getCol());
    EXPECT_EQ(1, e.getColNotesCount());
    EXPECT_EQ(1, e.getColLockNotesCount());
    EXPECT_EQ(1, e.getTotNotesCount());
    EXPECT_EQ(1, e.getTotLockNotesCount());
}

TEST(Executive, ClassFunctionsTest){
    auto* c = new Collezione("Collezione Prova");
    Executive e(c);
    Notes n("Nota di Prova Bloccata", "Testo della nota di Prova", true);
    Notes n2("Nota di Prova non Bloccata", "Testo della nota di Prova", false);
    //test AddNote
    e.AddNote(n);
    e.AddNote(n2);
    EXPECT_FALSE(nullptr == c->getNote(0));
    EXPECT_EQ(2, e.getColNotesCount());
    EXPECT_EQ(1, e.getColLockNotesCount());
    EXPECT_EQ(2, e.getTotNotesCount());
    EXPECT_EQ(1, e.getTotLockNotesCount());
    //test IsNoteLocked
    EXPECT_EQ(true, e.IsNoteLocked(0));
    //test ModifyNote
    EXPECT_FALSE(e.ModifyNote(0, 1, "Nuovo Titolo"));
    EXPECT_TRUE(e.ModifyNote(1, 1, "Nuovo Titolo"));
    e.ModifyNote(1, 2, "Nuovo Testo");
    e.ModifyNote(1, 3, "testo qualsiasi");
    auto* pNote = c->getNote(1);
    EXPECT_TRUE(true == pNote->isLocked());
    EXPECT_TRUE("Nuovo Testo" == pNote->getText());
    EXPECT_TRUE("Nuovo Titolo" == pNote->getTitle());
    //test RemoveNote
    e.RemoveNote(1);
    EXPECT_FALSE(&n2 == c->getNote(1));
    EXPECT_EQ(1, e.getColNotesCount());
    EXPECT_EQ(1, e.getColLockNotesCount());
    EXPECT_EQ(1, e.getTotNotesCount());
    EXPECT_EQ(1, e.getTotLockNotesCount());
}

