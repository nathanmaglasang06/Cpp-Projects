#include <iostream>
#include <string>
using namespace std;

int main() {
//Int Decleration
int YourAge;
int VotingAge = 18;
int TimeToVote;

//User Input
cout << "Voting Age Calculator \n\n";
cout << "What is your age?  ";
cin >> YourAge;

//Voting Calculations
if (YourAge >= VotingAge) {
    cout << "You are " << YourAge << " so you can vote";
} else {
    TimeToVote = VotingAge - YourAge;
    cout << "As you are only " << YourAge << " you still need to wait " << TimeToVote << " years before you can vote";
}

}
