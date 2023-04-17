#include "Arduboy2.h"
#include "Battle.hpp"
#include "../../creature/Creature.hpp"
#include "../../opponent/Opponent.hpp"
#include "../../player/Player.hpp"
#include "../../lib/TypeTable.hpp"
#include "../../lib/Move.hpp"
#ifdef CLI
#include <iostream>
#endif

#define DEBUG

uint16_t BattleEngine::calculateDamage(Action* action, Creature* committer, Creature* reciever) {
    //need to do something here with atk def stats
    uint8_t move = moveList[committer->moves[action->actionIndex]];
    float mod = getMatchupModifier(getMoveType(move), uint8_t(reciever->type))/2;
    uint8_t power = getMovePower(move);

    #ifdef DEBUG
        this->arduboy->print(F("p:  atk:  def:\n"));
        this->arduboy->print((unsigned)power);  this->arduboy->print(" ");
        this->arduboy->print((unsigned)committer->getAtkStat());this->arduboy->print(" ");
        this->arduboy->print((unsigned)reciever->getDefStat());this->arduboy->print(" ");
        this->arduboy->print("\n");
        this->arduboy->print(F("move Type: rtype: mod: \n"));
        this->arduboy->print((unsigned)getMoveType(move)); this->arduboy->print(" "); 
        this->arduboy->print((unsigned)reciever->type); this->arduboy->print(" ");
        this->arduboy->print((mod));this->arduboy->print(" ");
    #endif
    
    uint16_t damage = ((power * committer->getAtkStat() / reciever->getDefStat()) * mod);
    if ( damage == 0 ){
        if (mod == 0) {
            return 0;
        }
        return 1;
    }

    // going too need to balance this eventually
    return damage;
}

BattleEngine::BattleEngine(Arduboy2* arduboy) {
    this->arduboy = arduboy;
}

// battle loop
void BattleEngine::encounter() {
    if (this->checkLoss()) {
        this->arduboy->print("win\n");
    }

    if(this->checkWin()) {
        this->arduboy->print("loose\n");
    }
    if(this->arduboy->justPressed(A_BUTTON)){
    this->turnTick();
    }
    #ifdef DEBUG
        this->printEncounter();
        // this->playerCur->printMoves();
    #endif

   
}


void BattleEngine::loadOpponent(OpponentSeed* seed) {
    this->opponent.load(seed);
    this->opponentIndex = 0;
    this->opponentCur = &(this->opponent.party[0]);
    this->opponentHealths[0] = this->opponent.party[0].getHpStat();
    this->opponentHealths[1] = this->opponent.party[1].getHpStat();
    this->opponentHealths[2] = this->opponent.party[2].getHpStat();
}

void BattleEngine::loadPlayer(Player* player) {
    this->playerParty[0] = &(player->party[0]);
    this->playerParty[1] = &(player->party[1]);
    this->playerParty[2] = &(player->party[2]);
    // for now the hp will refil every encounter so we dont need to use the player field
    //this->playerHealths[i] = player->creatureHPs[i];
    this->playerHealths[0] = this->playerParty[0]->getHpStat();
    this->playerHealths[1] = this->playerParty[1]->getHpStat();
    this->playerHealths[2] = this->playerParty[2]->getHpStat();
    
    this->playerIndex = 0;
    this->playerCur = this->playerParty[0];
}

void BattleEngine::startEncounter(Player* player, OpponentSeed* seed) {
    this->arduboy->print("starting encounter\n");
    this->loadOpponent(seed);
    this->loadPlayer(player);
}

//this function is terrible
void BattleEngine::turnTick() {
    this->getInput();
    this->opponentInput();
    int8_t order = this->playerAction.priority != this->opponentAction.priority;
    if(order > 0){
        this->playerActionFirst();
    } else if (order < 0) {
        this->opponentActionFirst();
    } else {
        order = this->playerCur->getSpdStat() - this->opponentCur->getSpdStat();
        if(order > 0 || order == 0){
            this->playerActionFirst();
        } else if (order < 0) {
            this->opponentActionFirst();
        }
    }
}

void BattleEngine::playerActionFirst() {
    #ifdef CLI
        std::cout << "player action \n";
    #endif
    this->commitAction(&this->playerAction, this->playerCur, this->opponentCur);
    this->checkOpponentFaint();
    #ifdef CLI
        std::cout << "opponent action \n";
    #endif
    this->commitAction(&this->opponentAction, this->opponentCur, this->playerCur);
    this->checkPlayerFaint();
}

void BattleEngine::opponentActionFirst() {
    #ifdef CLI
        std::cout << "opponent action \n";
    #endif
    this->commitAction(&this->opponentAction, this->opponentCur, this->playerCur);
    this->checkPlayerFaint();
    #ifdef CLI
        std::cout << "player action \n";
    #endif
    this->commitAction(&this->playerAction, this->playerCur, this->opponentCur);
    this->checkOpponentFaint();

}

