#include<iostream>

using namespace std;

class Game{

    public:
        string name;
        string size;
        string author;
        int price;
        static int totalPrice; // cannot be initialised here
    

        Game(string gameName, string gameSize, string gameAuthor, int gamePrice):
            name(gameName), size(gameSize), author(gameAuthor), price(gamePrice){
                totalPrice += gamePrice;
                cout << "constructor has initialised the objects" << endl;
            }
        
        ~Game() {
            cout << "destructor is called" << endl;
        } 

        void displayTotalCost(){
            cout << "total cost of all games: " << totalPrice << endl;
        }

        void displayGameInformation(){
            cout << "name of the game: " << name << " size: "<< size << " author: " << author << " cost in ₹: " << price << endl;
        }
};

int Game::totalPrice = 0;

int main(){

    //dynamically created objects. new always returns a pointer.
    Game *game1 = new Game("surprice","53MB","keshav",1200);
    Game *game2 = new Game("shocked","1024KB","keshav", 12);
    

    game1->displayGameInformation();
    game2->displayGameInformation();
    game2->displayTotalCost();

    delete game1;
    delete game2;

}