// #include "doctest.h"
// #include "player.hpp"
// #include "game.hpp"
// #include "card.hpp"
// using namespace ariel;

// /**
//  * @brief 
//  * Test List:
//     1.	Test that the deck has exactly 52 cards at the beginning of the game.
//     2.	Test that the deck is shuffled randomly before distributing the cards.
//     3.	Test that the cards are divided equally between the two players at the beginning of the game.
//     4.	Test that a player draws only one card from their pile each turn.
//     5.	Test that the player with the highest card wins the turn and takes both cards.
//     6.	Test that two identical cards are placed face down and a lesser card on top of it.
//     7.	Test that the high card player takes all six cards in case of a tie.
//     8.	Test that the game continues with a closed card followed by an open card until one of the players wins.
//     9.	Test that the player with the most cards at the end of the game is declared the winner.
//     10.	Test that the game ends when one of the players runs out of cards.
//     11.	Test that each player takes the cards they threw if they run out of cards while breaking a tie.
//     12.	Test that the pot is divided half and half in case of a tie.
//     13.	Test that the game can handle multiple draws in a row.
//     14.	Test that the game can handle a draw within a draw.
//     15.	Test that the game can handle multiple ties in a row.
//     16.	Test that the game can handle the situation where one player runs out of cards and the other still has cards.
//     17.	Test that the game can handle the situation where both players run out of cards at the same time.
//     18.	Test that the game can handle the situation where a player has more than half of the total cards but the game is not yet over.
//     19.	Test that the game can handle the situation where a player has exactly half of the total cards but the game is not yet over.
//     20.	Test that the game can handle the situation where there are no more cards left to draw but the game is not yet over.
//  * @author Batel Cohen Yerushalmi
//  */

// //1
// TEST_CASE("deck has exactly 52 cards at the beginning of the game") {
//     Game game(Player("Alice"), Player("Bob"));
//     CHECK(game.getCardsLeft() == 52);
// }

// //2
// TEST_CASE("deck is shuffled randomly before distributing the cards") {
//     Game game(Player("Alice"), Player("Bob"));
//     Card first_card = game.drawCard();
//     game.resetDeck();
//     Card second_card = game.drawCard();
//     CHECK_FALSE(first_card == second_card);
// }

// //3
// TEST_CASE("cards are divided equally between the two players at the beginning of the game") {
//     Game game(Player("Alice"), Player("Bob"));
//     CHECK(game.getPlayer1().getStackSize() == game.getPlayer2().getStackSize());
// }

// //4
// TEST_CASE("a player draws only one card from their pile each turn") {
//     Game game(Player("Alice"), Player("Bob"));
//     Player p1 = game.getPlayer1();
//     game.playTurn();
//     CHECK(p1.getStackSize() == game.getPlayer1().getStackSize() + 1);
// }

// //5
// TEST_CASE("the player with the highest card wins the turn and takes both cards") {
//     Game game(Player("Alice"), Player("Bob"));
//     Card high_card(ACE, HEARTS);
//     Card low_card(TWO, HEARTS);
//     game.getPlayer1().addCard(high_card);
//     game.getPlayer2().addCard(low_card);
//     game.playTurn();
//     CHECK(game.getPlayer1().getCardesTaken() == 2);
// }

// //6
// TEST_CASE("card distribution") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1, p2);

//     CHECK(p1.stacksize() == 26);
//     CHECK(p2.stacksize() == 26);
// }

// //7
// TEST_CASE("draw one card per turn") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1, p2);

//     game.playTurn();
//     CHECK(p1.stacksize() == 25);
//     CHECK(p2.stacksize() == 27);

//     game.playTurn();
//     CHECK(p1.stacksize() == 24);
//     CHECK(p2.stacksize() == 26);
// }

// //8
// TEST_CASE("highest card wins") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1, p2);

//     Card c1(SPADES, ACE);
//     Card c2(DIAMONDS, KING);
//     p1.addCardToStack(c1);
//     p2.addCardToStack(c2);

