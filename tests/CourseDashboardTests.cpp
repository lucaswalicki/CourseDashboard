#include <gtest/gtest.h>
#include "CourseDashboard.hpp"
#include "UserData.hpp"
#include "User.hpp"

using namespace ::testing;

struct UserDataTests : public ::testing::Test
{
    User *user;
    User *user2;
    UserData *userData;
    UserDataTests()
    {
        user = new User("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
        user2 = new User("Krzysiek", "Cypher", "weekendowa", "firecodeLink", "gitHubLink");
        userData = new UserData;
    }

    bool createUser(User user)
    {
        userData->createUser(user);
        return true;
    }

    bool retrieveUser(User user)
    {
        userData->retriveUserByNick(user.getNick());
        return true;
    }

    bool updateUser(User user)
    {
        userData->updateUser(user, "Krzysiek", "Cypher", "weekendowa", "firecodeLink", "gitHubLink");
        return true;
    }

    bool showAll()
    {
        userData->showAll();
        return true;
    }
    
    bool deleteByNick(User user)
    {
        userData->deleteUserByNick(user.getNick());
        return true;
    }
    ~UserDataTests()
    {
        delete user;
        delete user2;
        delete userData;
    };

};

TEST(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}

TEST_F(UserDataTests, canCreateUser)
{
    auto result = createUser(*user);
    ASSERT_TRUE(result);
}

TEST_F(UserDataTests, canRetrieveUserByNick)
{
    createUser(*user);
    auto result = retrieveUser(*user);
    ASSERT_TRUE(result);
}

TEST_F(UserDataTests, canUpdateUserData)
{
    createUser(*user);
    auto result = updateUser(*user);
    ASSERT_TRUE(result);
}

TEST_F(UserDataTests, canShowAllUsers)
{
    createUser(*user);
    createUser(*user2);
    auto result = showAll();
    ASSERT_TRUE(result);
}

TEST_F(UserDataTests, canDeleteUserByNick)
{
    createUser(*user);
    createUser(*user2);
    showAll();
    auto result = deleteByNick(*user);
    std::cout << "After delete" << std::endl;
    showAll();
    ASSERT_TRUE(result);
}

TEST(CourseDashboardTests, canWriteToFile)
{
    //GIVEN
    CourseDashboard testCdb;
    User testUser {"testname","testnick","testgroup","testgithub","testfirecode"};

    //WHEN
    auto result = testCdb.savingToFile(testUser);

    //THEN
    ASSERT_TRUE(result);
}
TEST(CourseDashboardTests, canReadFromFile)
{
    //GIVEN
    CourseDashboard testCdb;

    //WHEN
    auto result = testCdb.readingFromFile();

    //THEN
    ASSERT_TRUE(result);
}
