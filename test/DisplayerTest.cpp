#include "gtest/gtest.h"

#include "../Displayer.h"
#include "../Collezione.h"


TEST(Displayer, DefaultConstructor) {
    Collezione c("Collezione di Prova");
    Displayer d(&c);
    EXPECT_FALSE(d.getCollection() == nullptr);
    EXPECT_EQ(0, d.getImpNotes());

}

TEST(DisplayerTest, UpdateTester) {
    Collezione c("Collezione di prova");
    Displayer d(&c);
    d.update("added");
    ASSERT_EQ(1, d.getImpNotes());
    d.update("deleted");
    ASSERT_EQ(0, d.getImpNotes());
}
