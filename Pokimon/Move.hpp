//
//  Move.hpp
//  Pokimon
//
//  Created by Osama on 2023-12-08.
//

#ifndef Move_hpp
#define Move_hpp
#include <string>
#include "Type.hpp"
#include <iostream>

class Pokemon;

class Move
{
protected:
    const std::string name;
    const Type type;
    const int power;

    virtual void execute(Pokemon *, Pokemon *) const = 0;

public:
    Move(const std::string& name, const Type type, const int power);
    

    virtual ~Move(){};
    
    void perform(Pokemon* attacker, Pokemon* defender) const;
};

class PhysicalMove:public Move{
public:
    PhysicalMove(const std::string& name,const Type type, const int power);
    
    virtual void execute(Pokemon *, Pokemon *) const override;
};

class SpecialMove:public Move {
public:
    SpecialMove(const std::string& name,const Type type, const int power);
   
    virtual void execute(Pokemon *, Pokemon *) const override;
};



#endif /* Move_hpp */
