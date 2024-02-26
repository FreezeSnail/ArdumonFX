#pragma once

/**** FX data header generated by fxdata-build.py tool version 1.15 ****/

using uint24_t = __uint24;

// Initialize FX hardware using  FX::begin(FX_DATA_PAGE); in the setup() function.

constexpr uint16_t FX_DATA_PAGE  = 0xfe0b;
constexpr uint24_t FX_DATA_BYTES = 128052;

constexpr uint24_t encounterRates = 0x000000;
constexpr uint24_t op1 = 0x000048;
constexpr uint24_t opts = 0x000054;
namespace CreatureData
{
  constexpr uint24_t creatureData = 0x000058;
}

namespace MoveData
{
  constexpr uint24_t move0 = 0x000218;
  constexpr uint24_t move1 = 0x00021E;
  constexpr uint24_t move2 = 0x000226;
  constexpr uint24_t move3 = 0x00022D;
  constexpr uint24_t move4 = 0x000233;
  constexpr uint24_t move5 = 0x00023A;
  constexpr uint24_t move6 = 0x000241;
  constexpr uint24_t move7 = 0x000246;
  constexpr uint24_t move8 = 0x00024E;
  constexpr uint24_t move9 = 0x000255;
  constexpr uint24_t move10 = 0x00025C;
  constexpr uint24_t move11 = 0x000264;
  constexpr uint24_t move12 = 0x000269;
  constexpr uint24_t move13 = 0x000272;
  constexpr uint24_t move14 = 0x00027B;
  constexpr uint24_t move15 = 0x000284;
  constexpr uint24_t move16 = 0x00028C;
  constexpr uint24_t move17 = 0x000291;
  constexpr uint24_t move18 = 0x000296;
  constexpr uint24_t move19 = 0x00029C;
  constexpr uint24_t move20 = 0x0002A2;
  constexpr uint24_t move21 = 0x0002A7;
  constexpr uint24_t move22 = 0x0002AE;
  constexpr uint24_t move23 = 0x0002B3;
  constexpr uint24_t move24 = 0x0002B7;
  constexpr uint24_t move25 = 0x0002BE;
  constexpr uint24_t move26 = 0x0002C9;
  constexpr uint24_t move27 = 0x0002D2;
  constexpr uint24_t move28 = 0x0002D7;
  constexpr uint24_t move29 = 0x0002DC;
  constexpr uint24_t move30 = 0x0002E6;
  constexpr uint24_t move31 = 0x0002EB;
  constexpr uint24_t move32 = 0x0002F5;
  constexpr uint24_t moveNames = 0x0002F7;
  constexpr uint24_t movePack = 0x00035A;
}

namespace EventData
{
  constexpr uint24_t m1e1Text = 0x0003BA;
  constexpr uint24_t m1e1 = 0x0003C7;
  constexpr uint24_t m1eTable = 0x0003CA;
  constexpr uint24_t m1s1e1Text = 0x0003D6;
  constexpr uint24_t m1s1e1 = 0x0003E5;
  constexpr uint24_t m1s1e21Text = 0x0003E8;
  constexpr uint24_t m1s1e2 = 0x0003F7;
  constexpr uint24_t m1s1eTable = 0x0003FA;
  constexpr uint24_t m1Table = 0x000406;
  constexpr uint24_t eventTable = 0x00040C;
}

namespace MapData
{
  constexpr uint24_t map1 = 0x00040F;
  constexpr uint24_t house1 = 0x000667;
  constexpr uint24_t m1submaps = 0x0006A7;
  constexpr uint24_t m1submapcount = 0x0006AA;
  constexpr uint24_t m1widths = 0x0006AB;
  constexpr uint24_t m1heights = 0x0006AD;
  constexpr uint24_t map1Warps = 0x0006AF;
  constexpr uint24_t house1Warps = 0x0006B7;
  constexpr uint24_t m1warpCounts = 0x0006BB;
  constexpr uint24_t m1warps = 0x0006BD;
  constexpr uint24_t warps = 0x0006C3;
  constexpr uint24_t maps = 0x0006C6;
}

namespace MoveLists
{
  constexpr uint24_t moveList = 0x0006D8;
}

namespace MenuFXData
{
  constexpr uint24_t attackText = 0x000758;
  constexpr uint24_t enemyAttackText = 0x000769;
  constexpr uint24_t damageText = 0x000776;
  constexpr uint24_t hpText = 0x000783;
  constexpr uint24_t atkText = 0x000788;
  constexpr uint24_t defText = 0x00078E;
  constexpr uint24_t spdText = 0x000794;
  constexpr uint24_t satkText = 0x00079A;
  constexpr uint24_t sdefText = 0x0007A1;
  constexpr uint24_t pointerText = 0x0007A8;
  constexpr uint24_t SPIRIT = 0x0007AA;
  constexpr uint24_t WATER = 0x0007B1;
  constexpr uint24_t WIND = 0x0007B7;
  constexpr uint24_t EARTH = 0x0007BC;
  constexpr uint24_t FIRE = 0x0007C2;
  constexpr uint24_t LIGHTNING = 0x0007C7;
  constexpr uint24_t PLANT = 0x0007D1;
  constexpr uint24_t ELDER = 0x0007D7;
  constexpr uint24_t NONE = 0x0007DD;
  constexpr uint24_t Fainted = 0x0007DE;
  constexpr uint24_t SwitchIn = 0x0007E6;
  constexpr uint24_t win = 0x0007F7;
  constexpr uint24_t lose = 0x0007FF;
  constexpr uint24_t escaped = 0x00080A;
  constexpr uint24_t changedIn = 0x000816;
  constexpr uint24_t quarter = 0x00082A;
  constexpr uint24_t half = 0x00083C;
  constexpr uint24_t doubled = 0x000849;
  constexpr uint24_t quad = 0x000857;
  constexpr uint24_t damage = 0x000869;
  constexpr uint24_t physical = 0x000870;
  constexpr uint24_t special = 0x000875;
  constexpr uint24_t power = 0x00087A;
  constexpr uint24_t move = 0x000881;
  constexpr uint24_t change = 0x000886;
  constexpr uint24_t escape = 0x00088D;
  constexpr uint24_t gather = 0x000894;
}

