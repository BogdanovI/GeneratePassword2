#include "passwordassembly.h"
#include <QMessageBox>

char PasswordAssembly::setLowerCaseLetter()
{
    char newLowerLetter;
    newLowerLetter = static_cast<char>(MIN_CODE_LOWER + rand() % (MAX_CODE_LOWER - MIN_CODE_LOWER));
    return newLowerLetter;
}

char PasswordAssembly::setUpperCaseLetter()
{
    char newUpperLetter;
    newUpperLetter = static_cast<char>(MIN_CODE_UPPER + rand() % (MAX_CODE_UPPER - MIN_CODE_UPPER));
    return newUpperLetter;
}

char PasswordAssembly::setTheNumbers()
{
    char newNumber;
    newNumber = static_cast<char>(MIN_CODE_NUM + rand() % (MAX_CODE_NUM - MIN_CODE_NUM));
    return newNumber;
}

QString PasswordAssembly::AssemblyNewPassword()
{
    QString generateNewPassword;
    int choiseSymbol = 0;
    bool checkUpperLeastOne = checkUpper;
    bool checkNumberLeastOne = checkNumber;
    bool checkPasswordSymbolAllUpper = false, checkPasswordSymbolAllNumber = false;
    for (int i = 0; i < setUserQuantityPassword; i++)
    {
        choiseSymbol = 1 + rand() % MAX_DIVERSITY_SYMBOL;
        switch (choiseSymbol)
        {
        case 1:
            generateNewPassword.push_back(setLowerCaseLetter());
            break;
        case 2:
            if (checkUpper == true)
            {
                generateNewPassword.push_back(setUpperCaseLetter());
                checkUpperLeastOne = false;
            }
            else
            {
                generateNewPassword.push_back(setLowerCaseLetter());
            }
            break;
        case 3:
            if (checkNumber == true)
            {
                generateNewPassword.push_back(setTheNumbers());
                checkNumberLeastOne = false;
            }
            else
            {
                generateNewPassword.push_back(setLowerCaseLetter());
            }
            break;
        }
    }
    for (int i = 0; i < generateNewPassword.size(); i++)
    {
        if (generateNewPassword[i].isUpper())
        {
            checkPasswordSymbolAllUpper = true;
        }
        if (generateNewPassword[i].isNumber())
        {
            checkPasswordSymbolAllNumber = true;
        }
    }
    while (checkUpperLeastOne == true || checkNumberLeastOne == true)
    {
        choiseSymbol = rand() % (generateNewPassword.size() - 1);
        if (checkUpperLeastOne == true && !generateNewPassword[choiseSymbol].isNumber())
        {
            generateNewPassword[choiseSymbol] = setUpperCaseLetter();
            checkUpperLeastOne = false;
        }
        if (checkNumberLeastOne == true && !generateNewPassword[choiseSymbol].isUpper())
        {
            generateNewPassword[choiseSymbol] = setTheNumbers();
            checkNumberLeastOne = false;
        }
        if (checkPasswordSymbolAllUpper == true)
        {
            generateNewPassword[choiseSymbol] = setTheNumbers();
        }
        if (checkPasswordSymbolAllNumber == true)
        {
            generateNewPassword[choiseSymbol] = setUpperCaseLetter();
        }
    }
    return generateNewPassword;
}
