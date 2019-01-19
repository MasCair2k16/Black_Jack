#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <random>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int deckSize =52;     // This will keep the order of how many cards there are in a deck.

struct playingCardvalue // When a card is being shuffled or anything like it. There has to be structs.
{
    int value;
    string face;
    string suit;
};

vector<playingCardvalue> createDeck(vector <playingCardvalue>, int deckAmount);

int main()
{
    int Player1Total = 0;       // All of these start at 0 becuase a players will not have have a card until the game starts.
    int Player2Total = 0;
    int players = 0;
    int deckInfo =0;
    int DealersTotal = 0;
    bool player1 = false;   // In the beginning, the user will determine how many players will be playing with. For now its false becuase no one is playng.
    bool player2 = false;
    int TotalNumCards;      // This will be the total number of cards the black Jack game will have
    int option;             // The option if the want to stay or hit.
    string playAgain;
    string player1Name;     // Players Name
    string player2Name;     // Players Name
    
    
    cout << "Would you like (1 or 2) players for the game?" << endl;
    cin >> players;
    
    if ( players == 1)
    {
        cout << "Please enter your name: ";
        cin >> player1Name;
    }
    else
    {
        cout << "Please enter first players name: ";
        cin >> player1Name;                         // Players 1 name
        
        cout << "Please enter second players name: ";
        cin >> player2Name;                         // Players 2 name
    }
    
    cout <<"How many decks would you like for this game?" << endl;
    cin >> TotalNumCards;
    
    int totalCards = TotalNumCards * deckSize;      // This will save the amount of cards  generated.
    
    vector<playingCardvalue> deck(totalCards); // This will generate the vector of decls for the user.
    
    deck = createDeck(deck, TotalNumCards); // Function call that uses the deck vector and the amount of decks. it reutrns a shuffled deck.
     
    
    //srand(time(0)); // This will create numbers without being able to repeat.
    
    
    if (players == 1)
    {
        player1 = true;       // Player 1 is chosen for the first deal
        player2 = false;      // Player 2 is skipped for now until next.
        
        
        cout << player1Name << ", you are dealt with ";
        if (deck[deckInfo].face != "Number")      // This will give the 1 player the first card of the game.
        {
            cout << deck[deckInfo].face;      // if the card is a face, it will show the face card. Unless its only a number card.
        }
        else
        {
            cout << deck[deckInfo].value;
        }
        
        
        cout << " " << deck[deckInfo].suit << endl << endl;
        
        Player1Total = deck[deckInfo].value;        // Player1Total will hold the value of cards the player will have.
        
        deckInfo++;         // Here
        
        cout << "The dealer is dealt with ";             // In here, the dealer is starting to be dealt after the players.
        if (deck[deckInfo].face != "Number")
        {
            cout << deck[deckInfo].face;
        }
        else
        {
            cout << deck[deckInfo].value;
        }
        cout << "  " << deck[deckInfo].suit << endl << endl;
        DealersTotal = deck[deckInfo].value;                // This will keep the dealers total so we could add them up later in the game.
        deckInfo++;       // Creats and implints a deck.
        
        cout << player1Name << ", you are dealt with ";
        if (deck[deckInfo].face != "Number")
        {
            cout << deck[deckInfo].face;
        }
        else
        {
            cout << deck[deckInfo].value;
        }
        
        cout << " " << deck[deckInfo].suit << endl << endl;
        Player1Total = Player1Total + deck[deckInfo].value;
        cout <<  player1Name << ", your total is " << Player1Total << endl << endl;  // This WIll show the players 1 total.
        
        deckInfo++;
        
        
        cout << "The Dealer is dealt with ";     // The dealer deals his or her own card.
        if (deck[deckInfo].face != "Number")
        {
            cout << deck[deckInfo].face;
        }
        else
        {
            cout << deck[deckInfo].value;
        }
        cout << " " << deck[deckInfo].suit << endl;
        DealersTotal = DealersTotal + deck[deckInfo].value;
        cout << "The Dealer's total is " << DealersTotal << endl << endl;     // This shows the dealers total
        deckInfo++;
        
    }
    
    if (players == 2)
    {
        player1 = true;
        player2 = true;        // This allows 2 players.
        
        cout << player1Name << ", you are dealt with ";
        if (deck[deckInfo].face != "Number")
        {
            cout << deck[deckInfo].face;
        }
        else
        {
            cout << deck[deckInfo].value;
        }
        
        cout << " " << deck[deckInfo].suit << endl << endl;
        
        Player1Total = deck[deckInfo].value;
        deckInfo++;
        
        
        cout <<  player2Name << ", you are dealt with ";
        if (deck[deckInfo].face != "Number")
        {
            cout << deck[deckInfo].face;
        }
        else
        {
            cout << deck[deckInfo].value;
        }
        
        cout << " " << deck[deckInfo].suit << endl << endl;
        
        Player2Total = deck[deckInfo].value;
        
        deckInfo++;
        
        cout << "The Dealer is dealt with ";
        if (deck[deckInfo].face != "Number")
        {
            cout << deck[deckInfo].face;
        }
        else
        {
            cout << deck[deckInfo].value;
        }
        cout << " " << deck[deckInfo].suit << endl << endl;
        DealersTotal = deck[deckInfo].value;
        deckInfo++;
        
        
        cout << player1Name << ", you are dealt with ";
        if (deck[deckInfo].face != "Number")
        {
            cout << deck[deckInfo].face;
        }
        else
        {
            cout << deck[deckInfo].value;
        }
        cout << " " << deck[deckInfo].suit << endl << endl;
        Player1Total = Player1Total + deck[deckInfo].value;
        cout << player1Name << ", your total is " << Player1Total << endl << endl;
        
        deckInfo++;
        
        cout << player2Name << ", you are dealt with ";
        if (deck[deckInfo].face != "Number")
        {
            cout << deck[deckInfo].face;
        }
        else
        {
            cout << deck[deckInfo].value;
        }
        cout << " " << deck[deckInfo].suit << endl;
        Player2Total = Player2Total + deck[deckInfo].value;
        cout << player2Name << ", you total is " << Player2Total << endl << endl;
        deckInfo++;
        
        cout << "The Dealer is dealt with ";
        if (deck[deckInfo].face != "Number")
        {
            cout << deck[deckInfo].face;
        }
        else
        {
            cout << deck[deckInfo].value;
        }
        cout << " " << deck[deckInfo].suit << endl;
        DealersTotal = DealersTotal + deck[deckInfo].value;
        cout << "Dealer's total is " << DealersTotal << endl << endl;
    }
    
	while (player1 == true)
	{
		cout << player1Name << ", would you like to hit (1) or stay (2): ";     //Here the player will be given the opportunity to choose if they want to stay or hit.
		(cin >> option).get();

		if (option == 1)        // If they hit, they are given another card.
		{
			cout << player1Name << ", you are dealt with ";      // The player will get another playing card.

			if (deck[deckInfo].face != "Number")
			{
				cout << deck[deckInfo].face;
			}
			else
			{
				cout << deck[deckInfo].value;
			}

			cout << " " << deck[deckInfo].suit << endl;
			Player1Total = Player1Total + deck[deckInfo].value;
			cout << player1Name << ", your total is " << Player1Total << endl << endl;
			deckInfo++;

			if (Player1Total > 21)
			{
				cout << "You busted" << endl << endl;
				player1 = false;

			}
		}
		else if (option == 2)       // If they dont hit, they will stand with what they have.
		{
			cout << player1Name << ", you stand with a total of " << Player1Total << endl << endl;
			player1 = false;
		}
	}
		
	// Players 2's Turn
	while (player2 == true)
	{
        cout << player2Name << ", would like you to hit(1) or stay(2).";
        cin >> option;
                
		if (option == 1)
		{
			cout << player2Name << ", you are dealt with ";

			if (deck[deckInfo].face != "Number")
			{
				cout << deck[deckInfo].face;
			}
			else
			{
				cout << deck[deckInfo].value;
			}

			cout << " " << deck[deckInfo].suit << endl;
			Player2Total = Player2Total + deck[deckInfo].value;
			cout << " Players 2's total " << Player2Total << endl << endl;
			deckInfo++;

			if (Player2Total > 21)
			{
				cout << "You busted" << endl << endl;
				player2 = false;

			}
		}      
        else if (option == 2)
        {
            cout << player2Name << ", you stand with a total of " << Player2Total << endl << endl;
			player2 = false;
        }
	}
                
	// Dealers Turn
    while (DealersTotal < 17)
    {
        cout << "Dealer is dealt ";
        if (deck[deckInfo].face != "Number")
        {
            cout << deck[deckInfo].face;
        }
                    
        else
        {
            cout << deck[deckInfo].value;
        }
        cout << " " << deck[deckInfo].suit << endl;
        DealersTotal = DealersTotal + deck[deckInfo].value;
        cout << " Dealers total is about " << DealersTotal << endl << endl;
                    
        deckInfo++;
    }
                
    if (DealersTotal > 21)
    {
        cout << "Dealer Busted" << endl << endl;
    }
    else
    {
        cout << "Dealer stands with a total of " << DealersTotal << endl << endl;
    }
                
                // Select Winners
                if (Player2Total == 0)
                {
                    if (DealersTotal > 21 && Player1Total <= 21)
                    {
                        cout << player1Name << ", you won!!!!" << endl << endl;
                    }
                    
                    else if (Player1Total <= 21 && Player1Total > DealersTotal)
                    {
                        cout << player1Name << " you won!" << endl << endl;
                    }
                    
                    else
                    {
                        cout << player1Name << ", you lost!" << endl << endl;
                    }
                    
                    
                }
                
                else
                {
                    if ((DealersTotal > 21 && Player1Total <= 21 && Player2Total <= 21) || (Player1Total <= 21 && Player1Total > DealersTotal && Player2Total <= 21 && Player2Total > DealersTotal))
                    {
                        cout << player1Name << ", you won!!!" << endl << endl;
                        cout << player2Name << ", you won!!!" << endl << endl;
                        
                        return 0;
                    }
                    
                    else if (Player1Total <= 21 && Player1Total > DealersTotal && Player2Total <= 21 && Player2Total < DealersTotal)
                    {
                        cout << player1Name << "you Won!!!" << endl << endl;
                        cout << player2Name << "you Lost!!!" << endl << endl;
                        
                        return 0;
                    }
                    
                    else if (Player1Total <= 21 && Player1Total < DealersTotal && Player2Total <= 21 && Player2Total > DealersTotal)
                    {
                        cout << player1Name << ", you lost!!!" << endl << endl;
                        cout << player2Name << ", you won!!!"<< endl << endl;
                        
                        return 0;
                    }
                    
                    else
                    {
                        cout << player1Name << ", you lost!!!" << endl << endl;
                        cout << player2Name << ", you lost!!!" << endl << endl;
                        
                        return 0;
                    }
                    
                }
               return 0; 
            }

