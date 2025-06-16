#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class CharacterActions {
public:
    virtual int attack() = 0;
    virtual void defend() = 0;
    virtual bool useSpecialAbility() = 0;
    virtual void displayStats() = 0;
};

class BaseCharacter :public CharacterActions {
protected:
    string name;
    int health;
    int mana;
    int attack_power;
    string special_ability;
    int special_ability_power;
public:
    BaseCharacter(string _name, int n1, int n2, int n3, string s2, int n4) :
        name(_name), health(n1), mana(n2), attack_power(n3), special_ability(s2), special_ability_power(n4) {
    }
    int attack() override {
        mana += 50;
        return attack_power;
    }
    void defend() override {

    }
    bool useSpecialAbility() override {
        if (mana >= 100) {
            mana = 0;
            return true;
        }
        return false;
    }
    void displayStats() override {
        cout << "Name: " << name << endl
            << "Health: " << health << endl
            << "Mana: " << mana << endl;
    }
    void statusAfterAttack(int _damage) {
        cout << name << " takes " << _damage << " damage! Health now: " << health << endl;
    }
    void attacking() {
        cout << name <<" attacks with power " << attack_power << "!" << endl;
    }
    void attacking(BaseCharacter* pB) {
        cout << name <<" attacks "<< pB->name <<" with power " << attack_power << "!" << endl;
    }
    void attacking(string s) {
        cout << name << " uses " << s << " with power " << special_ability_power <<"!" << endl;
    }
    void damage(int _damage){
        health -= _damage;
    }
    int getHealth() {
        return health;
    }
};

class Warrior :public BaseCharacter {
public:
    Warrior(string _name) :BaseCharacter(_name, 100, 0, 25, "Berserk Rage", 35) {}
};

class Mage :public BaseCharacter {
public:
    Mage(string _name) :BaseCharacter(_name, 120, 0, 20, "Arcane Blast", 30) {}
};

class Archer :public BaseCharacter {
public:
    Archer(string _name) :BaseCharacter(_name, 90, 0, 20, "Fire Arrow", 35) {}
};

class BossEnemy :public BaseCharacter {
public:
    BossEnemy(string _name) :BaseCharacter(_name, 150, 0, 30, "Inverse Plot Armour", -9000) {}
};

class GameEngine {
private:
    BaseCharacter* pWar;
    BaseCharacter* pMage;
    BaseCharacter* pArch;
    BaseCharacter* pBoss;
public:
    GameEngine() :pWar(new Warrior("Hercules")), pMage(new Mage("Rin")), pArch(new Archer("Emiya")), pBoss(new BossEnemy("Gilgamesh")) {}
    void startGame() {
        cout << "Game begins! Players vs. Boss" << endl << endl;
        int t=1;
        while (1) {
            // warrior attacks boss
            pWar->attacking();
            pBoss->damage(pWar->attack());
            pBoss->statusAfterAttack(pWar->attack());
            cout << endl;
            if(pBoss->getHealth() <= 0) {
                cout << "Boss defeated! Players win!" << endl;
                break;
            }
            cout << endl;
            // mage attacking boss
            pMage->attacking();
            pBoss->damage(pMage->attack());
            pBoss->statusAfterAttack(pMage->attack());
            cout << endl;
            if(pBoss->getHealth() <= 0) {
                cout << "Boss defeated! Players win!" << endl;
                break;
            }
            cout << endl;
            // archer attacking boss
            pArch->attacking();
            pBoss->damage(pArch->attack());
            pBoss->statusAfterAttack(pArch->attack());
            cout << endl;
            if(pBoss->getHealth() <= 0) {
                cout << "Boss defeated! Players win!" << endl;
                break;
            }
            cout << endl;

            // now boss attacks
            pBoss->attacking(pWar);
            pWar->damage(pBoss->attack());
            pWar->statusAfterAttack(pBoss->attack());
            cout << endl;
            if(pWar->getHealth() <= 0) {
                cout << "Warrior defeated! Boss wins! Game over" << endl;
                break;
            }
            cout << endl;

            pBoss->attacking(pMage);
            pMage->damage(pBoss->attack());
            pMage->statusAfterAttack(pBoss->attack());
            cout << endl;
            if(pMage->getHealth() <= 0) {
                cout << "Mage defeated! Boss wins! Game over" << endl;
                break;
            }
            cout << endl;

            pBoss->attacking(pArch);
            pArch->damage(pBoss->attack());
            pArch->statusAfterAttack(pBoss->attack());
            cout << endl;
            if(pArch->getHealth() <= 0) {
                cout << "Archer defeated! Boss wins! Game over" << endl;
                break;
            }
            cout << endl;

        }
    }
};


int main() {
    GameEngine ge;
    ge.startGame();

    return 0;
}