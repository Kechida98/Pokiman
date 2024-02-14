//
//  Move.cpp
//  Pokimon
//
//  Created by Osama on 2023-12-08.
//

#include "Pokemon.hpp"
#include "Move.hpp"

Move::Move(const std::string& name, const Type type, const int power)
: type(type), name(name), power(power)
{
    if (power<0) {
    throw invalid_argument("Not valid power for this move");
    }
}
void Move::perform(Pokemon *attacker, Pokemon *defender)const{
    
    // Kontrollera om attackeraren är medvetslös och inte kan använda draget
       if (attacker->getHealth() == 0)
       {
           cout << attacker->getName() << " is in a fainted state and can’t move." << endl;
           return;
       }

       else if (defender->getHealth() <= 0)
       {
           //säger till att attackeraren är medvetslös och att den inte kan göra sitt drag
           cout << attacker->getName() << " cannot perform a move, " << defender->getName() << " has already fainted." << endl;
           return;
       }
       else{
           // Utför draget om båda Pokémon är vid medvetande
           execute(attacker, defender);
       }

       
    // Meddela om försvararen blev medvetslös efter att draget utförts
       if (defender->getHealth() <= 0)
       {
           cout << defender->getName() << " has fainted." << endl;
       }
}

PhysicalMove::PhysicalMove(const std::string& name,const Type type, const int power)
: Move(name,type, power){}

void PhysicalMove::execute(Pokemon * attacker, Pokemon * defender) const {
    
    float basedDamage = (float)power * (attacker->getAttack()/(float)defender->getDefence()/5.f);
    float multiplier=defender->calculateDamageMultiplier(type);
    float totalDamage = basedDamage*multiplier;
    cout << attacker->getName() << " used " << name << endl;
    defender->reduceHealth(totalDamage);

    
    if (multiplier == 0) {
        cout<<"It doesn’t affect "<<defender->getName()<< endl;
    }else if (multiplier <1 && multiplier!=0){
        
        cout<<"It’s not very effective..."<< endl;
    }else if (multiplier>1){
        cout<<"It’s super effective!"<< endl;
        
    }
    
    
}

SpecialMove::SpecialMove(const std::string& name, const Type type, const int power)
:Move(name, type, power){}

void SpecialMove::execute(Pokemon * specialAttack, Pokemon *specialDefender)const{
    // Beräkna skadan baserat på speciell attack och speciellt försvar
    float baseDamage =(float)power * (specialAttack->getSpecialAttack()/(float)specialDefender->getSpecialDefence()/5.f);
    float multiplier = specialDefender->calculateDamageMultiplier(type);
    //cout<<type<< endl;
    //cout<<multiplier<<endl;
    
    float totalDamage = baseDamage*multiplier;
    //utför draget och minska försvarens hälsa
    std::cout << specialAttack->getName() << " used " << name << std::endl;
   
    specialDefender->reduceHealth(totalDamage);
    if (multiplier == 0) {
        cout<<"It doesn’t affect "<<specialDefender->getName()<< endl;
    }else if (multiplier <1 && multiplier !=0){
        
        cout<<"It’s not very effective..."<< endl;
    }else if (multiplier>1){
        cout<<"It’s super effective!"<< endl;
        
    }
}
