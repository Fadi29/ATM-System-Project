#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>
#include "StringLib.h"
using namespace std;



namespace BankLib
{

    enum SeperatorType { thick = 1, Thin = 0 };

    struct stUser
    {
        string Name;
        string Password;
        int Permission;
        bool DeleteMark = false;
    };

    string ReadString(string Message)
    {
        string Str;
        cout << Message;
        getline(cin >> ws, Str);
        return Str;
    }

    bool YesOrNo(string Message)
    {
        string YOrN = "";
        cout << Message;
        getline(cin >> ws, YOrN);
        return StringLib::LowerAllLetters(YOrN) == "yes"; // remember dont use if Its already boolean    
    }

    bool YOrNQuestion(string Message)
    {
        char YOrN;
        cout << Message;
        cin >> YOrN;
        return tolower(YOrN) == 'y';
    }

    void PressAnyKeySentence()
    {
        cout << "\n\nPress any Key to go back to Main Menu...";
        system("pause>0");
    }

    void LineSeperator(short Length, SeperatorType Type = SeperatorType::thick)
    {
        if (Type == SeperatorType::thick)
            for (short i = 0; i <= Length; i++)
                cout << '=';
        else
            for (short i = 0; i <= Length; i++)
                cout << '-';
    }

    double ReadDouble(string Message)
    {
        double Num;
        cout << Message;
        cin >> Num;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Input, Enter a number? ";
            cin >> Num;
        }
        return Num;
    }

    int ReadInt(string Message)
    {
        int Num;
        cout << Message;
        cin >> Num;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Input, Enter a number? ";
            cin >> Num;
        }
        return Num;
    }

    string ReadAccountNumber()
    {
        string AccountNumber;
        cout << "Please enter Account Number? ";
        getline(cin >> ws, AccountNumber);
        return AccountNumber;
    }

    bool CheckUserLoginIsRight(vector <stUser>& vUser, stUser& User)
    {
        for (stUser& C : vUser)
        {
            if (C.Name == User.Name && C.Password == User.Password)
            {
                User = C;
                return true;
            }
        }
        return false;
    }

    bool checkUserInfoExistance(vector <stUser>& vUser, stUser& User)
    {
        for (stUser& C : vUser)
        {
            if (C.Name == User.Name)
            {
                User = C;
                return true;
            }
        }
        return false;
    }

    bool IsAccountNumberExistInVector(const vector <stClient>& vClientsData, string AccountNumber)
    {
        for (int i = 0; i < vClientsData.size(); i++)
        {
            if (AccountNumber == vClientsData[i].AccountNumber)
                return true;
        }
        return false;
    }

    void HeaderOfSubScreens(string title, SeperatorType Type)
    {
        LineSeperator(40, Type);
        cout << '\n';
        cout << setw(8) << "" << title;
        cout << '\n';
        LineSeperator(40, Type);
    }

    void HeaderOfSubScreens(string title)
    {
        LineSeperator(40, SeperatorType::Thin);
        cout << '\n';
        cout << setw(8) << "" << title;
        cout << '\n';
        LineSeperator(40, SeperatorType::Thin);
    }

    void ManageUsersMenuScreen()
    {
        LineSeperator(40);
        cout << '\n';
        cout << setw(8) << "" << "Manage Users Menu Screen";
        cout << '\n';
        LineSeperator(40);

        cout << "\n\t [1] List Users.\n";
        cout << "\t [2] Add New User.\n";
        cout << "\t [3] Delete User.\n";
        cout << "\t [4] Update User.\n";
        cout << "\t [5] Find User.\n";
        cout << "\t [6] Main Menu.\n";
        LineSeperator(40);
    }

    void SaveClientInfoInVector(vector <stClient>& vClientsData, const stClient& ClientInfo, const string& AccountNumber)
    {
        if (vClientsData.empty())
            return;
        for (int i = 0; i < vClientsData.size(); i++)
            if (vClientsData[i].AccountNumber == AccountNumber)
            {
                vClientsData[i] = ClientInfo;
                return;
            }
    }

    string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";

        stClientRecord += Client.AccountNumber + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += Client.Name + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += to_string(Client.AccountBalance); // When we convert digit to string, it brings with it many zeros

        return stClientRecord;
    }

    void SaveClientsDataToFile(string FileName, const vector <stClient>& vClients)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out); // overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (const stClient& C : vClients)
                if (C.MarkForDelete == false)
                {
                    // we only write records that are not marked for delete
                    DataLine = ConvertRecordToLine(C);
                    MyFile << DataLine << endl;
                }

            MyFile.close();
        }
    }

    stClient ConvertLineToRecord(string Line, string Seperator = "#//#")
    {
        stClient Client;
        vector <string> vClientData;

        vClientData = StringLib::SplitString(Line, Seperator);

        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.Name = vClientData[2];
        Client.Phone = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]);//cast string to
        // double
        return Client;
    }

    vector <stClient> LoadClientsDataFromFile(string FileName)
    {
        vector <stClient> vClients;
        fstream MyFile;
        MyFile.open(FileName, ios::in);//read Mode
        if (MyFile.is_open())
        {
            string Line;
            stClient Client;
            while (getline(MyFile, Line))
            {
                Client = ConvertLineToRecord(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }


}