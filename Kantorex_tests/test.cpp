#include "pch.h"
#include "Kantorex_login/User.hpp"
#include "Kantorex_login/UsersList.hpp"
#include "Kantorex_login/Authorization.hpp"
#include "Kantorex_login/LogInManager.hpp"
#include "Kantorex_login/ILoggedUser.hpp"
#include "Kantorex_login/Administrator.hpp"
#include "Kantorex_login/ReadJSONfile.hpp"
#include "Kantorex_login/WriteJSONfile.hpp"
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

class WriteJSONfileTest : public ::testing::Test
{
protected:
	WriteJSONfileTest()
		: testedUsersListInput {
			{"Maja", "Kaleta", "cashier", "1234", ApplicationRole::CASHIER},
			{ "Lili", "Sobieski", "admin", "8888", ApplicationRole::ADMINISTRATOR },
			{ "Tom", "Tomski", "guest", "9999", ApplicationRole::GUEST }
	}
		, list(testedUsersListInput)
	{
	};
	std::vector<User> testedUsersListInput;
	UsersList list;
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

// class ReaderJSONfile
TEST(classReadJSONfile, expectedReturnValue_str_Kaleta)
{
	ReadJSONfile file;
	std::vector<User> list = file.read();
	EXPECT_EQ(list[0].getUserLastname(), "Kaleta");
	EXPECT_EQ(list[1].getUserLastname(), "Sobieski");
	EXPECT_EQ(list[2].getUserLastname(), "Tomski");
}
TEST(classReadJSONfile, expectedReturnValue_str_Tomski)
{
	ReadJSONfile file;
	std::vector<User> list = file.read();
	EXPECT_EQ(list[2].getUserLastname(), "Tomski");
}
//TEST(classReadJSONfile, expectedReturnValue_str_Tomski)
//{
//	ReadJSONfile file;
//	std::vector<User> list = file.read();
//	EXPECT_EQ(list[2].getUserLastname(), "Inny");
//}

// classWriteJSONfile
TEST_F(WriteJSONfileTest, expectedReturnValue_str_Sobieski)
{
	WriteJSONfile fileWrite;
	list.addUser("Jan", "Sobieski", "jsob", "1234", ApplicationRole::GUEST);
	fileWrite.write(list.getUsersList());
	ReadJSONfile fileRead;
	std::vector<User> list = fileRead.read();
	auto it = list.end()-1;
	EXPECT_EQ((*it).getUserLastname(), "Sobieski");
}