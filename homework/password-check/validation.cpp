#include "validation.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>

std::string getErrorMessage(ErrorCode errorCode) {
    int errorCodeNum = static_cast<int>(errorCode);
    switch (errorCodeNum) {
    case 0:
        return "Ok";
        break;
    case 1:
        return "Password needs to have at least nine characters";
        break;
    case 2:
        return "Password needs to have at least one number";
        break;
    case 3:
        return "Password needs to have at least one special character";
        break;
    case 4:
        return "Password needs to have at least one uppercase letter";
        break;
    case 5:
        return "Passwords do not match";
        break;
    default:
        return "Invalid error";
        break;
    }
}

bool doPasswordsMatch(std::string passwordA, std::string passwordB) {
    return (passwordA == passwordB) ? true : false;
}

ErrorCode checkPasswordRules(std::string password) {
    if (password.size() < 9)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    else if (std::none_of(password.begin(), password.end(), isdigit))
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    else if (std::all_of(password.begin(), password.end(), isalnum))
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    else if (std::none_of(password.begin(), password.end(), isupper))
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    else
        return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string password, std::string repeatedPassword) {
    if (doPasswordsMatch(password, repeatedPassword))
        return checkPasswordRules(password);
    else
        return ErrorCode::PasswordsDoNotMatch;
}

