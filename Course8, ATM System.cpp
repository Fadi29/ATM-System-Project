#include <iostream>
#include "StringLib.h"
#include "BankLib.h"
using namespace std;

const string FileOfClientData = "ClientData.txt";

enum enMainAtmOptions {
    enQuickWithdraw = 1, enNormalWithdraw = 2, enDeposit = 3,
    enCheckBalance = 4, enLogout = 5, enExit = 6
};

void AtmMainMenuScreen()
{
    BankLib::LineSeperator(40);
    cout << '\n';
    cout << setw(11) << "" << "ATM Main Menu Screen";
    cout << '\n';
    BankLib::LineSeperator(40);

    cout << "\n\t [1] Quick Withdraw.\n";
    cout << "\t [2] Normal Withdraw.\n";
    cout << "\t [3] Deposit.\n";
    cout << "\t [4] Check Balance.\n";
    cout << "\t [5] Logout.\n";
    cout << "\t [6] Exit.\n";
    BankLib::LineSeperator(40);
}

void QuickWithdrawScreen()
{
    BankLib::HeaderOfSubScreens("      Quick Withdraw", BankLib::SeperatorType::thick);
    cout << "\n\t[1] 20        [2] 50\n";
    cout << "\t[3] 100       [4] 200\n";
    cout << "\t[5] 400       [6] 600\n";
    cout << "\t[7] 800       [8] 1000\n";
    cout << "\t[9] Exit\n";
    BankLib::LineSeperator(40);
}

bool CheckClientLoginIsRight(const vector <stClient>& vClientsData, stClient& stClientInfo)
{
    for (const stClient& C : vClientsData)
    {
        if (C.AccountNumber == stClientInfo.AccountNumber && C.PinCode == stClientInfo.PinCode)
        {
            stClientInfo = C;
            return true;
        }
    }
    return false;
}


void Login(const vector <stClient> &vClientsData, stClient &stClientInfo)
{
    cout << '\n';
    BankLib::HeaderOfSubScreens("      Login Screen");
    cout << '\n';
    stClientInfo.AccountNumber = BankLib::ReadString("Enter Account Number? ");
    stClientInfo.PinCode = BankLib::ReadString("Enter PinCode? ");

    while (!CheckClientLoginIsRight(vClientsData, stClientInfo))
    {
        system("cls");
        BankLib::HeaderOfSubScreens("      Login Screen");
        cout << '\n';
        cout << "Invalid Account Number/PinCode!\n";
        stClientInfo.AccountNumber = BankLib::ReadString("Enter Account Number? ");
        stClientInfo.PinCode = BankLib::ReadString("Enter Pin? ");
    }

    system("cls");
}

void CheckBalance(const stClient &stClientInfo)
{
    BankLib::HeaderOfSubScreens("  Check Balance Screen", BankLib::SeperatorType::thick);

    cout << "\nYour Balance is " << stClientInfo.AccountBalance;
    BankLib::PressAnyKeySentence();
}

bool QuickWithdraw(stClient& stClientInfo)
{
    const static short NumOfMoneyToWithdraw[9] = { 0, 20, 50, 100, 200, 400, 600, 800, 1000 };
    
    int NumToWithdraw;
    QuickWithdrawScreen();
    cout << "\nYour Balance is " << stClientInfo.AccountBalance;
    do
    {
        NumToWithdraw = BankLib::ReadInt("\nChoose what to withdraw from [1] to [8] ? ");
        if (NumToWithdraw == 9)
        {
            BankLib::PressAnyKeySentence();
            return false;
        }
    } while (NumToWithdraw > 8 || NumToWithdraw < 1);
    
    if (NumOfMoneyToWithdraw[NumToWithdraw] > stClientInfo.AccountBalance)
    {
        cout << "\n\nThe amount exceeds your balance, make another choice.";
        BankLib::PressAnyKeySentence();
        return false;
    }

    if (!BankLib::YOrNQuestion("\n\nAre you sure you want perform this transactions? y/n ? "))
    {
        BankLib::PressAnyKeySentence();
        return false;
    }
    
    stClientInfo.AccountBalance -= NumOfMoneyToWithdraw[NumToWithdraw];
    cout << "\n\nDone Successfully, New balance is: " << stClientInfo.AccountBalance;
    BankLib::PressAnyKeySentence();
    return true;
}

