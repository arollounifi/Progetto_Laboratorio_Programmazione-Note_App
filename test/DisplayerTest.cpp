#include "gtest/gtest.h"
#include "../Displayer.h"

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
    Notes n("Nota di Prova Bloccata", "Testo della nota di Prova", true);
    Notes n2("Nota di Prova non Bloccata", "Testo della nota di Prova", false);
    auto* c = new Collezione("Collezione di prova");
    auto* e = new Executive(c);
    Displayer d(e);
    e->AddNote(n);
    e->AddNote(n2);
    EXPECT_EQ(2, d.getTotalNotes());
    EXPECT_EQ(1, d.getTotalLockNotes());
    EXPECT_EQ(1, d.getCollectionLockNotes());
    EXPECT_EQ(2, d.getCollectionNotes());
}
