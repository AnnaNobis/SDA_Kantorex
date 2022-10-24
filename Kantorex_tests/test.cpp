#include "pch.h"
#include "Kantorex_login/User.hpp"
#include "Kantorex_login/UsersList.hpp"
#include "Kantorex_login/Authorization.hpp"
#include "Kantorex_login/LogInManager.hpp"
#include "Kantorex_login/ILoggedUser.hpp"
#include "Kantorex_login/Administrator.hpp"
#include <vector>

class UserTest : public ::testing::Test
{
protected:
	UserTest()
		: _objectUnderTest("Maja", "Kaleta", "cashier", "1234", ApplicationRole::CASHIER)
	{};
	User _objectUnderTest;
};

class AuthorizationTest : public ::testing::Test
{
protected:
	AuthorizationTest()
		: _usersListInput{
					{"Maja", "Kaleta", "cashier", "1234", ApplicationRole::CASHIER},
					{"Lili", "Sobieski", "admin", "8888", ApplicationRole::ADMINISTRATOR},
					{"Tom", "Tomski", "guest", "9999", ApplicationRole::GUEST}
			}
		, _enteredLogin("cashier")
		, _enteredPassword("1234")
		, _users(_usersListInput)
		, _checkedUser(_users.getUser(1))
	{};
	std::vector<User> _usersListInput;
	std::string _enteredLogin;
	std::string _enteredPassword;
	User _checkedUser;
	UsersList _users;
	Authorization _objectUnderTest;
};

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



// class User
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
TEST_F(UserTest, getUserId)
{
	EXPECT_EQ(_objectUnderTest.getUserId(), "1");
}

TEST_F(UserTest, getUserFirstname)
{
	EXPECT_EQ(_objectUnderTest.getUserFirstname(), "Maja");
}

TEST_F(UserTest, getUserLastname)
{
	EXPECT_EQ(_objectUnderTest.getUserLastname(), "Kaleta");
}

TEST_F(UserTest, getUserLogin)
{
	EXPECT_EQ(_objectUnderTest.getLogin(), "cashier");
}
TEST_F(UserTest, getPassword)
{
	EXPECT_EQ(_objectUnderTest.getPassword(), "1234");
}
TEST_F(UserTest, getAppRole)
{
	EXPECT_EQ(_objectUnderTest.getAppRole_enum(), ApplicationRole::CASHIER);
}

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
	//EXPECT_EQ((objectUnderTest.getUser(4)).getUserId(), "4");
}

// class Authorization
TEST_F(AuthorizationTest, checkLogin)
{
	EXPECT_EQ(_objectUnderTest.checkLogin(_enteredLogin),true);
}
TEST_F(AuthorizationTest, checkPassword)
{
	EXPECT_EQ(_objectUnderTest.checkPassword(_enteredPassword), true);
}


// class ILoggedUsers
TEST(classAdministrator_getCanBuy, expectedReturnValue_False)
{
	std::shared_ptr<ILoggedUser> loggedUser = std::make_shared<Administrator>();
	EXPECT_EQ(loggedUser->getCanBuy(), false);
}
TEST(classAdministrator_getCanSell, expectedReturnValue_False)
{
	std::shared_ptr<ILoggedUser> loggedUser = std::make_shared<Administrator>();
	EXPECT_EQ(loggedUser->getCanSell(), false);
}
TEST(classAdministrator_getCanBalance, expectedReturnValue_True)
{
	std::shared_ptr<ILoggedUser> loggedUser = std::make_shared<Administrator>();
	EXPECT_EQ(loggedUser->getCanBalance(), true);
}
TEST(classAdministrator_getCanRepart, expectedReturnValue_True)
{
	std::shared_ptr<ILoggedUser> loggedUser = std::make_shared<Administrator>();
	EXPECT_EQ(loggedUser->getCanReport(), true);
}
// negative
//TEST(classAdministrator_getCanRepart, expectedReturnValue_Truef)
//{
//	std::shared_ptr<ILoggedUser> loggedUser = std::make_shared<Administrator>();
//	EXPECT_EQ(loggedUser->getCanReport(), false);
//}


// class LogInManager
//TEST(classLogInManager_hidePassword, enteredValue_str_password_expectedReturnValue_str_password)
//{
//	LogInManager objectUnderTest;
//	EXPECT_EQ(objectUnderTest.hidePassword("password"), "password");
//}