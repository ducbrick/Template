#include <bits/stdc++.h>

using namespace std;

const string TASKNAME = "doancon";

typedef long long ll;
typedef pair<int, int> ii;
typedef vector < int > vii;
typedef vector < ii > vpii;
const int iFirst = 1;   
const int iLast = 5;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r){
    return uniform_int_distribution<ll> (l, r) (rng);
}
string intToString(int x)
{
    stringstream ss;
    ss << x;
    string st; ss >> st;
    if (x < 10) st = "0" + st;
    if (x == 0) st = "00";
    return st;
}
void MakeTest(ofstream& cout)
{
    cout << 1000000 << '\n';

    for(auto i = 1; i <= 1000000; i++)
      cout << Rand(0, 1000000) << ' ';
}
int main()
{
    srand(time(NULL));

    system(("mkdir " + TASKNAME).c_str());

    for(int iTest = iFirst; iTest <= iLast; iTest++)
    {
        string testForder = TASKNAME + "\\Test" + intToString(iTest);
        string inputFile = TASKNAME + ".INP";
        string outputFile = TASKNAME + ".OUT";

        system(("mkdir " + testForder).c_str());

        ofstream inp (inputFile.c_str());

        MakeTest(inp);
        inp.close();

        system((TASKNAME + ".exe").c_str());

        system(("move /y " + inputFile + " " + testForder + "/" + inputFile).c_str());
        system(("move /y " + outputFile + " " + testForder + "/" + outputFile).c_str());
    }
}
