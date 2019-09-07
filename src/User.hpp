#pragma once
#include <string>
#include "nlohmann/json.hpp"

class User
{
public:
    enum class Group
    {
        weekend,
        evening
    };

    User(const std::string & name,
         const std::string & nick,
         Group group,
         const std::string & gitHub,
         const std::string & firecode);

    User(nlohmann::json userJson);
   
    std::string toString() const;
    nlohmann::json toJson() const;

    void setName(std::string_view name);
    void setNick(std::string_view nick);
    void setGroup(Group group);
    void setGitHub(std::string_view gitHub);
    void setFirecode(std::string_view firecode);
    std::string getNick() const;

    friend bool operator==(const User &lhs, const User& rhs);

private:
    std::string name_;
    std::string nick_;
    Group group_;
    std::string gitHub_;
    std::string firecode_;  

};

//bool operator==(const User &lhs, const User& rhs);

using Users = std::vector<User>;
