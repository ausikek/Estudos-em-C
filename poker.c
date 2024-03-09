#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND 5


void shuffle(unsigned int wDeck[][FACES]);


void deal(unsigned int wDeck[][FACES], 
		const char *wFace[],
		const char *wSuit[],
		int handFace[HAND],
		int handSuit[HAND],
		int isPlayer);


int checkHand(const int whandFace[], const int whandSuit[]);


int playerHand(unsigned int wDeck[][FACES],
 				const char *wFaces[],
  				const char *wSuits[]);


int dealerHand(unsigned int wDeck[][FACES],
				const char *wFaces[],
				const char *wSuits[]);


void winner(int num1, int num2);


int main(void) {

	unsigned int deck[SUITS][FACES] = {0};

	unsigned int card = 1;

	for (size_t row = 0; row <= 3; row++) {

		for (size_t column = 0; column <= 12; column++) {

			deck[row][column] = card;

			card++; 
		}
	}

	srand(time(NULL));

	const char *suit[SUITS] =
		
		{"Hearts", "Diamonds", "Clubs", "Spades"};
	
	const char *face[FACES] = 
		
		{"Ace", "Deuce", "Three", "Four",
		 "Five", "Six", "Seven", "Eight", 
		 "Nine", "Ten", "Jack", "Queen", "King"};


	shuffle(deck);
	
	puts("Your Hand\n");

	int x = playerHand(deck, face, suit);

	puts("\n");

	puts("Dealer Hand\n");

	int y = dealerHand(deck, face, suit);

	winner(x,y);
	
	return 0;
}


void shuffle(unsigned int wDeck[][FACES]) {

	for (size_t row = 0; row <= 3; row++) {

		for (size_t column = 0; column <= 12; column++) {

			unsigned int rand_row = rand() % SUITS;
			unsigned int rand_column = rand() % FACES;

			int hold = wDeck[rand_row][rand_column];
			wDeck[rand_row][rand_column] = wDeck[row][column];
			wDeck[row][column] = hold;

		}
	}
}


void deal(unsigned int wDeck[][FACES],
		const char *wFace[],
		const char *wSuit[],
		int handFace[],
		int handSuit[],
		int isPlayer) {

	
	static size_t card = 1;
	static size_t final_card = 5;
	static size_t decrement = 1;
	static int format = 1;

	if (isPlayer == 1) {

		for (card; card <= final_card; card++) {

			for (size_t row = 0; row < SUITS; row++) {

				int isFound = 0;

				if (isFound == 1) {

					break;

				}

				for (size_t column = 0; column < FACES; column++) {

					if (wDeck[row][column] == card) {

						handFace[card - decrement] = column;
						handSuit[card - decrement] = row;

						printf("%5s of %-8s%c", wFace[column], wSuit[row],
							format % 2 == 0 ? '\n' : '\t');
					
						format++;

						isFound = 1;

						break;

					}
				}
			}
		}
	
	puts("\n");
	format++;

	} else {

		for (card; card <= final_card; card++) {

			for (size_t row = 0; row < SUITS; row++) {

				for (size_t column = 0; column < FACES; column++) {

					if (wDeck[row][column] == card) {

						handFace[card - decrement] = column;
						handSuit[card - decrement] = row;
					
						format++;

					}
				}
			}
		}
	}

	final_card += 5;
	decrement += 5;

}

int checkHand(const int whandFace[], const int whandSuit[]) {


	int checkHighest(int CardFaces[]);
	int checkSolo(int *sentinel);
	int checkPair(int CardFaces[], int *sentinel);
	int checkTwoPair(int CardFaces[], int *sentinel);
	int checkThree(int CardFaces[], int *sentinel);
	int checkStraight(int CardFaces[], int *sentinel);
	int checkFlush(int CardSuit[], int *sentinel);
	int checkFour(int CardFaces[], int *sentinel);


	int Faces[FACES] = {0};
	int Suits[SUITS] = {0};
	int handClassification = 0;
	int sentinel = 0;


	for (size_t i = 0; i < HAND; i++) {
		
		Faces[whandFace[i]]++;
		Suits[whandSuit[i]]++;
	
	}

	int highestCard = checkHighest(Faces);

	while (sentinel == 0) {

		handClassification = checkFour(Faces, &sentinel);
		    if (sentinel != 0) break;

		handClassification = checkFlush(Suits, &sentinel);
		    if (sentinel != 0) break;

		handClassification = checkStraight(Faces, &sentinel);
		    if (sentinel != 0) break;

		handClassification = checkThree(Faces, &sentinel);
		    if (sentinel != 0) break;

		handClassification = checkTwoPair(Faces, &sentinel);
		    if (sentinel != 0) break;

		handClassification = checkPair(Faces, &sentinel);
		    if (sentinel != 0) break;
		
		handClassification = checkSolo(&sentinel);

	}
		
		int handData[2] = {handClassification, highestCard};

		return handClassification;

}