//     game.playTurn();
//     CHECK(game.getLastTurnWinner() == &p1);
//     CHECK(p1.cardesTaken() == 2);
// }

// //9
// TEST_CASE("face down cards in case of identical cards") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1, p2);

//     Card c1(SPADES, ACE);
//     Card c2(DIAMONDS, ACE);
//     p1.addCardToStack(c1);
//     p2.addCardToStack(c2);

//     game.playTurn();
//     CHECK(game.getLastTurnWinner() == &p2);
//     CHECK(p2.cardesTaken() == 2);
// }

// //10
// TEST_CASE("take all six cards in case of tie") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1, p2);

//     Card c1(SPADES, KING);
//     Card c2(DIAMONDS, KING);
//     Card c3(CLUBS, QUEEN);
//     Card c4(HEARTS, QUEEN);
//     p1.addCardToStack(c1);
//     p1.addCardToStack(c3);
//     p2.addCardToStack(c2);
//     p2.addCardToStack(c4);

//     game.playTurn();
//     CHECK(game.getLastTurnWinner() == &p2);
//     CHECK(p2.cardesTaken() == 6);
// }

// //11
// TEST_CASE("each player takes the cards they threw if they run out of cards while breaking a tie") {
//     Player p1("Alice");
//     Player p2("Bob");
//     p1.addCard(Card(SPADES, KING));
//     p2.addCard(Card(HEARTS, KING));
//     Game game(p1, p2);
//     game.playTurn();
//     CHECK(p1.stacksize() == 0);
//     CHECK(p2.stacksize() == 0);
//     CHECK(p1.cardesTaken() == 2);
//     CHECK(p2.cardesTaken() == 2);
// }

// //12
// TEST_CASE("pot is divided half and half in case of a tie") {
//     Player p1("Alice");
//     Player p2("Bob");
//     p1.addCard(Card(CLUBS, 8));
//     p2.addCard(Card(DIAMONDS, 8));
//     p1.addCard(Card(SPADES, 3));
//     p2.addCard(Card(HEARTS, 3));
//     Game game(p1, p2);
//     game.playTurn();
//     CHECK(p1.stacksize() == 0);
//     CHECK(p2.stacksize() == 0);
//     CHECK(p1.cardesTaken() == 1);
//     CHECK(p2.cardesTaken() == 1);
// }

// //13
// TEST_CASE("multiple draws in a row") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1,p2);
//     game.playTurn(); // Alice plays Queen of Hearts, Bob plays Queen of Diamonds. Draw.
//     game.playTurn(); // Alice plays 2 of Spades, Bob plays 2 of Clubs. Draw.
//     game.playTurn(); // Alice plays 10 of Hearts, Bob plays 10 of Diamonds. Draw.
//     game.playTurn(); // Alice plays 3 of Clubs, Bob plays 3 of Hearts. Draw.
//     game.playTurn(); // Alice plays 8 of Diamonds, Bob plays 8 of Spades. Draw.
//     CHECK(game.getLastTurnResult() == "Alice played 8 of Diamonds Bob played 8 of Spades. Draw.");
// }

// //14
// TEST_CASE("draw within a draw") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1,p2);
//     game.playTurn(); // Alice plays King of Clubs, Bob plays 6 of Spades. Alice wins.
//     game.playTurn(); // Alice plays 5 of Diamonds, Bob plays 5 of Hearts. Draw.
//     game.playTurn(); // Alice plays Queen of Diamonds, Bob plays 8 of Clubs. Bob wins.
//     game.playTurn(); // Alice plays 2 of Hearts, Bob plays 2 of Diamonds. Draw within a draw.
//     game.playTurn(); // Alice plays 7 of Spades, Bob plays 7 of Clubs. Draw within a draw.
//     CHECK(game.getLastTurnResult() == "Alice played 7 of Spades Bob played 7 of Clubs. Draw within a draw.");
// }

