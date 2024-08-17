#include <iostream>
#include <string>
using namespace std;

void addCandidates(string candidates[], int votes[], int &numCandidates) {
    cout << "Enter the number of candidates: ";
    cin >> numCandidates;
    for (int i = 0; i < numCandidates; i++) {
        cout << "Enter candidate " << i + 1 << " name: ";
        cin >> candidates[i];
        votes[i] = 0;
    }
}

void castVote(string candidates[], int votes[], int numCandidates) {
    string chosenCandidate;
    bool validVote = false;
    cout << "Enter the candidate's name you want to vote for: ";
    cin >> chosenCandidate;

    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i] == chosenCandidate) {
            votes[i]++;
            validVote = true;
            break;
        }
    }

    if (!validVote) {
        cout << "Invalid candidate. Try again.\n";
        castVote(candidates, votes, numCandidates);
    }
}

void displayResults(string candidates[], int votes[], int numCandidates) {
    int totalVotes = 0;
    for (int i = 0; i < numCandidates; i++) {
        totalVotes += votes[i];
    }

    for (int i = 0; i < numCandidates; i++) {
        cout << candidates[i] << " received " << (votes[i] * 100.0 / totalVotes) << "% of the votes.\n";
    }
}

int main() {
    const int maxCandidates = 100;
    string candidates[maxCandidates];
    int votes[maxCandidates];
    int numCandidates;
    int numVoters;

    addCandidates(candidates, votes, numCandidates);

    cout << "Enter the number of voters: ";
    cin >> numVoters;

    for (int i = 0; i < numVoters; i++) {
        castVote(candidates, votes, numCandidates);
    }

    displayResults(candidates, votes, numCandidates);

    return 0;
}