#include "pch.h"
#include "Kantorex_login/User.hpp"
#include "Kantorex_login/UsersList.hpp"
#include "Kantorex_login/ReadJSONfile.hpp"
#include "Kantorex_login/Authorization.hpp"
#include <vector>

//int User::_counter = 0;

class UserTest : public ::testing::Test
{
protected:
	UserTest()
		: objectUnderTest("Maja", "Kaleta", "cashier", "1234", ApplicationRole::CASHIER)
	{};
	User objectUnderTest;
};

class ReadJSONfileTest : public ::testing::Test
{
protected:
	ReadJSONfileTest()
		: usersListInput{
							{"Maja", "Kaleta", "cashier", "1234", ApplicationRole::CASHIER},
							{"Lili", "Sobieski", "admin", "8888", ApplicationRole::ADMINISTRATOR},
							{"Tom", "Tomski", "guest", "9999", ApplicationRole::GUEST}
	}
		, objectUnderTest()
	{};
	std::vector<User> usersListInput;
	ReadJSONfile objectUnderTest;
};

class AuthorizationTest : public ::testing::Test
{
protected:
	AuthorizationTest()
		: usersListInput{
					{"Maja", "Kaleta", "cashier", "1234", ApplicationRole::CASHIER},
					{"Lili", "Sobieski", "admin", "8888", ApplicationRole::ADMINISTRATOR},
					{"Tom", "Tomski", "guest", "9999", ApplicationRole::GUEST}
			}
		, enteredLogin("cashier")
		, enteredPassword("1234")
		, _checkedUser("Maja", "Kaleta", "cashier", "1234", ApplicationRole::CASHIER)
	{};
	std::vector<User> usersListInput;
	std::string enteredLogin;
	std::string enteredPassword;
	User _checkedUser;
	//UsersList _users;
	Authorization objectUnderTest;
};

//class UsersListTest : public ::testing::Test
//{
//protected:
//	std::vector<User> testedUsersListInput;
//	std::shared_ptr<std::vector<User>> testedList;
//	UsersList objectUnderTest;
//	UsersListTest()
//		: testedUsersListInput{
//			{"Maja", "Kaleta", "cashier", "1234", ApplicationRole::CASHIER},
//			{"Lili", "Sobieski", "admin", "8888", ApplicationRole::ADMINISTRATOR},
//			{"Tom", "Tomski", "guest", "9999", ApplicationRole::GUEST}
//	}
//		, testedList(std::make_shared<std::vector<User>>(testedUsersListInput)
//		, objectUnderTest()
//	{
//
//	};
//};


//		User user1("Maja", "Kaleta", "cashier", "1234", ApplicationRole::CASHIER);
//		User user2("Lili", "Sobieski", "admin", "8888", ApplicationRole::ADMINISTRATOR);
//		User user3("Tom", "Tomski", "guest", "9999", ApplicationRole::GUEST);
//		_testedList.emplace_back("Maja", "Kaleta", "cashier", "1234", ApplicationRole::CASHIER);
//		_testedList.emplace_back("Lili", "Sobieski", "admin", "8888", ApplicationRole::ADMINISTRATOR);
//		_testedList.emplace_back("Tom", "Tomski", "guest", "9999", ApplicationRole::GUEST);
//	//}
//	//std::shared_ptr<std::vector<User>> _testedList;
//};


TEST(classUser_enamToString, enteredValue_ApplicationRole_ADMINISTRATOR_expectedReturnValue_administrator) 
{
	User user;
	EXPECT_EQ(user.enumToString(ApplicationRole::ADMINISTRATOR), "administrator");
}
TEST(classUser_enamToString, enteredValue_ApplicationRole_GUEST_expectedReturnValue_guest)
{
	User user;
	EXPECT_EQ(user.enumToString(ApplicationRole::GUEST), "guest");
}
TEST(classUser_enamToString, enteredValue_ApplicationRole_CASHIER_expectedReturnValue_cashier)
{
	User user;
	EXPECT_EQ(user.enumToString(ApplicationRole::CASHIER), "cashier");
}

TEST(classUser_stringToEnum, enteredValue_administrator_expectedReturnValue_ApplicationRole_ADMINISTRATOR)
{
	User user;
	EXPECT_EQ(user.stringToEnum("administrator"), ApplicationRole::ADMINISTRATOR);
}
TEST(classUser_stringToEnum, enteredValue_guest_expectedReturnValue_ApplicationRole_GUEST)
{
	User user;
	EXPECT_EQ(user.stringToEnum("guest"), ApplicationRole::GUEST);
}
TEST(classUser_stringToEnum, enteredValue_cashier_expectedReturnValue_ApplicationRole_CASHIER)
{
	User user;
	EXPECT_EQ(user.stringToEnum("cashier"), ApplicationRole::CASHIER);
}
TEST(classUser_getAppRole_str, expectedReturnValue_guest_defaultValue)
{
	User user;
	EXPECT_EQ(user.getAppRole_str(), "guest");
}
TEST(classUser_getAppRole_enum, expectedReturnValue_ApplicationRole_GUEST)
{
	User user;
	EXPECT_EQ(user.getAppRole_enum(), ApplicationRole::GUEST);
}

TEST(classUsersList_getUser, enteredValue_int_1_expectedReturnValue_user1_id_str_1)
{
	UsersList list;
	User user1;
	user1 = list.getUser(1);
	EXPECT_EQ(user1.getUserId(), "1");
}
// class Authorization

TEST_F(AuthorizationTest, checkLogin)
{
	EXPECT_EQ(objectUnderTest.checkLogin(enteredLogin),true);
}
TEST_F(AuthorizationTest, checkPassword)
{
	EXPECT_EQ(objectUnderTest.checkPassword(enteredPassword), true);
}

// class User

TEST_F(UserTest, getUserId)
{
	EXPECT_EQ(objectUnderTest.getUserId(), "1");
}

TEST_F(UserTest, getUserFirstname)
{
	EXPECT_EQ(objectUnderTest.getUserFirstname(), "Maja");
}

TEST_F(UserTest, getUserLastname)
{
	EXPECT_EQ(objectUnderTest.getUserLastname(), "Kaleta");
}

TEST_F(UserTest, getUserLogin)
{
	EXPECT_EQ(objectUnderTest.getLogin(), "cashier");
}
TEST_F(UserTest, getPassword)
{
	EXPECT_EQ(objectUnderTest.getPassword(), "1234");
}
TEST_F(UserTest, getAppRole)
{
	EXPECT_EQ(objectUnderTest.getAppRole_enum(), ApplicationRole::CASHIER);
}