#include<iostream>
using namespace std;

int attack(int health, int damage) {
    int newHealth = health - damage; 
    return newHealth;
}

int defend(int health, int armor) {
    int newHealth = health + armor/2; 
    return newHealth;
}

int heal(int health, int amount) {
    int newHealth = health + amount; 
    return newHealth;
}

int battleRound(int health, int &armor, int &points) {
    int damage = 30;
    int healAmount = 5;
    
    cout << "\nEntering Battle Round..." << endl;
    health = defend(health, armor);
    armor -= 5; 
    points += 20;
    
    health = attack(health, damage);
    points -= 10; 

    health = heal(health, healAmount);
    points += 30;

    return health;
}

void startGame(int &final_health, int &final_armor, int &final_points) {
    int health = 100;
    int armor = 30;
    int points = 0;

    cout << "Game Start! Initial Health: " << health 
         << ", Armor: " << armor 
         << ", Points: " << points << endl;

    health = battleRound(health, armor, points);

    cout << "\nBattle Round Over! Final Status -> Health: " << health 
         << ", Armor: " << armor 
         << ", Points: " << points << endl;
         
    final_health = health;
    final_armor = armor;
    final_points = points;
}

int main() {
    int health, armor, points;

    startGame(health, armor, points); 

    cout << "Final Stats - Health: " << health << ", Armor: " << armor << ", Points: " << points << endl;
    
    if(points >= 50 && health > 0) {
        cout << "You won. Play again" << endl;
    } else {
        cout << "You Lose. Game Over. Play again" << endl;
    }

    return 0;
}

