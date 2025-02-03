#include "Phaser.hpp"
#include "Sounds.hpp"

const int Phaser::Empty = 0;

const std::string Sounds::Regular = "Bang";
const std::string Sounds::Plasma = "Fwooosh";
const std::string Sounds::Rocket = "Boouuuuuum";

Phaser::Phaser(int maxAmmo, AmmoType type)
{
    maxAmmo = maxAmmo;
    currentAmmo = currentAmmo;
    defaultType = type;
    magazine.resize(maxAmmo, type);
}

Phaser::~Phaser()
{
}

void Phaser::fire()
{
    if (currentAmmo == Empty) {
        std::cout << "Clip empty, please reload" << std::endl;
        return;
    }

    AmmoType currentType = magazine.front();
    std::string sound;
    switch (currentType) {
        case REGULAR: sound = Sounds::Regular; break;
        case PLASMA: sound = Sounds::Plasma; break;
        case ROCKET: sound = Sounds::Rocket; break;
    }

    std::cout << sound << std::endl;
    magazine.erase(magazine.begin());
    currentAmmo--;
}

void Phaser::ejectClip()
{
    magazine.clear();
    currentAmmo = Empty;
}

void Phaser::changeType(AmmoType newType)
{
    defaultType = newType;
    std::cout << "Switching ammo to type: " << (newType == REGULAR ? "regular" : newType == PLASMA ? "plasma" : "rocket") << std::endl;
}

void Phaser::reload()
{
    std::cout << "Reloading..." << std::endl;
    magazine.assign(maxAmmo, defaultType);
    currentAmmo = maxAmmo;
}

void Phaser::addAmmo(AmmoType type)
{
    if (currentAmmo == maxAmmo) {
        std::cout << "Clip full" << std::endl;
        return;
    }

    magazine.push_back(type);
    currentAmmo++;
}

int Phaser::getCurrentAmmos() const
{
    return currentAmmo;
}
