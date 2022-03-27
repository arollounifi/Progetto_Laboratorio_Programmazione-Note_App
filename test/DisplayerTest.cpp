#include "gtest/gtest.h"
#include "../Displayer.h"

TEST(Displayer, DefaultConstructor) {
    auto* c = new Collezione("Collezione di prova");
    auto* e = new Executive(c);
    Displayer d(e);
    EXPECT_FALSE(d.getpExecutive() == nullptr);
    EXPECT_EQ(0, d.getTotalNotes());
    EXPECT_EQ(0, d.getTotalLockNotes());
    EXPECT_EQ(0, d.getCollectionLockNotes());
    EXPECT_EQ(0, d.getCollectionNotes());
}

TEST(Displayer, UpdateTester) {
    auto* c = new Collezione("Collezione di prova");
    auto* e = new Executive(c);
    Displayer d(e);
    //simulate notes creation
    e->setTotLockNotesCount(1);
    e->setTotNotesCount(1);
    e->setColNotesCount(1);
    e->setColLockNotesCount(1);
    d.update();
    EXPECT_EQ(1, d.getTotalNotes());
    EXPECT_EQ(1, d.getTotalLockNotes());
    EXPECT_EQ(1, d.getCollectionLockNotes());
    EXPECT_EQ(1, d.getCollectionNotes());
}
