#include "game.hpp"




int main(){

    // Init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    // Init game
    Game game;
    

    // Game loop
    while(game.isRunning()){


        // Update - polling contained in update()
        game.update();

        // Render
        game.render();
    }



    if (game.isRunning() == false){
        game.deleteOnClose();
    }

    return 0;
}