namespace Teams
{
namespace StockCreatures
{
    constexpr uint24_t null = 0x00089B;
    constexpr uint24_t SquibbleSnail = 0x0008A0;
    constexpr uint24_t SquableSnail = 0x0008A5;
    constexpr uint24_t ScrambleSnail = 0x0008AA;
    constexpr uint24_t SkitterCrab = 0x0008AF;
    constexpr uint24_t ScatterCrab = 0x0008B4;
    constexpr uint24_t ShatterCrab = 0x0008B9;
    constexpr uint24_t squid = 0x0008BE;
    constexpr uint24_t bigsquid = 0x0008C3;
    constexpr uint24_t BiggestSquid = 0x0008C8;
    constexpr uint24_t bell = 0x0008CD;
    constexpr uint24_t ember = 0x0008D2;
    constexpr uint24_t cuircuit = 0x0008D7;
    constexpr uint24_t hedge = 0x0008DC;
    constexpr uint24_t cloud = 0x0008E1;
    constexpr uint24_t rock = 0x0008E6;
    constexpr uint24_t wiggleworm = 0x0008EB;
    constexpr uint24_t waggleworm = 0x0008F0;
    constexpr uint24_t skimskate = 0x0008F5;
    constexpr uint24_t skimray = 0x0008FA;
    constexpr uint24_t billow = 0x0008FF;
    constexpr uint24_t howl = 0x000904;
    constexpr uint24_t item = 0x000909;
    constexpr uint24_t item2 = 0x00090E;
    constexpr uint24_t zip = 0x000913;
    constexpr uint24_t zap = 0x000918;
    constexpr uint24_t suculent = 0x00091D;
    constexpr uint24_t cactus = 0x000922;
    constexpr uint24_t flickerfly = 0x000927;
    constexpr uint24_t flitfly = 0x00092C;
    constexpr uint24_t dragon = 0x000931;
    constexpr uint24_t skull = 0x000936;
    constexpr uint24_t ardu = 0x00093B;
}

namespace Names
{
    constexpr uint24_t jimbo = 0x000940;
}

  constexpr uint24_t teamList = 0x000946;
}

constexpr uint24_t testmap = 0x000AD5;
constexpr uint24_t Font = 0x000D15;
constexpr uint24_t fightMenu = 0x00144C;
constexpr uint24_t tilesheet = 0x00264E;
constexpr uint24_t npc = 0x003250;
constexpr uint24_t worldTiles = 0x003312;
constexpr uint24_t arduboyFont = 0x003914;
constexpr uint24_t battleMenu = 0x004B16;
constexpr uint24_t letters = 0x004F98;
constexpr uint24_t creatureSprites = 0x010F9A;
constexpr uint24_t maskedFont = 0x013F9C;
constexpr uint24_t characterSheet = 0x01CF9E;
constexpr uint24_t moveInfo = 0x01D300;
constexpr uint24_t creature6 = 0x01D5D2;
constexpr uint24_t creature10 = 0x01D66A;
constexpr uint24_t creature9 = 0x01D702;
constexpr uint24_t creature5 = 0x01D77C;
constexpr uint24_t creature16 = 0x01D8C8;
constexpr uint24_t creature26 = 0x01D9F6;
constexpr uint24_t creature27 = 0x01DAAC;
constexpr uint24_t test1 = 0x01DBDA;
constexpr uint24_t creature15 = 0x01DC72;
constexpr uint24_t creature23 = 0x01DDA0;
constexpr uint24_t creature3 = 0x01DDFC;
constexpr uint24_t creature24 = 0x01DF48;
constexpr uint24_t creature30 = 0x01DFA4;
constexpr uint24_t creature2 = 0x01E03C;
constexpr uint24_t creature25 = 0x01E1C4;
constexpr uint24_t creature28 = 0x01E2B6;
constexpr uint24_t creature7 = 0x01E38A;
constexpr uint24_t creature17 = 0x01E47C;
constexpr uint24_t creature4 = 0x01E58C;
constexpr uint24_t creature14 = 0x01E6D8;
constexpr uint24_t creature19 = 0x01E752;
constexpr uint24_t creature22 = 0x01E808;
constexpr uint24_t creature18 = 0x01E8A0;
constexpr uint24_t creature21 = 0x01E974;
constexpr uint24_t creature31 = 0x01E9EE;
constexpr uint24_t creature8 = 0x01EA68;
constexpr uint24_t creature0 = 0x01EBD2;
constexpr uint24_t creature20 = 0x01ED5A;
constexpr uint24_t creature13 = 0x01EDD4;
constexpr uint24_t creature29 = 0x01EE6C;
constexpr uint24_t creature1 = 0x01EF40;
constexpr uint24_t creature12 = 0x01F0AA;
constexpr uint24_t test2 = 0x01F142;
constexpr uint24_t creature11 = 0x01F1DA;
namespace CreatureNames
{
  constexpr uint24_t CreatureNames = 0x01F2CC;
}

namespace Test
{
  constexpr uint24_t Test = 0x01F32C;
}

constexpr uint24_t greyTest = 0x01F332;
