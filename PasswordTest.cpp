#include <gtest/gtest.h>
#include "Password.h"


class PasswordTest : public ::testing::Test {
protected:
    Password my_password;  

    void SetUp() override {
        my_password = Password();  
    }

    void TearDown() {

    
    }
};


TEST_F(PasswordTest, SingleLetterPassword) {
    int actual = my_password.count_leading_characters("Z");
    ASSERT_EQ(1, actual);
}

TEST_F(PasswordTest, MixedCaseDetection) {
    ASSERT_FALSE(my_password.has_mixed_case("aaaaa"));
    ASSERT_FALSE(my_password.has_mixed_case("AAAAA"));
    ASSERT_TRUE(my_password.has_mixed_case("aA"));
    ASSERT_TRUE(my_password.has_mixed_case("Aa"));
    ASSERT_FALSE(my_password.has_mixed_case("12345"));
    ASSERT_FALSE(my_password.has_mixed_case("!!!!"));
}

TEST_F(PasswordTest, SetPasswordCriteria) {
    my_password.set("Short1");
    ASSERT_FALSE(my_password.authenticate("Short1"));
    my_password.set("ThisIsAVeryLongPasswordExceedingLimit");
    ASSERT_FALSE(my_password.authenticate("ThisIsAVeryLongPasswordExceedingLimit"));
    my_password.set("alllowercase");
    ASSERT_FALSE(my_password.authenticate("alllowercase"));
    my_password.set("ValidPass1");
    ASSERT_TRUE(my_password.authenticate("ValidPass1"));
    my_password.set("aaaaValidPass1");
    ASSERT_FALSE(my_password.authenticate("aaaaValidPass1"));
}

TEST_F(PasswordTest, PasswordHistory) {
    my_password.set("Password1");
    my_password.set("Password2");
    ASSERT_FALSE(my_password.authenticate("Password1"));
    ASSERT_TRUE(my_password.authenticate("Password2"));
}

TEST_F(PasswordTest, RepeatPassword) {
    my_password.set("RepeatPass1");
    ASSERT_TRUE(my_password.authenticate("RepeatPass1"));
    my_password.set("RepeatPass1");
    my_password.set("NewPass1");
    ASSERT_FALSE(my_password.authenticate("RepeatPass1"));
    ASSERT_TRUE(my_password.authenticate("NewPass1"));
}

TEST_F(PasswordTest, DefaultPasswordSet) {
    ASSERT_TRUE(my_password.authenticate("ChicoCA-95929"));
}

TEST_F(PasswordTest, CountLeadingCharacters) {
    ASSERT_EQ(1, my_password.count_leading_characters("Z"));
    ASSERT_EQ(0, my_password.count_leading_characters(""));
    ASSERT_EQ(5, my_password.count_leading_characters("aaaaa"));
    ASSERT_EQ(1, my_password.count_leading_characters("abcdef"));
    ASSERT_EQ(1, my_password.count_leading_characters("aAa"));
}


class PracticeTest : public ::testing::Test {
protected:
    Password my_password;

    void SetUp() override {
        my_password = Password(); 
    }
};

TEST_F(PracticeTest, EmptyPassword) {
    int actual = my_password.count_leading_characters("");
    ASSERT_EQ(0, actual);
}

TEST_F(PracticeTest, SingleCharacterRepeated) {
    int actual = my_password.count_leading_characters("aaaaa");
    ASSERT_EQ(5, actual);
}

TEST_F(PracticeTest, NoRepeats) {
    int actual = my_password.count_leading_characters("abcdef");
    ASSERT_EQ(1, actual);
}

TEST_F(PracticeTest, CaseSensitivity) {
    int actual = my_password.count_leading_characters("aAa");
    ASSERT_EQ(1, actual);
}
