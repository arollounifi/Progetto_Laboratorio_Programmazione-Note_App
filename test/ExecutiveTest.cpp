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
    Executive e(c1);
    e.setCol(c2);
    e.setTotNotesCount(1);
    e.setTotLockNotesCount(1);
    e.setColLockNotesCount(1);
    e.setColNotesCount(1);
    EXPECT_FALSE(c1 == e.getCol());
    EXPECT_EQ(1, e.getColNotesCount());
    EXPECT_EQ(1, e.getColLockNotesCount());
    EXPECT_EQ(1, e.getTotNotesCount());
    EXPECT_EQ(1, e.getTotLockNotesCount());
}

TEST(Executive, ClassFunctionsTest){
    auto* c = new Collezione("Collezione Prova");
    Executive e(c);
    Notes n("Nota di Prova", "Testo della nota di Prova", true);
    //test AddNote
    e.AddNote(n);
    EXPECT_FALSE(nullptr == c->getNote(0));
    EXPECT_EQ(1, e.getTotNotesCount());
    EXPECT_EQ(1, e.getTotLockNotesCount());
    EXPECT_EQ(1, c->getTotalLockedNotes());
    EXPECT_EQ(1, c->getTotalNotes());
    //test IsNoteLocked
    EXPECT_EQ(true, e.IsNoteLocked(0));
    //test ModifyNote
    const std::string& InitialTitle = n.getTitle();
    const std::string& InitialText = n.getText();
    bool InitialLock = true;
    e.ModifyNote(0, 1, "Nuovo Titolo");
    e.ModifyNote(0, 2, "Nuovo Testo");
    e.ModifyNote(0, 3, "testo qualsiasi");
    auto* pNote = c->getNote(0);
    EXPECT_FALSE(InitialLock == pNote->isLocked());
    EXPECT_FALSE(InitialText == pNote->getText());
    EXPECT_FALSE(InitialTitle == pNote->getTitle());
    //test RemoveNote
    e.RemoveNote(0);
    EXPECT_FALSE(&n == c->getNote(0));
    EXPECT_EQ(0, e.getColNotesCount());
    EXPECT_EQ(0, e.getColLockNotesCount());
    EXPECT_EQ(0, e.getTotNotesCount());
    EXPECT_EQ(0, c->getTotalNotes());
}