vector<playingCardvalue> createDeck(vector<playingCardvalue> deck, int deckAmount) // Create new Deck
{
    // Creates a seed based off of the system clocl used in the shuffle function
    
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    
    int cardID = 0;  // Card Iterator
    
    for (int x= 0; x< deckAmount; ++x)     // Loops as may times as there are decks
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 1; j<= 13; ++j)
            {
                switch (i) //Assign a suit to all the cards
                {
                    case 0: deck[cardID].suit = "of Hearts";
                        break;
                    case 1: deck[cardID].suit = "of Diamonds";
                        break;
                    case 2: deck[cardID].suit = "of Spades";
                        break;
                    case 3: deck[cardID].suit = "of Clubs";
                }
                
                switch (j) // Assign face and value to cards
                {
                    case 11:    deck[cardID].face = "Jack";
                        deck[cardID].value = 10;
                        break;
                    case 12:    deck[cardID].face = "Queen";
                        deck[cardID].value = 10;
                        break;
                    case 13:    deck[cardID].face = "King";
                        deck[cardID].value = 10;
                        break;
                    default:    deck[cardID].face = "Number";
                        deck[cardID].value = j;
                }
                
                cardID++; // iterate through all the cards
            }
        }
    }
    shuffle(deck.begin(), deck.end(), default_random_engine(seed));
    return deck;
}
