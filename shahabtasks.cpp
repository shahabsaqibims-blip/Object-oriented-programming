#include <iostream>
using namespace std;

class Hero {
protected:
    string name;
    string type;
    int health;
    double power;
    int experience;

public:

    Hero(string n, string t, int h, double p, int exp) {
        name = n;
        type = t;
        health = h;
        power = p;
        experience = exp;
    }

        void showGameMessage() {
        cout << " FANTASY BATTLE ARENA \n";
        cout << "Each hero fights with unique abilities.\n";
        cout << "Attack and Defense determine survival!\n";

    }


    virtual double attack() = 0;
    virtual double defend() = 0;


    void displayBasicInfo() {
        cout << "Hero Name: " << name << endl;
        cout << "Hero Type: " << type << endl;
        cout << "Health: " << health << endl;
        cout << "Power: " << power << endl;
        cout << "Experience: " << experience << endl;
    }
};


class Warrior : public Hero {
private:
    string weapon;
    double armorStrength;
    int rageLevel;

public:
    Warrior(string n, int h, double p, int exp,
            string w, double armor, int rage)
        : Hero(n, "Warrior", h, p, exp) {
        weapon = w;
        armorStrength = armor;
        rageLevel = rage;
    }

    void display() {
        cout << "\n----- WARRIOR PROFILE -----\n";
        displayBasicInfo();
        cout << "Weapon: " << weapon << endl;
        cout << "Armor Strength: " << armorStrength << endl;
        cout << "Rage Level: " << rageLevel << endl;
    }

    double attack() {
        return power * (1 + rageLevel * 0.1) + experience * 0.5;
    }

    double defend() {
        return armorStrength * 1.5 + health * 0.2;
    }
};


class Mage : public Hero {
private:
    string spell;
    int mana;
    double magicMultiplier;

public:
    Mage(string n, int h, double p, int exp,
         string s, int m, double mm)
        : Hero(n, "Mage", h, p, exp) {
        spell = s;
        mana = m;
        magicMultiplier = mm;
    }

    void display() {
        cout << "\n----- MAGE PROFILE -----\n";
        displayBasicInfo();
        cout << "Spell: " << spell << endl;
        cout << "Mana: " << mana << endl;
        cout << "Magic Multiplier: " << magicMultiplier << endl;
    }

    double attack() {
        return power * magicMultiplier + mana * 0.8;
    }

    double defend() {
        return mana * 0.5 + experience * 0.3;
    }
};


class Archer : public Hero {
private:
    string bowType;
    int arrows;
    double accuracy;

public:
    Archer(string n, int h, double p, int exp,
           string bt, int arr, double acc)
        : Hero(n, "Archer", h, p, exp) {
        bowType = bt;
        arrows = arr;
        accuracy = acc;
    }

    void display() {
        cout << "\n----- ARCHER PROFILE -----\n";
        displayBasicInfo();
        cout << "Bow Type: " << bowType << endl;
        cout << "Arrows: " << arrows << endl;
        cout << "Accuracy: " << accuracy << endl;
    }

    double attack() {
        return power * accuracy + arrows * 0.3;
    }

    double defend() {
        return accuracy * 50 + health * 0.1;
    }
};

int main() {

    
    Warrior w("Thor", 150, 80.5, 40, "Axe", 60.0, 5);
    Mage m("Merlin", 100, 70.0, 50, "Fireball", 120, 1.8);
    Archer a("Legolas", 110, 65.0, 45, "Longbow", 80, 0.9);

    w.showGameMessage();

    w.display();
    m.display();
    a.display();

    double wAttack = w.attack();
    double mAttack = m.attack();
    double aAttack = a.attack();

    double wDefense = w.defend();
    double mDefense = m.defend();
    double aDefense = a.defend();

      cout << "\n BATTLE RESULTS \n";

    cout << "\nWarrior Attack: " << wAttack;
    cout << "\nWarrior Defense: " << wDefense << endl;

    cout << "\nMage Attack: " << mAttack;
    cout << "\nMage Defense: " << mDefense << endl;

    cout << "\nArcher Attack: " << aAttack;
    cout << "\nArcher Defense: " << aDefense << endl;

    
    cout << "\n FINAL SUMMARY \n";

    if (wAttack > mAttack && wAttack > aAttack)
        cout << "Warrior has the highest attack power!\n";
    else if (mAttack > wAttack && mAttack > aAttack)
        cout << "Mage has the highest attack power!\n";
    else
        cout << "Archer has the highest attack power!\n";

    cout << "==========================\n";

    return 0;
}