int checkHighest(int CardFaces[]) {

	int highest = 0;

	if (CardFaces[0] > 0) {

		return highest;

	} else {

		for (size_t i = 1; i < FACES; i++) {

			if (CardFaces[i] > 0) {

				highest = i;

			}
		}

		return highest;

	}
}


int checkSolo(int *sentinel) {

	if (*sentinel == 0) {

		*sentinel = -1;

		return 0;
	
	}

}


int checkPair(int CardFaces[], int *sentinel) {

	int isPair = 0;

	if (*sentinel != -1) {

		for (size_t i = 0; i < FACES; i++) {

			if (CardFaces[i] == 2) {

				isPair++;

			} 
		}

		if (isPair == 1) {

			*sentinel = -1;

			return 1;

		} 
	}
}


int checkTwoPair(int CardFaces[], int *sentinel) {

	if (*sentinel != -1) {

		int twoPair = 0;

		for (size_t i = 0; i < FACES; i++) {

			if (CardFaces[i] == 2) {

				twoPair++;

			}
		}
	
		if (twoPair == 2) {

			*sentinel = -1;

			return 2;

		}
	}
}


int checkThree(int CardFaces[], int *sentinel) {

	if (*sentinel != -1) {

		for (size_t i = 0; i < FACES; i++) {

			if (CardFaces[i] == 3) {

				*sentinel = -1;

				return 3;

			}
		}
	}
}


int checkStraight(int CardFaces[], int *sentinel) {

	if (*sentinel != -1) {

		for (size_t j = 0; j < FACES - 4; j++) {
		
			if (CardFaces[j] == 1 && CardFaces[j+1] == 1 && CardFaces[j+2] == 1 && CardFaces[j+3] && CardFaces[j+4] == 1) {
							
				*sentinel = -1;
				
				return 4;
		
			} 
		}
	
		if (CardFaces[0] == 1 && CardFaces[9] == 1 && CardFaces[10] == 1 && CardFaces[11] == 1 && CardFaces[12] == 1) {

				printf("Broadway Straight");
				
				*sentinel = -1;
				
				return 4;
	
		}
	}
}


int checkFlush(int CardSuit[], int *sentinel) {

	if (*sentinel != -1) {

		for (size_t k = 0; k < SUITS; k++) {
		
			if (CardSuit[k] == 5) {
				
				*sentinel = -1;
		
				return 5;

			}
		}
	}
}


int checkFour(int CardFaces[], int *sentinel) {

	if (*sentinel != -1) {

		for (size_t i = 0; i < FACES; i++) {

			if (CardFaces[i] == 4) {

				*sentinel = -1;

				return 6;

			}
		}
	}
}


void winner(int num1, int num2) {

	if (num1 > num2) {
		
		puts("\n");
		printf("Player wins.");

	} else if (num1 < num2) {

		puts("\n");
		printf("Dealer wins.");

	} else {

		puts("\n");
		printf("Draw.");

	}
}


int playerHand(unsigned int wDeck[][FACES],
 				const char *wFaces[],
  				const char *wSuits[]) {


	void changeCardsPlayer(unsigned int wDeck[][FACES],
 				int handFace[], 
				int handSuit[],
				const char *wFaces[],
  				const char *wSuits[],
				int *handClass);

	
	int handFace[HAND] = {0};
	int handSuit[HAND] = {0};

	deal(wDeck, wFaces, wSuits, handFace, handSuit, 1);

	int handClass = checkHand(handFace, handSuit);

	changeCardsPlayer(wDeck, handFace, handSuit, wFaces, wSuits, &handClass);

	return handClass;


}

