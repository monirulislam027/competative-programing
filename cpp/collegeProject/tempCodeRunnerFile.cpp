#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// Function to randomly shuffle a vector
template <typename T>
void shuffleVector(vector<T> &v)
{
    random_device rd;
    mt19937 gen(rd());
    shuffle(v.begin(), v.end(), gen);
}

int main()
{
    // Given roles
    vector<int> roles = {534729, 634528, 634533, 634536, 634537, 634538, 634544, 634548, 634549, 634552, 634554, 634555, 634556, 634559, 634565, 634568, 634573, 634576, 634577, 634581, 634604, 634608, 634610, 634612, 634615, 634618, 634620, 635638, 534708, 534732, 534771, 183496};

    // Team leaders
    vector<int> teamLeaders = {534766, 634559, 634553, 634564, 634569, 634595, 634600, 534728};

    // Filter members (excluding team leaders)
    vector<int> members;
    for (int role : roles)
    {
        if (find(teamLeaders.begin(), teamLeaders.end(), role) == teamLeaders.end())
        {
            members.push_back(role);
        }
    }

    // Create teams (vector of vectors)
    vector<vector<int>> teams;

    // Assign team leaders and randomly select members
    for (int leader : teamLeaders)
    {
        vector<int> team = {leader};
        for (int i = 0; i < 4; ++i)
        {
            int randomIndex = rand() % members.size();
            team.push_back(members[randomIndex]);
            members.erase(members.begin() + randomIndex);
        }
        teams.push_back(team);
    }

    // Print the teams
    for (int i = 0; i < teams.size(); ++i)
    {
        cout << "Team " << i + 1 << ": ";
        for (int j = 0; j < teams[i].size(); j++)
        {
            cout << teams[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}