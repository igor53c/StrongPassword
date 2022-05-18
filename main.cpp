#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int minimumNumber(int n, string password)
{
    string numbers = "0123456789";
    string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string specialCharacters = "!@#$%^&*()-+";

    bool haveNumbers = false;
    bool haveLowerCase = false;
    bool haveUpperCase = false;
    bool haveSpecialCharacters = false;

    int twoChar = 2;

    int retValue = 6;

    for(int i = 0; i < n; i++)
    {
        if(!haveNumbers && numbers.find(password[i]) != string::npos)
        {
            haveNumbers = true;
            retValue--;
        }
        else if(!haveLowerCase && lowerCase.find(password[i]) != string::npos)
        {
            haveLowerCase = true;
            retValue--;
        }
        else if(!haveUpperCase && upperCase.find(password[i]) != string::npos)
        {
            haveUpperCase = true;
            retValue--;
        }
        else if(!haveSpecialCharacters && specialCharacters.find(password[i]) != string::npos)
        {
            haveSpecialCharacters = true;
            retValue--;
        }
        else if(twoChar > 0)
        {
            twoChar--;
            retValue--;
        }

        if(retValue == 0)
            break;
    }

    return retValue;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
            );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
        );

    return s;
}
