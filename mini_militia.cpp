#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Player {
public:
    int health;
    int ammo;

    Player() : health(100), ammo(50) {}

    void shoot() {
        if (ammo > 0) {
            std::cout << "Player shoots! Bang!" << std::endl;
            ammo--;
        } else {
            std::cout << "Out of ammo! Reload!" << std::endl;
        }
    }

    void takeDamage(int damage) {
        health -= damage;
        std::cout << "Player takes " << damage << " damage. Health: " << health << std::endl;
    }

    void reload() {
        ammo = 50;
        std::cout << "Player reloads. Ammo: " << ammo << std::endl;
    }
};

class Enemy {
public:
    int health;

    Enemy() : health(50) {}

    void takeDamage(int damage) {
        health -= damage;
        std::cout << "Enemy takes " << damage << " damage. Health: " << health << std::endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Player player;
    Enemy enemy;

    while (player.health > 0 && enemy.health > 0) {
        // Simulate player actions
        int action = rand() % 3;  // 0: shoot, 1: reload, 2: do nothing

        if (action == 0) {
            player.shoot();
            enemy.takeDamage(20);
        } else if (action == 1) {
            player.reload();
        }

        // Simulate enemy actions
        if (rand() % 2 == 0) {
            enemy.takeDamage(10);
        }

        // Simulate time passing
        // ...

        // Display game state
        // ...
    }

    // Display game over message
    // ...

    return 0;
}
