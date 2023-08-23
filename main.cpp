#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int MAX_PLAYER_HEALTH = 100;
    const int CHANCE_OF_INVULNERABILITY = 5; // 1 in n
    const int INVULNERABLE_TURNS = 3; // n + 1 turns
    const int BOSS_MIN_DAMAGE = 3;
    const int BOSS_MAX_DAMAGE = 10;
    // TO-DO boss damage - range
    
    int playerHealth = MAX_PLAYER_HEALTH;
    int score = 0;
    int invulnerableTurn = 0;
    
    enum PlayerState {ALIVE, DEAD, INVULNERABLE};
    PlayerState playerState = ALIVE;
    
    // main game loop modeling the FSM
    // FSM ends when the playerState is in the temrinal state
    while (playerState != DEAD) {
        
        score++;
        cout << "You survived " << score << " rounds." << endl;
        int bossDamage = rand() % (BOSS_MAX_DAMAGE - BOSS_MIN_DAMAGE + 1) + BOSS_MIN_DAMAGE + 1;
        cout << "Boss does " << bossDamage << " damage!" << endl;
        
        
        switch(playerState) {
            case ALIVE:
                playerHealth -= bossDamage;
                    cout << "Player health reduced to " << playerHealth << endl;
                if (playerHealth <= 0) {
                    playerState = DEAD;
                }
                else if (rand() % CHANCE_OF_INVULNERABILITY == 0) {
                    cout << "You lucked into an invulerable BUFF, enjoy god mode!" << endl;
                    playerState = INVULNERABLE;
                    invulnerableTurn = INVULNERABLE_TURNS;
                }
                break;
            
            case INVULNERABLE:
                cout << "Invulnerable! Damage mitigated!" << endl;
                if (invulnerableTurn == 0) {
                    cout << "Invulnerable fades ...." << endl;
                    playerState = ALIVE;
                    
                }
                else {
                    cout << "Invulnerability has " << invulnerableTurn << endl;
                    invulnerableTurn--;
                    
                }
                break;
            
            
            case DEAD:
                cout << "You died." << endl;
                break;
        }
        
        
    }
    
    
    
    
    
	return 0;
}
