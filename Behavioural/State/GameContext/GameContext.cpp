#include <iostream>
class Player
{
    public:
	void attack() {
	    std::cout << "Player Attack" << std::endl;
	}
	void fireBumb() {
	    std::cout << "Player Bombs" << std::endl;
	}
	void fireGunblade() {
	    std::cout << "Player Gunpointed" << std::endl;
	}
	void fireLaserPistol() {
	    std::cout << "Player Laser Attack" << std::endl;
	}
	void survive() {
	    std::cout << "Player on survival mode" << std::endl;
	}
	void firePistol() {
	    std::cout << "Player only Pistol capability" << std::endl;
	}
	void dead() {
	    std::cout << "Player is dead" << std::endl;
	}


};

class PlayerState {	
    public:
    virtual void action(Player* p) = 0;
};

class HealthyState: public PlayerState {
    public:
	void action(Player* p) {
	    p->attack();
	    p->fireBumb();
	    p->fireGunblade();
	    p->fireLaserPistol();
	}
};

class SurvivalState: public PlayerState {
    public:
	void action(Player* p) {
	    p->survive();
	    p->firePistol();
	}
};

class DeadState: public PlayerState {
    public:
	void action(Player* p) {
	    p->dead();
	}
};

class GameContext {
    private:
	PlayerState* state;
	Player* player;
    public:
	GameContext ( ){
	    player = new Player();
	}
	void setState(PlayerState* state) { this->state = state; }
	void gameAction() { state->action(player); }
};


int main() {
    GameContext* context = new GameContext();
    HealthyState*   healthyState = new HealthyState();
    SurvivalState*  survivalState = new SurvivalState();
    DeadState*   deadState = new DeadState();

    context->setState(healthyState);
    context->gameAction();
    printf("*****\n");

    context->setState(survivalState);
    context->gameAction();
    printf("*****\n");

    context->setState(deadState);
    context->gameAction();
    printf("*****\n");
}
