#include <bits/stdc++.h>
using namespace std;

void print(int nam, vector<int> rolls)
{

    cout << "Team " << nam << endl
         << "=========================" << endl;
    sort(rolls.begin() + 1, rolls.end());
    for (int i = 0; i < rolls.size(); i++)
    {
        cout << rolls[i];
        if (i == 0)
            cout << " => Team Leader";
        cout << endl;
    }
    cout << endl
         << endl;
}

template <typename T>
void shuffleVector(vector<T> &v)
{
    random_device rd;
    mt19937 gen(rd());
    shuffle(v.begin(), v.end(), gen);
}

int main()
{
    cout << endl
         << "Web Development Project (28566)" << endl
         << endl;
    vector<int> rolls = {534729, 634528, 634533, 634536, 634537, 634538, 634544, 634548, 634549, 634552, 634554, 634555, 634556, 634559, 634565, 634568, 634573, 634576, 634577, 634581, 634604, 634608, 634610, 634612, 634615, 634618, 634620, 635638, 534708, 534732, 534771, 183496};

    vector<int> alpha = {534766}; // Jarir
    vector<int> beta = {634559};  // Masud
    vector<int> delta = {634553}; // Arman
    vector<int> eta = {634564};   // Sohan
    vector<int> gama = {634569};  // Monirul
    vector<int> iota = {634595};  // Sami
    vector<int> omega = {634600}; // Nur Alam
    vector<int> theta = {534728}; // Riad

    // team for girls
    vector<int> zeta = {634562, 634543, 634545, 634557, 634572, 634594, 634598, 634619};

    vector<vector<int>> teams = {alpha, beta, delta, eta, gama, iota, omega, theta};

    for (int i = 0; i < teams.size(); i++)
    {

        for (int j = 0; j < 4; j++)
        {
            teams[i].push_back(rolls[0]);
            rolls.erase(rolls.begin());
        }
    }

    for (int i = 0; i < teams.size(); i++)
    {
        print(i + 1, teams[i]);
    }

    return 0;
}