// //15
// TEST_CASE("multiple ties in a row") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1,p2);
//     game.playTurn(); // Alice plays Ace of Hearts, Bob plays Ace of Spades. Draw.
//     game.playTurn(); // Alice plays 2 of Clubs, Bob plays 2 of Diamonds. Draw.
//     game.playTurn(); // Alice plays 3 of Hearts, Bob plays 3 of Clubs. Draw.
//     game.playTurn(); // Alice plays 4 of Spades, Bob plays 4 of Diamonds. Draw.
//     game.playTurn(); // Alice plays 5 of Hearts, Bob plays 5 of Clubs. Draw.
//     CHECK(game.getLastTurnResult() == "Alice played 5 of Hearts Bob played 5 of Clubs. Draw.");
// }

// //16
// TEST_CASE("one player runs out of cards") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1,p2);
//     for (int i=0; i<26; i++) {
//         game.playTurn();
//     }
//     CHECK(game.getLastTurnResult() == "Alice played 7 of Spades Bob played 7 of Diamonds. Alice wins.");
//     CHECK(game.getWinner() == &p1);
//     CHECK(p1.stacksize() == 0);
//     CHECK(p2.cardesTaken() == 52);
// }

// //17
// TEST_CASE("both players run out of cards at the same time") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1,p2);
//     for (int i=0; i<26; i++) {
//         game.playTurn();
//     }
//     game.playTurn(); // Alice plays 4 of Diamonds, Bob plays 4 of Spades. Draw.
//     game.playTurn(); // Alice plays 8 of Spades, Bob plays 8 of Hearts. Draw.
//     game.playTurn(); // Alice plays 2 of Hearts, Bob plays 2 of Clubs. Draw.
//     CHECK(game.getLastTurnResult() == "Alice played 2 of Hearts Bob played 2 of Clubs. Draw.");
//     CHECK(game.getWinner() == nullptr);
//     CHECK(p1.stacksize() == 0);
//     CHECK(p2.stacksize() == 0);
//     CHECK(p1.cardesTaken() == 26);
//     CHECK(p2.cardesTaken() == 26);
// }

// //18
// TEST_CASE("one player has more than half of the total cards") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1,p2);
//     for (int i=0; i<30; i++) {
//         game.playTurn();
//     }
//     CHECK(game.getWinner() == nullptr);
//     CHECK(p1.cardesTaken() == 20);
//     CHECK(p2.cardesTaken() == 10);
//     CHECK(p1.winRate() == doctest::Approx(0.66666667));
//     CHECK(p2.winRate() == doctest::Approx(0.33333333));
// }

// //19
// TEST_CASE("exactly half of the total cards are taken") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1,p2);
//     for (int i=0; i<25; i++) {
//         game.playTurn();
//     }
//     game.playTurn(); // Alice plays 6 of Hearts, Bob plays 6 of Spades. Draw.
//     game.playTurn(); // Alice plays 10 of Clubs, Bob plays 10 of Diamonds. Draw.
//     game.playTurn(); // Alice plays Jack of Clubs, Bob plays King of Diamonds. Bob wins.
//     CHECK(game.getLastTurnResult() == "Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.");
//     CHECK(game.getWinner() == &p2);
//     CHECK(p1.cardesTaken() == 13);
//     CHECK(p2.cardesTaken() == 13);
//     CHECK(p1.winRate() == doctest::Approx(0.5));
//     CHECK(p2.winRate() == doctest::Approx(0.5));
//     CHECK(game.getDrawRate() == doctest::Approx(0.2));
//     CHECK(game.getDrawCount() == 5);
// }

// //20
// TEST_CASE("no more cards left to draw") {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1,p2);
//     for (int i=0; i<26; i++) {
//         game.playTurn();
//     }
//     CHECK(game.getLastTurnResult() == "Alice played 7 of Spades Bob played 7 of Diamonds. Alice wins.");
//     CHECK(game.getWinner() == &p1);
//     CHECK(p1.cardesTaken() == 26);
//     CHECK(p2.cardesTaken() == 26);
//     CHECK(p1.winRate() == doctest::Approx(0.5));
//     CHECK(p2.winRate() == doctest::Approx(0.5));
//     CHECK(game.getDrawRate() == doctest::Approx(0.0));
//     CHECK(game.getDrawCount() == 0);
// }