bool NormalWithdraw(stClient& stClientInfo)
{
    BankLib::HeaderOfSubScreens("  Normal Withdraw Screen", BankLib::SeperatorType::thick);
    int NumToWithdraw;

    do   
        NumToWithdraw = BankLib::ReadInt("\nEnter an amount multiple of 5's ? ");
     while (NumToWithdraw % 5 != 0 && NumToWithdraw > 0);

     if (NumToWithdraw > stClientInfo.AccountBalance)
     {
         cout << "\n\nThe amount exceeds your balance, make another choice.";
         BankLib::PressAnyKeySentence();
         return false;
     }
     
     if (!BankLib::YOrNQuestion("\n\nAre you sure you want perform this transactions? y/n ? "))
     {
         BankLib::PressAnyKeySentence();
         return false;
     }

     stClientInfo.AccountBalance -= NumToWithdraw;
     cout << "\n\nDone Successfully, New balance is: " << stClientInfo.AccountBalance;
     BankLib::PressAnyKeySentence();
     return true;
}

bool Deposit(stClient& stClientInfo)
{
    BankLib::HeaderOfSubScreens("        Deposit Screen", BankLib::SeperatorType::thick);   
    int AmountToDeposit;
    cout << '\n';

    do
        AmountToDeposit = BankLib::ReadInt("\nEnter an positive Deposit Amount? ");
    while (AmountToDeposit < 0);

    if (!BankLib::YOrNQuestion("\n\nAre you sure you want perform this transactions? y/n ? "))
    {
        BankLib::PressAnyKeySentence();
        return false;
    }

    stClientInfo.AccountBalance += AmountToDeposit;
    cout << "\n\nDone Successfully, New balance is: " << stClientInfo.AccountBalance;
    BankLib::PressAnyKeySentence();
    return true;
}

void AtmMainControlPanel()
{
    vector <stClient> vClientsData = StringLib::LoadClientsDataFromFile(FileOfClientData);
    stClient stClientInfo;
    bool IsDataChanged = false;
    enMainAtmOptions AtmOptions = enMainAtmOptions::enExit;  
    Login(vClientsData, stClientInfo);
    system("cls");
    do
    {
        AtmMainMenuScreen();
        cout << '\n';
        AtmOptions = enMainAtmOptions(BankLib::ReadInt("Choose what do you want to do? [1 to 5]? "));
        // be careful from Variable Shadowing!
        system("cls");
        switch (AtmOptions)
        {
        case enMainAtmOptions::enQuickWithdraw:
            IsDataChanged = QuickWithdraw(stClientInfo);
            break;
        case enMainAtmOptions::enNormalWithdraw:
            IsDataChanged = NormalWithdraw(stClientInfo);
            break;
        case enMainAtmOptions::enDeposit:
            IsDataChanged = Deposit(stClientInfo);
            break;
        case enMainAtmOptions::enCheckBalance:
            CheckBalance(stClientInfo);
            break;
        case enMainAtmOptions::enLogout:
            Login(vClientsData, stClientInfo);
            break;
        }
        if (IsDataChanged)
        {
            BankLib::SaveClientInfoInVector(vClientsData, stClientInfo, stClientInfo.AccountNumber);
            StringLib::SaveClientsDataToFile(FileOfClientData, vClientsData);
        }

        system("cls");
    } while (AtmOptions != enMainAtmOptions::enExit);

    cout << '\n';
    BankLib::HeaderOfSubScreens("Program Ends :-)");
}

int main()
{  
    AtmMainControlPanel();  
    system("pause>0");

    return 0;
}
