#include "Creature.hpp"

#include <avr/pgmspace.h>

#include "../data/Creatures.hpp"
#include "../lib/Move.hpp"
#include "../opponent/OpponentSeed.hpp"
#include "../sprites/creatureSprites.h"

// This will need to load the creature seed from the progmemstore
const CreatureData_t getCreatureFromStore(uint8_t id) {
  CreatureData_t cseed;
  memcpy_P(&cseed, &CreatureData[id], sizeof(CreatureData_t));
  return cseed;
}

Creature::Creature() {
  this->statlist.attack = 0;
  this->statlist.defense = 0;
  this->statlist.speed = 0;
  this->statlist.hp = 0;
  this->statlist.spcAtk = 0;
  this->statlist.spcDef = 0;
}

// todo(snail)
//  maybe I should move this out into an abstraction so its easier to change
void Creature::load(CreatureData_t seed) {
  this->id = static_cast<uint8_t>((seed.id));
  this->setStats(seed);
  // Need some kind of default setting for moves ?
  this->loadMoves(seed);
  this->loadSprite(seed);
}

// 00,id1,lvl1,move11,move12,move13,move14,
void Creature::loadFromOpponentSeed(uint32_t seed) {
  CreatureData_t cSeed =
      getCreatureFromStore(parseOpponentCreatureSeedID(seed));
  this->id = static_cast<uint8_t>((cSeed.id));
  this->loadTypes(cSeed);
  this->level = parseOpponentCreatureSeedlvl(seed);
  this->setStats(cSeed);
  this->setMove(parseOpponentCreatureSeedMove(seed, 0), 0);
  this->setMove(parseOpponentCreatureSeedMove(seed, 1), 1);
  this->setMove(parseOpponentCreatureSeedMove(seed, 2), 2);
  this->setMove(parseOpponentCreatureSeedMove(seed, 3), 3);
  this->loadSprite(cSeed);
}

void Creature::loadMoves(CreatureData_t seed) {
  this->setMove(static_cast<uint8_t>((seed.move1)), 0);
  this->setMove(static_cast<uint8_t>((seed.move2)), 1);
  this->setMove(static_cast<uint8_t>((seed.move3)), 2);
  this->setMove(static_cast<uint8_t>((seed.move4)), 3);
}

void Creature::loadSprite(CreatureData_t seed) {
  this->sprite = creatureSprites[static_cast<uint8_t>((seed.id))];
}

void Creature::loadTypes(CreatureData_t seed) {
  this->types = DualType((Type) static_cast<uint8_t>((seed.type1)),
                         (Type) static_cast<uint8_t>((seed.type2)));
}

// should prob have error checking but w/e
void Creature::setMove(uint8_t move, uint8_t slot) {
  this->moves[slot] = move;
  this->moveList[slot] = Move(getMovePack(move));
}

void Creature::setStats(CreatureData_t seed) {
  this->statlist.attack = seedToStat((seed.atkSeed));
  this->statlist.defense = seedToStat((seed.defSeed));
  this->statlist.speed = seedToStat((seed.spdSeed));
  // need to bulk up lineraly
  this->statlist.hp = seedToStat((seed.hpSeed)) + 30;
  this->statlist.spcAtk = seedToStat((seed.spcAtkSeed));
  this->statlist.spcDef = seedToStat((seed.spcDefSeed));
}

// some ai to find best advantage should move this out of this class though
// going to need this for the opponent ai
uint8_t Creature::getAdvantage(DualType opponent) { return 0; }

uint8_t Creature::getMove(uint8_t slot) { return this->moves[slot]; }

bool Creature::moveTypeBonus(uint8_t index) {
  return this->types.getType1() == (Type)this->moveList[index].getMoveType() ||
         this->types.getType2() == (Type)this->moveList[index].getMoveType();
}

uint8_t Creature::seedToStat(uint8_t seed) {
  return seed;
  // return (2*this->level)*(seed/3);
}