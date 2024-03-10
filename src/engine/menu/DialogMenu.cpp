#pragma once
#include "DialogMenu.hpp"
#include "../../external/ArduboyG.h"
#include "../../fxdata.h"
#include "../../lib/Type.hpp"
#include "../draw.h"
#include "../world/Event.hpp"
#include <ArduboyFX.h>
#include "../../lib/Text.hpp"
#include "../../common.hpp"

#define WHITETEXT 1
#define BLACKTEXT 0

void DialogMenu::drawPopMenu() {
    PopUpDialog curMenu = popDialogStack[0];
    SpritesU::drawOverwriteFX(0, 40, battleMenu, FRAME(0));

    uint24_t addr;
    setTextColorBlack();
    switch (curMenu.type) {
    case TEXT:
        SpritesU::drawOverwriteFX(curMenu.x + 8, curMenu.y + 2, curMenu.textAddress, FRAME(WHITETEXT));
        break;
    case DAMAGE:
    case ENEMY_DAMAGE:
        font.setCursor(curMenu.x + 3, curMenu.y + 3);
        font.println(curMenu.damage);
        SpritesU::drawOverwriteFX(curMenu.x + 8, curMenu.y + 2, damageText, FRAME(WHITETEXT));
        break;
    case NAME:
        addr = FX::readIndexedUInt24(CreatureNames::CreatureNames, curMenu.textAddress);
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y + 2, addr, FRAME(WHITETEXT));
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y + 10, attackText, FRAME(WHITETEXT));
        break;
    case ENEMY_NAME:
        addr = FX::readIndexedUInt24(CreatureNames::CreatureNames, curMenu.textAddress);
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y, addr, FRAME(WHITETEXT));
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y + 10, enemyAttackText, FRAME(WHITETEXT));
        break;
    case FAINT:
        addr = FX::readIndexedUInt24(CreatureNames::CreatureNames, curMenu.textAddress);
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y, addr, FRAME(WHITETEXT));
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y + 10, Fainted, FRAME(WHITETEXT));
        break;
    case SWITCH:
        addr = FX::readIndexedUInt24(CreatureNames::CreatureNames, curMenu.textAddress);
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y, addr, FRAME(WHITETEXT));
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y + 10, SwitchIn, FRAME(WHITETEXT));
        break;
    case WIN:
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y + 10, win, FRAME(WHITETEXT));

        break;
    case LOSS:
        addr = FX::readIndexedUInt24(CreatureNames::CreatureNames, curMenu.textAddress);
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y, addr, FRAME(WHITETEXT));
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y + 10, lose, FRAME(WHITETEXT));
        break;
    case ESCAPE_ENCOUNTER:
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y, escape, FRAME(WHITETEXT));
        break;
    case GATHERING:
        // font.setCursor(curMenu.x + 3, curMenu.y + 3);
        // //printString(font, "Gathering is not", curMenu.x + 3, curMenu.y + 3);
        // font.setCursor(curMenu.x + 3, curMenu.y + 13);
        // //printString(font, "implemented yet", curMenu.x + 3, curMenu.y + 13);
        break;
    case TEAM_CHANGE:
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y, changedIn, FRAME(WHITETEXT));
        break;
    case EFFECTIVENESS:
        Modifier mod = Modifier(curMenu.textAddress);
        switch (mod) {
        case Modifier::Quarter:
            SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y, quarter, FRAME(WHITETEXT));
            break;
        case Modifier::Half:
            SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y, half, FRAME(WHITETEXT));
            break;
        case Modifier::Double:
            SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y, doubled, FRAME(WHITETEXT));
            break;
        case Modifier::Quadruple:
            SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y, quad, FRAME(WHITETEXT));
            break;
        }
        SpritesU::drawOverwriteFX(curMenu.x + 3, curMenu.y + 10, damageText, FRAME(WHITETEXT));
        break;
    }
}

bool DialogMenu::peek() {
    return dialogPointer >= 0;
}

void DialogMenu::pushMenu(PopUpDialog info) {
    dialogPointer++;
    popDialogStack[dialogPointer] = info;
}

void DialogMenu::pushEvent(Event event) {
    dialogPointer++;
    popDialogStack[dialogPointer] = PopUpDialog{0, 34, 120, 30, event.textAddress, TEXT};
}

void DialogMenu::popMenu() {
    if (dialogPointer <= 0) {
        dialogPointer--;
        return;
    }
    for (uint8_t i = 0; i < dialogPointer; i++) {
        popDialogStack[i] = popDialogStack[i + 1];
    }
    dialogPointer--;
}