void BattleEngine::checkPlayerFaint() {
    if (this->playerHealths[this->playerIndex] <= 0 ){
        #ifdef CLI
        std::cout << "player faint \n";
        #endif
        this->playerIndex++;
        this->playerCur = this->playerParty[this->playerIndex];
        //this->awakeMons &= ~(1 << this->playerIndex);
    }
}

void  BattleEngine::checkOpponentFaint() {
    if (this->opponentHealths[this->opponentIndex] <= 0 ){
        #ifdef CLI
        std::cout << "opponent faint \n";
        #endif
        this->opponentIndex++;
        this->opponentCur = &(this->opponent.party[this->opponentIndex]);
        //this->awakeMons &= ~(1 << this->opponentIndex+5);
    }
}

bool BattleEngine::checkLoss() {
    //return uint8_t(this->awakeMons & 0b11100000) == uint8_t(0) ;
    return (this->playerHealths[0] <= 0 && this->playerHealths[1] <= 0 && this->playerHealths[2] <= 0);
}

bool BattleEngine::checkWin() {
    //return uint8_t(this->awakeMons & 0b00000111) == uint8_t(0) ;
    return (this->opponentHealths[0] <= 0 && this->opponentHealths[1] <= 0 && this->opponentHealths[2] <= 0);
}

void BattleEngine::endEncounter() {

    this->arduboy->print(F("\nend encounter \n"));

    #ifdef CLI
        std::cout << "end encounter \n";
    #endif
}

void BattleEngine::getInput() {
    // arduboy input from menu
    //this->menu->actionInput(&this->playerAction);
    this->arduboy->display();
    //while(!this->arduboy->justPressed(A_BUTTON)){}
    this->arduboy->clear();

    this->opponentAction.setActionType(ActionType::ATTACK);
    this->opponentAction.actionIndex = 1;
}

void BattleEngine::opponentInput() {
    // ai to select best move

    //For now just do the first slot attack
    this->opponentAction.setActionType(ActionType::ATTACK);
    this->opponentAction.actionIndex = 1;
}



#ifdef CLI
        void BattleEngine::loadAwakeMons(uint8_t b){
            this->awakeMons = b;
        }

        void BattleEngine::printEncounter() {
            std::cout << "PLAYER: cur: " << (unsigned)this->playerIndex << " lvl: " << (unsigned)this->playerCur->level;
            std::cout << " type: " << (unsigned)this->playerCur->type << "\nhp:";
            for(int i = 0; i < 3; i++ ){ std::cout << " " << (unsigned)this->playerHealths[i];}
            std::cout << std::endl;
            std::cout << "Opponent: cur:" << (unsigned)this->opponentIndex << " lvl: " << (unsigned)this->opponentCur->level;
            std::cout << " type: " << (unsigned)this->opponentCur->type  << "\nhp:";
            for(int i = 0; i < 3; i++ ){ std::cout << " " << (unsigned)this->opponentHealths[i];} 
            std::cout << std::endl;
        }
#endif

void BattleEngine::commitAction(Action* action, Creature* commiter, Creature* reciever) {
    switch (action->actionType) {
    case ActionType::ATTACK: {
        uint16_t damage = calculateDamage(action, commiter, reciever);
        #ifdef CLI
            std::cout << "Attacking with index " << (unsigned)action->actionIndex << " Damage: " << unsigned(damage) << std::endl;
        #endif
        applyDamage(damage, reciever);
        break;
    }
    case ActionType::ITEM:
        break;
    case ActionType::CHNGE:
        break;
    case ActionType::ESCAPE:
        // should add a check in here for opponent vs random encounter
        this->endEncounter();
        break;
    
    default:
        break;
    }
}


void BattleEngine::applyDamage(uint16_t damage, Creature* reciever) {
    if( reciever == this->playerCur) {
        uint8_t hp = this->playerHealths[this->playerIndex];
        this->playerHealths[this->playerIndex] -= damage >= hp ? hp : damage;
    } else {
        uint8_t hp = this->opponentHealths[this->opponentIndex];
        this->opponentHealths[this->opponentIndex] -= damage >= hp ? hp : damage;

    }

}


#ifdef DEBUG

        void BattleEngine::printEncounter() {
            this->arduboy->print("P: cur: "); this->arduboy->print((unsigned)this->playerIndex); 
            this->arduboy->print(" lvl: "); this->arduboy->print((unsigned)this->playerCur->level);
            this->arduboy->print("\nhp:");
            for(int i = 0; i < 3; i++ ){ this->arduboy->print(" "); this->arduboy->print((unsigned)this->playerHealths[i]);}
            this->arduboy->print("\nO: cur: "); this->arduboy->print((unsigned)this->opponentIndex); 
            this->arduboy->print(" lvl: "); this->arduboy->print((unsigned)this->opponentCur->level);
            this->arduboy->print("\nhp:");
            for(int i = 0; i < 3; i++ ){ this->arduboy->print(" "); this->arduboy->print((unsigned)this->opponentHealths[i]);}
        }

#endif