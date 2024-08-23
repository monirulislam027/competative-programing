#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to shuffle a vector randomly
void shuffleVector(vector<int> &v)
{
    srand(time(0));
    random_shuffle(v.begin(), v.end());
}

int main()
{
    // Given roles
    vector<int> roles = {534729, 634528, 634533, 634536, 634537, 634538, 634544, 634548, 634549, 634552, 634554, 634555, 634556, 634559, 634565, 634568, 634573, 634576, 634577, 634581, 634604, 634608, 634610, 634612, 634615, 634618, 634620, 635638, 534708, 534732, 534771, 183496};

    // Team leader roles
    vector<int> teamLeaders = {534766, 634559, 634553, 634564, 634569, 634595, 634600, 534728};

    // Remove team leaders from the roles list
    vector<int> members;
    for (int role : roles)
    {
        if (find(teamLeaders.begin(), teamLeaders.end(), role) == teamLeaders.end())
        {
            members.push_back(role);
        }
    }

    // Create teams
    const int teamSize = 5;
    const int numTeams = teamLeaders.size();

    vector<vector<int>> teams(numTeams, vector<int>(teamSize));

    // Shuffle members randomly
    shuffleVector(members);

    // Assign members to teams
    int memberIndex = 0;
    for (int i = 0; i < numTeams; ++i)
    {
        for (int j = 0; j < teamSize && memberIndex < members.size(); ++j)
        {
            teams[i][j] = members[memberIndex++];
        }
    }

    // Print the teams
    for (int i = 0; i < numTeams; ++i)
    {
        cout << "Team " << i + 1 << ": ";
        for (int j = 0; j < teamSize; ++j)
        {
            cout << teams[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}