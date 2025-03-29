#include <iostream>
#include <vector>

class Plant {
public:
    Plant(int health, int damage) : health(health), damage(damage) {}
    void attack(Zombie& zombie);
private:
    int health;
    int damage;
};

class Zombie {
public:
    Zombie(int health, int speed) : health(health), speed(speed) {}
    void move();
private:
    int health;
    int speed;
};

class GameController {
public:
    void startGame();
    void update();
private:
    std::vector<Plant> plants;
    std::vector<Zombie> zombies;
};

int main() {
    GameController game;
    game.startGame();
    return 0;
}