int dealerHand(unsigned int wDeck[][FACES],
		const char *wFaces[],
		const char *wSuits[]) {


	void changeCardsDealer(unsigned int wDeck[][FACES],
					int handFace[], 
					int handSuit[],
					const char *wFaces[],
					const char *wSuits[],
					int *handClass);


	int handFace[HAND] = {0};
	int handSuit[HAND] = {0};

	deal(wDeck, wFaces, wSuits, handFace, handSuit, 0);

	int handClass = checkHand(handFace, handSuit);

	changeCardsDealer(wDeck, handFace, handSuit, wFaces, wSuits, &handClass);

	return handClass;


}


void draw(unsigned int wDeck[][FACES],
		  int drawedFace[],
		  int drawedSuit[]) {

	
	static size_t card = 11;
	
	for (size_t row = 0; row < SUITS; row++) {

		for (size_t column = 0; column < FACES; column++) {

			if (wDeck[row][column] == card) {

				drawedFace[0] = column;
				drawedSuit[0] = row;

			}
		}
	}

	card++;

}


void swap(int testFace[], int testSuit[], int drawedFace[], int drawedSuit[], int idx) {

	testFace[idx] = drawedFace[0];
	testSuit[idx] = drawedSuit[0]; 

}


void printHand( int handFace[], 
				int handSuit[],
				const char *wFace[],
				const char *wSuit[]) {

	puts("\n");

	for (size_t card = 0; card < HAND; card++) {

		printf("%5s of %-8s%c", wFace[handFace[card]], wSuit[handSuit[card]],
		 		(card + 1) % 2 == 0 ? '\n' : '\t');
	
	}
}


void changeCardsDealer(unsigned int wDeck[][FACES],
 				int handFace[], 
				int handSuit[],
				const char *wFaces[],
  				const char *wSuits[],
				int *handClass) {


	int drawedFace[1] = {0};
	int drawedSuit[1] = {0};

	int testFace[HAND] = {0};
	int testSuit[HAND] = {0};

	int swapHandClass = *handClass;
	int tempHandClass = 0;


	for (size_t card = 0; card < HAND; card++) {

		testFace[card] = handFace[card];
		testSuit[card] = handSuit[card];

	}

		int sentinel = 0;

	for (size_t pass = 1; pass <= 3; pass++) {

		if (swapHandClass == 0) {

			draw(wDeck, drawedFace, drawedSuit);

			for (size_t i = 0; i < HAND; i++) {

				swap(testFace, testSuit, drawedFace, drawedSuit, i);
				
				tempHandClass = checkHand(testFace, testSuit);


				if (tempHandClass > swapHandClass) {
					swapHandClass = tempHandClass;

					*handClass = swapHandClass;

					sentinel = -1;

					break;

				}  else {

					for (size_t card = 0; card < HAND; card++) {

						testFace[card] = handFace[card];
						testSuit[card] = handSuit[card];

					}
				}
			}
		
		} else if (swapHandClass > 0 && sentinel != -1) {

			draw(wDeck, drawedFace, drawedSuit);

			for (size_t i = 0; i < HAND; i++) {

				swap(testFace, testSuit, drawedFace, drawedSuit, i);

				tempHandClass = checkHand(testFace, testSuit);

				if (tempHandClass > swapHandClass) {

					swapHandClass = tempHandClass;

					*handClass = swapHandClass;

					sentinel = -1;

					break;

				} else {

					for (size_t card = 0; card < HAND; card++) {

						testFace[card] = handFace[card];
						testSuit[card] = handSuit[card];

					}
				}
			}
		} 
	}
		
		printHand(testFace, testSuit, wFaces, wSuits);

}

void changeCardsPlayer(unsigned int wDeck[][FACES],
 				int handFace[], 
				int handSuit[],
				const char *wFaces[],
  				const char *wSuits[],
				int *handClass) {

	
	int drawedFace[1] = {0};
	int drawedSuit[1] = {0};


	for (size_t pass = 1; pass <= 3; pass++) {

		draw(wDeck, drawedFace, drawedSuit);

		int choice = 0;

		printf("\n You drew a %s of %s. Press 1 - 5 to swap for a card in your hand or 0 to discard it.\n",
		 		wFaces[drawedFace[0]],
				wSuits[drawedSuit[0]]);

		scanf("%d", &choice);

		if (choice == 0) {

			continue;

		} else {

			swap(handFace, handSuit, drawedFace, drawedSuit, choice - 1);

			*handClass = checkHand(handFace, handSuit);

		}

		printHand(handFace, handSuit, wFaces, wSuits);

	}
}
