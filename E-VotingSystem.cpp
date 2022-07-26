#include <iostream>
#include <fstream>
using namespace std;
const int count = 5;
int main();
pair<string, int> p[count];
class AdminReg
{
public:
  string state, city, password;
  static string id;
  string population;
  void info()
  {
    cout << "\n\t\tWelcome to Admin Page of E-Voting System\n";
    cout << "\tEnter your State name: ";
    cin.ignore();
    getline(cin, state);
    cout << "\n\tEnter your city name: ";
    getline(cin, city);
    cout << "\n\tEnter your city population: ";
    cin >> population;
    cout << "\n\tEnter password as admin: ";
    cin >> password;
    id = state + city + population;
    ofstream admin_file;

    admin_file.open("d:/Projects/E-votingfiles/" + id + "_" + password + ".txt");
    admin_file << state << endl
               << city << endl
               << population << endl
               << id << endl
               << password;
    admin_file.close();
    ofstream admincred;
    admincred.open("d:/Projects/E-votingfiles/" + id + ".txt");
    admincred << id << endl
              << password;
    admincred.close();
    cout << "\tYou have sucessfully registered !!.\n";
    cout << "\tYour credentials are :-\n\t1. Your state :- " << state << "\n\tYour city :- " << city << "\n\t3. Your city's population :- " << population << "\n\t4. Your id :- " << id << "\n\t5. Your password :- " << password << endl;
    cout << "\t\t\t Thank You !!" << endl;
  }
};
class AdminLogin
{
public:
  string password, mypass;
  string id, myid;
  int population;
  void isValid()
  {
    AdminReg ad;
    cout << "\n\t\tWelcome to Login Page of E-Voting System\n";
    cout << "\n\tEnter your id: ";
    cin >> id;
    cout << "\n\tEnter password as admin: ";
    cin >> password;
    ifstream read("d:/Projects/E-votingfiles/" + id + ".txt");
    getline(read, myid);
    getline(read, mypass);
    if (id == myid && password == mypass)
    {
      string state, city;
      string population;
      ifstream read("d:/Projects/E-votingfiles/" + id + "_" + password + ".txt");
      getline(read, state);
      cout << state;
      getline(read, city);
      getline(read, population);
      cout << "\tYour state :- " << state << endl
           << "\tYour city :-" << city << endl
           << "\tYour city's population :-" << population << endl;
      main();
    }
    else
    {
      cout << "\tInvalid id or password . please reEnter." << endl;
      main();
    }
  }
};
class Candidate
{
public:
  string candidatename, partysymbol;
  AdminReg ad;
  string id, myid, password, mypass;
  bool isLogged()
  {

    cout << "\n\t\tWelcome to  Candidate Registration Page \n";
    cout << "\n\tEnter your id: ";
    cin >> id;
    cout << "\n\tEnter password as admin: ";
    cin >> password;
    ifstream read("d:/Projects/E-votingfiles/" + id + ".txt");
    getline(read, myid);
    getline(read, mypass);
    if (id == myid && password == mypass)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  void candidateregister(int count)
  {

    cin.ignore();
    ofstream party;
    party.open("d:/Projects/E-votingfiles/party/partysymbol.txt");

    for (int i = 0; i < count; i++)
    {

      cout << "\n\tEnter name of candidae: ";
      getline(cin, candidatename);
      cout << "\n\tEnter your party name: ";
      getline(cin, partysymbol);
      p[i].first = partysymbol;
      p[i].second = 0;
      ofstream candidatefile;
      candidatefile.open("d:/Projects/E-votingfiles/candidatefile/" + candidatename + "_" + partysymbol + ".txt");
      candidatefile << candidatename << endl
                    << partysymbol;
      candidatefile.close();
      party << partysymbol << endl;
    }
    party.close();
    main();
  }
};
class Voter
{
public:
  void vote()
  {

    ifstream read("d:/Projects/E-votingfiles/party/partysymbol.txt");
    string t;

    cout << "Party Symbols: choose one for vote :-\n";
    int i = 0;
    while (getline(read, t))
    {
      cout << "\t" << t << endl;
    }
    read.close();
    int j = 1;
    bool out = true;
    do
    {
      cout << "\tenter your choice - voter" << j << ":- ";
      string choice;
      cin >> choice;
      for (int i = 0; i < count; i++)
        if (p[i].first == choice)
          p[i].second += 1;
      cout << "\tNo voter rest ? yes/no";
      string val;
      cin >> val;
      if (val == "no")
        out = false;
      j++;
    } while (out);
    for (int i = 0; i < count; i++)
      cout << p[i].first << " " << p[i].second << endl;
    int max = 0, winner = -1;
    for (int i = 0; i < count; i++)
      if (p[i].second > max)
        winner = i;
    cout << "\t\tWinner is : " << p[winner].first << endl;
  }
};
string AdminReg::id = "";
int main()
{
  system("color A");
  cout << "\n\tWelcome to E-Voting System owned by Government of INDIA:" << endl;
  cout << "\t__________________________________________________________\n";
  cout << "\n\t\t1. Admin's Registration\n\t\t2. Admin's Login\n\t\t3. Candidate's Registration\n\t\t4. Voter's Login\n";
  cout << "\n\tEnter your choice : ";
  int choice;
  cin >> choice;
  if (choice == 1)
  {
    AdminReg ad;
    ad.info();
    main();
  }
  else if (choice == 2)
  {
    AdminLogin al;
    al.isValid();
  }
  else if (choice == 3)
  {
    Candidate cd;
    bool check = cd.isLogged();
    if (check)
    {
      cd.candidateregister(count);
    }

    else
    {
      cout << "\tInvalid id or password . please reEnter." << endl;
      main();
    }
  }
  else if (choice == 4)
  {
    // cout<<"hii";
    Voter v;
    v.vote();
    main();
  }
  else
  {
    cout << "\n\tInvalid option, please resubmit your choice." << endl;
    cout<<"Thank for the vote !! See you next year....";
  }
}
