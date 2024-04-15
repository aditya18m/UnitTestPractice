/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST_F(PracticeTest, empty_password) {
    Password my_password;
    int actual = my_password.count_leading_characters("");
    ASSERT_EQ(0, actual);
}

TEST_F(PracticeTest, single_character_repeated) {
    Password my_password;
    int actual = my_password.count_leading_characters("aaaaa");
    ASSERT_EQ(5, actual);
}

TEST_F(PracticeTest, no_repeats) {
    Password my_password;
    int actual = my_password.count_leading_characters("abcdef");
    ASSERT_EQ(1, actual);
}

TEST_F(PracticeTest, case_sensitivity) {
    Password my_password;
    int actual = my_password.count_leading_characters("aAa");
    ASSERT_EQ(1, actual);
}