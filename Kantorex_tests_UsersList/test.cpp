#include "pch.h"
#include "Kantorex_login/UsersList.hpp"

class UsersListTest : public ::testing::Test
{
protected:

	UsersListTest()
		: testedUsersListInput{
			{"Maja", "Kaleta", "cashier", "1234", ApplicationRole::CASHIER},
			{"Lili", "Sobieski", "admin", "8888", ApplicationRole::ADMINISTRATOR},
			{"Tom", "Tomski", "guest", "9999", ApplicationRole::GUEST}
	}
		, objectUnderTest(testedUsersListInput)
	{

	};

	std::vector<User> testedUsersListInput;
	UsersList objectUnderTest;
};

// class UsersList
TEST_F(UsersListTest, getUser_enteredValue_int_1_expectedReturnValue_user1_id_str_1)
{
	EXPECT_EQ((objectUnderTest.getUser(1)).getUserId(), "1");
}
TEST_F(UsersListTest, getUser_enteredValue_str_Kaleta_expectedReturnValue_user1_str_Kaleta)
{
	EXPECT_EQ((objectUnderTest.getUser("Kaleta")).getUserLastname(), "Kaleta");
}
TEST_F(UsersListTest, addUser_enteredValue_User4Lovelace_expectedReturnValue_user4Id_str_4_str_Lovelace)
{
	objectUnderTest.addUser("Ada", "Lovelace", "alove", "alove88", ApplicationRole::GUEST);
	EXPECT_EQ((objectUnderTest.getUser("Lovelace")).getUserLastname(), "Lovelace");
	EXPECT_EQ((objectUnderTest.getUser(4)).getUserId(), "4");
}