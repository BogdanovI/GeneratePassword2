#ifndef PASSWORDASSEMBLY_H
#define PASSWORDASSEMBLY_H

#include <QString>
#include <ctime>

class PasswordAssembly
{
private:
    int setUserQuantityPassword;
    bool checkUpper;
    bool checkNumber;
    char setLowerCaseLetter();
    char setUpperCaseLetter();
    char setTheNumbers();
    enum encodingRange
    {
        MAX_DIVERSITY_SYMBOL = 3,
        MIN_CODE_NUM = 48,
        MAX_CODE_NUM = 57,
        MIN_CODE_UPPER = 65,
        MAX_CODE_UPPER = 90,
        MIN_CODE_LOWER = 97,
        MAX_CODE_LOWER = 122
    };

public:
    QString AssemblyNewPassword();
    PasswordAssembly(int setQuantity, bool upperCheck, bool numberCheck)
    {
        checkUpper = upperCheck;
        checkNumber = numberCheck;
        setUserQuantityPassword = setQuantity;
    }
};

#endif // PASSWORDASSEMBLY_H
