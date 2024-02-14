//
//  Pokemon.hpp
//  Pokimon
//
//  Created by Osama on 2023-12-08.
//

#ifndef Pokemon_hpp
#define Pokemon_hpp
#include <string>
#include "Type.hpp"
#include "Move.hpp"
#include <stdexcept>

class Pokemon
{
private:
    const Move* move1;
    const Move* move2;
    const Move* move3;
    const Move* move4;
    
    const std::string name;
    int health;
    int attack;
    int spAttack;
    int defense;
    int spDefense;
    
    
    
protected:
    const Type type;
   
    
public:
    // dessa borde förmodligen inte vara public
    
    
    Pokemon(const std::string &name, const Type type, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health,  int attack, int spAttack, int defense, int spDefense);
    
    
    virtual ~Pokemon(){};
    
    void executeMove1(Pokemon* target);
    
    void executeMove2(Pokemon* target);
    
    void executeMove3(Pokemon* target);
    
    void executeMove4(Pokemon* target);
    
    void reduceHealth(int damage);
    
    virtual float calculateDamageMultiplier(Type damagetype);
    
    int getHealth()const{return health;}
    
    int getAttack()const{return attack;}
    
    
    int getSpecialAttack()const {
        return spAttack;
    }
    
    int getDefence()const{
        return defense;
    }
    
    int getSpecialDefence()const{
        return spDefense;
    }
    
    
    string getName()const{
        return name;
    }
    
};
class DualTypePokemon:public Pokemon{
private:
    const Type secondType;
public:
    DualTypePokemon(const std::string& name, Type primaryType,Type secondType, const Move* move1,const Move* move2,const Move* move3,const Move* move4, int health, int attack, int spAttack,int defense, int spDefence);
    
    virtual ~DualTypePokemon(){};
    
    float calculateDamageMultiplier(Type damagetype)override;
};


#endif /* Pokemon_hpp */
