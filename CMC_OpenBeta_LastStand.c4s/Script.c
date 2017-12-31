/*-- Last Stand --*/

#strict 2
#include CSTD

static const FKDT_SuicideTime = 40; //Standardzeit bei Fake Death

static aAutomat, aLights, iLightsCounter;

//Dies ist ein CMC Beta Szenario.
//Ersteller: Henry / Michael14 / CMC Entwicklerteam

//GDEF-Spielziel

public func GDEF_CenterX()		{return(1000);}
public func GDEF_CenterY()		{return(805);}

public func GDEF_Waves()		{return(10);}
public func GDEF_MaxActive()		{return(25);}
public func GDEF_WaveCooldown(int iWave){return(20);}
public func GDEF_MonsterCount(int iWave)
{
  if(iWave == 1)
    return(10);
  else if(iWave == 2)
    return(20);
  else if(iWave == 3)
    return(16);
  else if(iWave == 4)
    return(16);
  else if(iWave == 4)
    return(16);
  else if(iWave == 5)
    return(16);
  else if(iWave == 6)
    return(14);
  else if(iWave == 7)
    return(45);
  else if(iWave == 8)
    return(35);
  else if(iWave == 9)
    return(35);
  else if(iWave == 10)
    return(45);
}

public func GDEF_MonsterSet(int iWave)
{
  if(iWave == 1)
    return([1]);
  else if(iWave == 2)
    return([1]);
  else if(iWave == 3)
    return([1,1,1,2]);
  else if(iWave == 4)
    return([1,2]);
  else if(iWave == 5)
    return([1,2,2]);
  else if(iWave == 6)
    return([2]);
  else if(iWave == 7)
    return([1,3,2]);
  else if(iWave == 8)
    return([1,2,2]);
  else if(iWave == 9)
    return([1,2,2,3]);
  else if(iWave == 10)
    return([1,2,2]);

/*  if(iWave == 1)
    return([1]);
  else if(iWave == 2)
    return([1]);
  else if(iWave == 3)
    return([1,1,2,1]);
  else if(iWave == 4)
    return([1,2,3]);
  else if(iWave == 5)
    return([1,2,3]);
  else if(iWave == 6)
    return([2,3]);
  else if(iWave == 7)
    return([1,3,4]);
  else if(iWave == 8)
    return([1,2,3,4]);
  else if(iWave == 9)
    return([1,3,4,5]);
  else if(iWave == 10)
    return([1,2,2,3,4,5]);*/
}

public func GDEF_MonsterType1()
{
  var x,y; MonsterSpawn(x,y);
  var m = CreateObject(H2HC,x,y,-1);
  m->SetCmd(true,"MoveTo",0,GDEF_CenterX(),GDEF_CenterY(),0,0,0,true);
  return(m);
}

public func GDEF_MonsterType2()
{
  var x,y; MonsterSpawn(x,y);
  var m = CreateObject(H2ZB,x,y,-1);
  m->SetCmd(true,"MoveTo",0,GDEF_CenterX(),GDEF_CenterY(),0,0,0,true);
  return(m);
}

public func GDEF_MonsterType3()
{
  var x,y; MonsterSpawn(x,y);
  var m = CreateObject(H2FH,x,y,-1);
  m->SetCmd(true,"MoveTo",0,GDEF_CenterX(),GDEF_CenterY(),0,0,0,true);
  return(m);
}

public func GDEF_MonsterType4()
{
  var x,y; MonsterSpawn(x,y);
  var m = CreateObject(H2PH,x,y,-1);
  m->SetCmd(true,"MoveTo",0,GDEF_CenterX(),GDEF_CenterY(),0,0,0,true);
  return(m);
}

public func GDEF_MonsterType5()
{
  var x,y; MonsterSpawn(x,y);
  var m = CreateObject(H2MH,x,y,-1);
  m->SetCmd(true,"MoveTo",0,GDEF_CenterX(),GDEF_CenterY(),0,0,0,true);
  return(m);
}

public func MonsterSpawn(int & iX, int & iY)
{
  var rand = Random(4);
  if(!rand)
    { iX = 10; iY = 840; }
  if(!--rand)
    { iX = 370; iY = 360; }
  if(!--rand)
    { iX = 1700; iY = 250; }
  if(!--rand)
    { iX = 2010; iY = 840; }
}


/* Initialisierung */

public func Initialize()
{
  _inherited();

  //Starttitel und Musikliste zusammenstellen
  SetPlayList("On a Razor-Blade.ogg;Origin of Silence.ogg;Quick Charge.ogg;Reflective Motion.ogg;CMC_Base Groove.ogg;CMC_Firehawk.ogg;CMC_Friendly Unit.ogg;CMC_Getaway.ogg;CMC_Deep Universe.ogg;CMC_Eurocorps.ogg;CMC_Moving Squad.ogg;CMC_Offensive.ogg;CMC_Rock Go On.ogg;CMC_Showtime.ogg;CMC_Slow Motion.ogg;CMC_Striking Force.ogg;CMC_No Good.ogg;CMC_Obsession.ogg;CMC_Your Eyes.ogg");
  Music("Reflective Motion.ogg");

  //Einrichtung plazieren
  CreateInterior();
  //Ausrüstung plazieren
  CreateEquipment();
  //Dekoration plazieren
  CreateDecoration();

  return 1;
}

/* Plazierungslisten */

static spawn_gate;

func CreateInterior()
{
  Log("$CreatingInterior$");

  //Rampen
  DrawMaterialQuad("Wall-Concrete3",1031,860,1031,850,1061,860,1031,860,true);
  DrawMaterialQuad("Wall-Concrete3",970,860,970,850,940,860,970,860,true);

  //Aufzüge
  CreateObject(LFTP, 45, 1038, -1);
  CreateObject(LFTP, 985, 1038, -1);
  CreateObject(LFTP, 1765, 566, -1);

  //Leitern
  CreateObject(LADR, 271, 298, -1)->Set(7);
  CreateObject(LADR, 561, 1037, -1)->Set(7);
  CreateObject(LADR, 695, 980, -1)->Set(14);
  CreateObject(LADR, 930, 808, -1)->Set(5);
  CreateObject(LADR, 1415, 1019, -1)->Set(19);

  //Türen, Tore und Luken
  spawn_gate = CreateObject(GAT1, 1055, 795, -1);
  CreateObject(GAT2, 635, 915, -1);
  CastPXS ("Water",300,10,635,915);

  //Bodenluken
  var tmp = CreateObject(HA4K, 1410, 861, -1);
  tmp->Lock();
  tmp->SetMaxDamage(-1);
  tmp = CreateObject(HA4K, 690, 861, -1);
  tmp->Lock();
  tmp->SetMaxDamage(-1);
  tmp = CreateObject(HA4K, 270, 251, -1);
  tmp->Lock();
  tmp->SetMaxDamage(-1);
  tmp = CreateObject(SLDR, 365, 690, -1);
  tmp->Lock();
  tmp->SetMaxDamage(-1);
  CreateObject(HA4K, 930, 763, -1);

  //Große Bodenluken
  CreateObject(H24K, 695, 868, -1);
  CreateObject(H24K, 1415, 868, -1);

  //Stahltüren
  CreateObject(STDR, 254, 691, -1);
  CreateObject(SLDR, 1335, 1090, -1);
  CreateObject(LBDR, 682, 810, -1)->DoDamage(500);

  /*
  tmp = CreateObject(SLDR, 915, 860, -1);
  tmp->Lock();
  tmp->Open();
  CreateObject(SWTH, 930, 860, -1)->Set(tmp);

  tmp = CreateObject(SLDR, 1085, 860, -1);
  tmp->Lock();
  tmp->Open();
  CreateObject(SWTH, 1072, 860, -1)->Set(tmp);
  */

  //Gerüste
  CreateObject(SFFG, 290, 860, -1)->Set(5);
  CreateObject(SFFG, 350, 860, -1)->Set(5);
  CreateObject(SFFG, 410, 860, -1)->Set(5);
  CreateObject(SFFG, 1630, 860, -1)->Set(5);
  CreateObject(SFFG, 1690, 860, -1)->Set(5);
  CreateObject(SFFG, 1750, 860, -1)->Set(5);

  //Phosphorfässer
  CreateObject(HBRL, 625, 990, -1);
  CreateObject(HBRL, 1430, 1090, -1);
  CreateObject(HBRL, 1460, 1090, -1);
  CreateObject(HBRL, 1490, 1090, -1);

  //Gasflaschen
  CreateObject(GSBL, 1215, 1090, -1);
  CreateObject(GSBL, 1420, 1030, -1);

  //Sonstiges
  //CreateObject(DEB1, 1261, 862, -1);
  CreateObject(LCKR, 1305, 809, -1)->SetR(-41);
  CreateObject(CHAR, 1398, 809, -1);
  CreateObject(OTBL, 1405, 809, -1);
  CreateObject(OCHR, 1295, 1089, -1);
  CreateObject(OCHR, 1257, 1089, -1);
  CreateObject(CCP2, 1278, 1090, -1);
  CreateObject(CCP2, 1241, 1090, -1);
  CreateObject(MPPJ, 1163, 1089, -1);

  //Grenzen
  CreateObject(BRDR, 250, 0, -1)->Set(0);
  CreateObject(BRDR, 1780, 0, -1)->Set(1);

  //Sounds

  //Hallen
  CreateObject(SE4K, 450, 800, -1)->Set("Interior*.ogg",665,105);
  CreateObject(SE4K, 1580, 800, -1)->Set("Interior*.ogg",665,105);

  //Erdrutsche
  CreateObject(SE4K, 300, 800, -1)->Set("FallingDirt*.ogg",775,250);
  CreateObject(SE4K, 1730, 800, -1)->Set("FallingDirt*.ogg",775,250);

  //Zombies
  CreateObject(SE4K,10,10,-1)->Set("BattleLoop*.ogg",35*5,35*2,-1);
  CreateObject(SE4K,10,10,-1)->Set("DistantZombie*.ogg",35*20,35*5,-1);

  return(1);
}

func CreateEquipment()
{
  Log("$CreatingEquipment$");

  //Waffenautomat

  //Dragninautomat
  CreateObject(DGND, 1435, 810, -1);
}

func CreateDecoration()
{
  Log("$CreatingDecoration$");

  //Straßenlichter
  CreateObject(SLGH, 445, 860, -1);
  CreateObject(SLGH, 615, 860, -1);
  CreateObject(SLGH, 1480, 860, -1);
  CreateObject(SLGH, 1595, 860, -1);

  //Wandlampen
  CreateObject(BLGH, 710, 800, -1);
  CreateObject(BLGH, 710, 850, -1);
  CreateObject(BLGH, 955, 845, -1);
  CreateObject(BLGH, 1045, 845, -1);
  CreateObject(BLGH, 1380, 850, -1);

  //Lüftungsgitter
  CreateObject(ENGT, 740, 860, -1);
  CreateObject(ENGT, 1320, 860, -1);

  //Notausgangslichter
  CreateObject(ETLT, 330, 820, -1);
  CreateObject(ETLT, 1700, 820, -1);

  //Zäune
  CreateObject(FENC, 30, 860, -1)->Set(2);
  CreateObject(FENC, 90, 860, -1)->Set(2);
  CreateObject(FENC, 150, 860, -1);
  CreateObject(FENC, 210, 860, -1)->Set(2);
  CreateObject(FENC, 1820, 860, -1)->Set(2);
  CreateObject(FENC, 1880, 860, -1);
  CreateObject(FENC, 1940, 860, -1)->Set(2);
  CreateObject(FENC, 2000, 860, -1)->Set(2);

  //Monitore
  CreateObject(MNI2, 1070, 1078, -1);
  CreateObject(MNI2, 1410, 799, -1);

  //Topfpflanzen
  CreateObject(PLT3, 660, 860, -1);
  CreateObject(PLT3, 1350, 860, -1);
  Schedule("FindObject(PCMK)->CreateObject(_BAS)->CreateObject(ENAP)",50);
}

public func TestTravel()
{
	if (FindObject(_BAS))
	{
		FindObject(_BAS)->Travel("Dunkelfels", 576, 817);
	}
}

/* Lichtverwaltung */

func LightsOff()
{
  aLights = FindObjects(Find_Func("IsLamp"), Sort_Func("Lamp_SortX"));
  iLightsCounter = 0;
  if(aLights[iLightsCounter])
    Schedule("LightsOffHelper();", 50);
  else
    return -1;
}

global func Lamp_SortX()
{
  return GetX();
}

func LightsOffHelper()
{
  while(!aLights[iLightsCounter])
    if(iLightsCounter >= GetLength(aLights) - 1)
      return;
    else
      iLightsCounter++;

  aLights[iLightsCounter]->~TurnOff();
  aLights[iLightsCounter] = 0;

  Schedule("LightsOffHelper();", 50);
}

public func GetNextMap()
{
	var maps = [
		["AtlanticCrisis", 3130, 398]
	];
	var map = maps[Random(GetLength(maps))];
	while (map[0] == current_section)
	{
		map = maps[Random(GetLength(maps))];
	}
	return map;
}

public func SectionLoaded(string section)
{
	if (section == "AtlanticCrisis")
	{
		  //Rampen
  DrawMaterialQuad("Wall-PlateBlue",1391,510,1361,500,1361,510,1376,510,true);
  DrawMaterialQuad("Wall-Plate",1421,520,1391,510,1391,520,1406,520,true);
  DrawMaterialQuad("Wall-PlateBlue",1451,530,1421,520,1421,530,1436,530,true);
  DrawMaterialQuad("Wall-Plate",1661,540,1631,530,1631,540,1646,540,true);

  DrawMaterialQuad("Wall-Unknown1",1300,640,1390,610,1390,640,1300,640,true);
  DrawMaterialQuad("BackWall-Stripes",1390,610,1420,600,1420,610,1390,610,true);
  DrawMaterialQuad("Wall-Stripes",1420,600,1420,585,1435,585,1430,600,true);

  DrawMaterialQuad("Wall-Unknown1",1631,619,1660,619,1660,620,1631,620,1);
  DrawMaterialQuad("Wall-Unknown1",1691,630,1661,620,1661,630,1676,630,true);
  DrawMaterialQuad("Wall-Unknown1",1721,640,1691,630,1691,640,1706,640,true);

  DrawMaterialQuad("Wall-Stripes",2280,520,2290,510,2290,520,2280,520,true);
  DrawMaterialQuad("Wall-Stripes",2380,510,2390,520,2380,520,2380,510,true);

  DrawMaterialQuad("Wall-Stripes",3620,520,3630,510,3630,520,3620,520,true);
  DrawMaterialQuad("Wall-Stripes",3720,510,3730,520,3720,520,3720,510,true);

  DrawMaterialQuad("Wall-Plate",4350,540,4380,530,4380,540,4365,540,true);
  DrawMaterialQuad("Wall-PlateRed",4560,530,4590,520,4590,530,4575,530,true);
  DrawMaterialQuad("Wall-Plate",4590,520,4620,510,4620,520,4605,520,true);
  DrawMaterialQuad("Wall-PlateRed",4620,510,4650,500,4650,510,4635,510,true);

  DrawMaterialQuad("Wall-Unknown1",4290,640,4320,630,4320,640,4305,640,true);
  DrawMaterialQuad("Wall-Unknown1",4320,630,4350,620,4350,630,4335,630,true);
  DrawMaterialQuad("Wall-Unknown1",4351,619,4379,619,4379,620,4351,620,1);

  DrawMaterialQuad("Wall-Stripes",4575,585,4580,600,4590,600,4590,585,true);
  DrawMaterialQuad("BackWall-Stripes",4590,600,4620,610,4590,610,4590,600,true);
  DrawMaterialQuad("Wall-Unknown1",4620,610,4710,640,4620,640,4620,610,true);

  //Leitern
  CreateObject(LADR, 1275, 596, -1)->Set(11);
  CreateObject(LADR, 1550, 586, -1)->Set(6);
  CreateObject(LADR, 1575, 504, -1)->Set(12);

  CreateObject(LADR, 2200, 600, -1)->Set(9);
  CreateObject(LADR, 2400, 600, -1)->Set(9);

  CreateObject(LADR, 2765, 602, -1)->Set(8);
  CreateObject(LADR, 2870, 602, -1)->Set(8);
  CreateObject(LADR, 2910, 602, -1)->Set(8);

  CreateObject(LADR, 2990, 532, -1)->Set(8);

  CreateObject(LADR, 3070, 602, -1)->Set(8);
  CreateObject(LADR, 3110, 602, -1)->Set(8);
  CreateObject(LADR, 3215, 602, -1)->Set(8);

  CreateObject(LADR, 3610, 600, -1)->Set(9);
  CreateObject(LADR, 3810, 600, -1)->Set(9);

  CreateObject(LADR, 4435, 504, -1)->Set(12);
  CreateObject(LADR, 4460, 586, -1)->Set(6);
  CreateObject(LADR, 4738, 596, -1)->Set(11);

  //Bodenluken
  CreateObject(HA4K, 1410, 613, -1);
  CreateObject(HA4K, 1550, 533, -1);

  CreateObject(HA4K, 2200, 523, -1);
  CreateObject(HA4K, 2400, 523, -1);

  CreateObject(HA4K, 2870, 533, -1);
  CreateObject(HA4K, 2910, 533, -1);

  CreateObject(HA4K, 2990, 463, -1);

  CreateObject(HA4K, 3070, 533, -1);
  CreateObject(HA4K, 3110, 533, -1);

  CreateObject(HA4K, 3610, 523, -1);
  CreateObject(HA4K, 3810, 523, -1);

  CreateObject(HA4K, 4460, 533, -1);
  CreateObject(HA4K, 4600, 613, -1);

  //Gerüste
  CreateObject(SFFG, 2150, 470, -1)->Set(5);
  CreateObject(SFFG, 2150, 520, -1)->Set(4);

  CreateObject(SFFG, 3860, 470, -1)->Set(5);
  CreateObject(SFFG, 3860, 520, -1)->Set(4);

  //Schutztüren
  CreateObject(GDDR, 2795, 530, -1);
  CreateObject(GDDR, 2875, 460, -1);
  CreateObject(GDDR, 3105, 460, -1);
  CreateObject(GDDR, 3185, 530, -1);

  //Kisten
  CreateObject(WCR2, 2910, 460, -1)->AutoRespawn();
  CreateObject(WCR2, 3070, 460, -1)->AutoRespawn();

  //Metallkisten
  CreateObject(MWCR, 2940, 530, -1)->AutoRespawn();
  CreateObject(MWCR, 2960, 530, -1)->AutoRespawn();

  //Verbandskisten
  CreateObject(BECR, 2120, 470, -1)->AutoRespawn();
  CreateObject(BECR, 3890, 470, -1)->AutoRespawn();

  //Benzinfässer
  CreateObject(PBRL, 1290, 500, -1)->AutoRespawn();
  CreateObject(PBRL, 1580, 530, -1)->AutoRespawn();
  CreateObject(PBRL, 1580, 600, -1)->AutoRespawn();

  CreateObject(PBRL, 2160, 520, -1)->AutoRespawn();

  CreateObject(PBRL, 2940, 460, -1)->AutoRespawn();
  CreateObject(PBRL, 3020, 380, -1)->AutoRespawn();

  CreateObject(PBRL, 3850, 520, -1)->AutoRespawn();

  CreateObject(PBRL, 4435, 530, -1)->AutoRespawn();
  CreateObject(PBRL, 4435, 600, -1)->AutoRespawn();
  CreateObject(PBRL, 4720, 500, -1)->AutoRespawn();

  //Phosphorfässer
  CreateObject(HBRL, 2430, 520, -1)->AutoRespawn();
  CreateObject(HBRL, 3580, 520, -1)->AutoRespawn();

  //Giftfässer
  CreateObject(TBRL, 2810, 530, -1)->AutoRespawn();
  CreateObject(TBRL, 2830, 530, -1)->AutoRespawn();

  //Explosivfässer
  CreateObject(XBRL, 3110, 410, -1)->AutoRespawn();
  CreateObject(XBRL, 3140, 530, -1)->AutoRespawn();

  //Gasflasche
  CreateObject(GSBL, 3160, 530, -1)->AutoRespawn();

  //Explosivkiste
  CreateObject(XWCR, 2815, 410, -1)->AutoRespawn();

  //Stahlbrücken
  CreateObject(_HBR, 2064, 532, -1);
  CreateObject(_HBR, 2335, 522, -1)->SwitchMode();
  CreateObject(_HBR, 2487, 532, -1);
  CreateObject(_HBR, 2734, 472, -1);
  CreateObject(_HBR, 3247, 472, -1);
  CreateObject(_HBR, 3524, 532, -1);
  CreateObject(_HBR, 3675, 522, -1)->SwitchMode();
  CreateObject(_HBR, 3947, 532, -1);

  //Haie
  CreateObject(SHRK, 500, 680, -1)->AutoRespawn();
  CreateObject(SHRK, 600, 680, -1)->AutoRespawn();
  CreateObject(SHRK, 700, 680, -1)->AutoRespawn();
  CreateObject(SHRK, 800, 680, -1)->AutoRespawn();

  CreateObject(SHRK, 2270, 680, -1)->AutoRespawn();
  CreateObject(SHRK, 2370, 680, -1)->AutoRespawn();
  CreateObject(SHRK, 2470, 680, -1)->AutoRespawn();
  CreateObject(SHRK, 2570, 680, -1)->AutoRespawn();

  CreateObject(SHRK, 3440, 680, -1)->AutoRespawn();
  CreateObject(SHRK, 3540, 680, -1)->AutoRespawn();
  CreateObject(SHRK, 3640, 680, -1)->AutoRespawn();
  CreateObject(SHRK, 3740, 680, -1)->AutoRespawn();

  CreateObject(SHRK, 5100, 680, -1)->AutoRespawn();
  CreateObject(SHRK, 5200, 680, -1)->AutoRespawn();
  CreateObject(SHRK, 5300, 680, -1)->AutoRespawn();
  CreateObject(SHRK, 5400, 680, -1)->AutoRespawn();

  //Sandsackbarrieren
  CreateObject(SBBA, 1705, 540, -1)->Right();
  CreateObject(SBBA, 2115, 520, -1);
  CreateObject(SBBA, 2306, 510, -1)->Right();
  CreateObject(SBBA, 3704, 510, -1);
  CreateObject(SBBA, 3895, 520, -1)->Right();
  CreateObject(SBBA, 4305, 540, -1);

  //Explosivtank
  CreateObject(XTNK, 3140, 410, -1)->AutoRespawn();

  //Phosphortanks
  CreateObject(PTNK, 1600, 530, -1)->AutoRespawn();
  CreateObject(PTNK, 2430, 520, -1)->AutoRespawn();
  CreateObject(PTNK, 3580, 520, -1)->AutoRespawn();
  CreateObject(PTNK, 4410, 530, -1)->AutoRespawn();

  //Seegras und Muscheln entfernen
  for(var obj in FindObjects(Find_Or(Find_ID(SWD1), Find_ID(SWD2), Find_ID(SHEL)), Find_InRect(1280, 370, 3450, 280)))
    RemoveObject(obj);

  //Wasseroberfläche ebnen
  DrawMaterialQuad("Water",1631,610,4379,610,4379,615,1631,615,1);

  //Grenzen
  CreateObject(BRDR, 1170, 0, -1)->Set(0);
  CreateObject(BRDR, 4835, 0, -1)->Set(1);

  //Soundkulisse

  //Möven
  CreateObject(SE4K, 1080, 550, -1)->Set("Seagulls*.ogg",1000,500, 10,50);
  CreateObject(SE4K, 2300, 380, -1)->Set("Seagulls*.ogg",1000,500, 10,50);
  CreateObject(SE4K, 3810, 380, -1)->Set("Seagulls*.ogg",1000,500, 10,50);
  CreateObject(SE4K, 4930, 550, -1)->Set("Seagulls*.ogg",1000,500, 10,50);

  //Wellen
  CreateObject(SE4K, 500, 650, -1)->Set("Wave*.ogg",100,50, 75);
  CreateObject(SE4K, 1000, 650, -1)->Set("Wave*.ogg",100,50, 75);
  CreateObject(SE4K, 1920, 650, -1)->Set("Wave*.ogg",100,50, 75);
  CreateObject(SE4K, 2500, 650, -1)->Set("Wave*.ogg",100,50, 75);
  CreateObject(SE4K, 3510, 650, -1)->Set("Wave*.ogg",100,50, 75);
  CreateObject(SE4K, 4090, 650, -1)->Set("Wave*.ogg",100,50, 75);
  CreateObject(SE4K, 5410, 650, -1)->Set("Wave*.ogg",100,50, 75);
  CreateObject(SE4K, 5510, 650, -1)->Set("Wave*.ogg",100,50, 75);

  //Lautsprecher
  CreateObject(SE4K, 2990, 330, -1)->Set("Announce*.ogg",3000,500, 75);

  //Wind
  CreateObject(SE4K, 1540, 300, -1)->Set("WindSound*.ogg",300,100, 50);
  CreateObject(SE4K, 2990, 280, -1)->Set("WindSound*.ogg",300,100, 50);
  CreateObject(SE4K, 4460, 300, -1)->Set("WindSound*.ogg",300,100, 50);

  //Innenbereich
  CreateObject(SE4K, 1500, 550, -1)->Set("Interior*.ogg",700,100, 75);
  CreateObject(SE4K, 2990, 500, -1)->Set("Interior*.ogg",700,100, 75);
  CreateObject(SE4K, 4510, 550, -1)->Set("Interior*.ogg",700,100, 75);
  CreateObject(SE4K, 1500, 550, -1)->Set("InteriorMetal*.ogg",1000,300, 75);
  CreateObject(SE4K, 2990, 500, -1)->Set("InteriorMetal*.ogg",1000,300, 75);
  CreateObject(SE4K, 4510, 550, -1)->Set("InteriorMetal*.ogg",1000,300, 75);
  
    //Versorgungskisten (Kugeln)
  var crate = CreateObject(AMCT, 1680, 400, -1);
  crate->Set(ABOX);
  crate = CreateObject(AMCT, 4330, 400, -1);
  crate->Set(ABOX);

  //Versorgungskiste (Gewehrgranaten)
  crate = CreateObject(AMCT, 3020, 460, -1);
  crate->Set(GBOX);

  //Raketen
  PlaceSpawnpoint(MBOX, 2150, 515);
  PlaceSpawnpoint(MBOX, 3860, 515);

  //Geschützstellungen
  CreateObject(GNET, 1465, 530, -1)->Set(LCAC);
  CreateObject(GNET, 4545, 530, -1)->Set(LCAC);

  //Artilleriebatterien
  CreateObject(ATBY,2231,520,-1)->SetRotation(20);
  CreateObject(ATBY,3775,520,-1)->SetRotation(-20);

  //Patrouillenboote
  SetupVehicleSpawn([PBOT],DIR_Right,CreateObject(VSPW,1480,600,-1),50*21);
  SetupVehicleSpawn([PBOT],DIR_Right,CreateObject(VSPW,1705,609,-1),50*21);
  SetupVehicleSpawn([PBOT],DIR_Left,CreateObject(VSPW,2990,571,-1),50*21);
  SetupVehicleSpawn([PBOT],DIR_Left,CreateObject(VSPW,4310,609,-1),50*21);
  SetupVehicleSpawn([PBOT],DIR_Left,CreateObject(VSPW,4530,600,-1),50*21);

  //Automaten
  var store = CreateObject(WPVM,1500, 530,-1);
  store->AddWare(C4PA,10);
  store->AddWare(FAPK,10);
  store->AddWare(CDBT,10);
  store->AddWare(BWTH,10);
  store->AddWare(RSHL,10);
  store->AddWare(ATWN,20);
  store->AddWare(FGRN,20);
  store->AddWare(FRAG,20);
  store->AddWare(PGRN,20);
  store->AddWare(SGRN,20);
  store->AddWare(STUN,20);
  store->AddWare(SRBL,20);
  store = CreateObject(WPVM,3025, 530,-1);
  store->AddWare(C4PA,10);
  store->AddWare(FAPK,10);
  store->AddWare(CDBT,10);
  store->AddWare(BWTH,10);
  store->AddWare(RSHL,10);
  store->AddWare(ATWN,20);
  store->AddWare(FGRN,20);
  store->AddWare(FRAG,20);
  store->AddWare(PGRN,20);
  store->AddWare(SGRN,20);
  store->AddWare(STUN,20);
  store->AddWare(SRBL,20);
  store = CreateObject(WPVM,4500, 530,-1);
  store->AddWare(C4PA,10);
  store->AddWare(FAPK,10);
  store->AddWare(CDBT,10);
  store->AddWare(BWTH,10);
  store->AddWare(RSHL,10);
  store->AddWare(ATWN,20);
  store->AddWare(FGRN,20);
  store->AddWare(FRAG,20);
  store->AddWare(PGRN,20);
  store->AddWare(SGRN,20);
  store->AddWare(STUN,20);
  store->AddWare(SRBL,20);
  
    //Orientierungslichter
  CreateObject(OLGH, 1655, 400, -1)->Set(7, 10, 1, 1, 10);
  CreateObject(OLGH, 2410, 420, -1)->Set(35, 5, 1, 1, 20);
  CreateObject(OLGH, 2990, 380, -1)->Set(4, 10, 1, 1, 20);
  CreateObject(OLGH, 3600, 420, -1)->Set(35, 5, 1, 1, 20);
  CreateObject(OLGH, 4355, 400, -1)->Set(7, 10, 1, 1, 10);

  //Straßenlichter
  CreateObject(SLGH, 1393, 511, -1);
  CreateObject(SLGH, 2780, 460, -1);
  CreateObject(SLGH, 3200, 460, -1);
  CreateObject(SLGH, 4617, 511, -1);

  //Automaten
  CreateObject(VGMN, 2840, 530, -1);
  CreateObject(VGMN, 3140, 530, -1)->Set(3);

  //Büsche
  CreateObject(BSH2, 2770, 570, -1);
  CreateObject(BSH2, 3180, 425, -1);

  //Bojen
  CreateObject(BUOY, 1180, 633, -1);
  CreateObject(BUOY, 2370, 633, -1);

  CreateObject(BUOY, 3840, 633, -1);
  CreateObject(BUOY, 4830, 633, -1);

  //Satellitenschüssel
  CreateObject(SADH, 2840, 410, -1);

  //Radare
  CreateObject(RADR, 1610, 400, -1);
  CreateObject(RADR, 4400, 400, -1);

  //Flaschen
  CreateObject(BOTL, 2940, 512, -1);
  CreateObject(BOTL, 2945, 512, -1);

  //Jetwrack
  CreateObject(_JW1, 1110, 700, -1);
  CreateObject(_JW2, 1275, 740, -1);

  //Kaputte U-Boote
  CreateObject(SUBB, 3805, 780, -1);
  CreateObject(SUBB, 7200, 800, -1);

  //Kaputte Boote
  CreateObject(SLBB, 110, 740, -1);
  CreateObject(SLBB, 5385, 760, -1);

  //Ventillatoren
  CreateObject(VENT, 1380, 590, -1)->SetCon(30);
  CreateObject(VEN3, 2410, 500, -1)->SetCon(30);
  CreateObject(VEN3, 3600, 500, -1)->SetCon(30);
  CreateObject(VENT, 4630, 590, -1)->SetCon(30);

  //Feuerlöscher
  CreateObject(FIE2, 1530, 595, -1);
  CreateObject(FIE2, 2970, 455, -1);
  CreateObject(FIE2, 4480, 595, -1);

  //Geländer
  CreateObject(RAI1, 1280, 500, -1)->SetRail([1,1,1,1]);
  CreateObject(RAI1, 1450, 530, -1)->SetRail([1,1,1,1,1,1,1,1,1,1]);
  CreateObject(RAI1, 1500, 600, -1)->SetRail([1,1,1,1,1]);
  CreateObject(RAI1, 2125, 520, -1)->SetRail([1,1,1,1,1,1,1,1]);
  CreateObject(RAI1, 2880, 460, -1)->SetRail([1,1,1,1,1,1,1,1,1,1,1,1]);
  CreateObject(RAI1, 3735, 520, -1)->SetRail([1,1,1,1,1,1,1,1]);
  CreateObject(RAI1, 4380, 530, -1)->SetRail([1,1,1,1,1,1,1,1,1,1]);
  CreateObject(RAI1, 4410, 600, -1)->SetRail([1,1,1,1,1]);
  CreateObject(RAI1, 4650, 500, -1)->SetRail([1,1,1,1]);

  //Schilder
  CreateObject(ESGN, 1515, 590, -1);
  CreateObject(ESGN, 2970, 440, -1);
  CreateObject(ESGN, 4495, 590, -1);

  //Lüftungsgitter
  CreateObject(ENGT, 2890, 530, -1);
  CreateObject(ENGT, 3090, 530, -1);

  //Bildschirme
  CreateObject(SCR1, 1665, 595, -1);
  CreateObject(SCA1, 2825, 490, -1)->SetAction("Grenade");
  CreateObject(SCA1, 3155, 490, -1)->SetAction("Medic");
  CreateObject(SCR1, 4330, 595, -1);
  }
}

public func OnClassSelection(object pClonk)
{
  pClonk->CreateObject(_BAS);
}

public func RelaunchPosition(& iX, & iY, int iTeam)
{
  iX = 1055;
  iY = 795;
}

static current_section;

global func SetSection(array section)
{
	current_section = section;
}

func Script0()
{
	ScriptGo(false);
	var base;
	if (!(base = FindObject2(Find_ID(_BAS)))) return;
	var objects = CreateHash();
	var base_x = current_section[1], base_y = current_section[2];
	// Save
	for (var obj in FindObjects(Find_Or(Find_OCF(OCF_CrewMember), Find_Category(C4D_Object)), Find_Or(base->Find_InRect(-89, -29, 180, 109), Find_ID(ABAG)), Find_Not(Find_ID(_BAS))))
	{
		if (obj)
		{
			HashPut(objects, obj, [obj->GetX() - base->GetX(), obj->GetY() - base->GetY()]);
			obj->SetPosition(0, 0);
			obj->SetXDir(0);
			obj->SetYDir(0);
			if (GetOCF(obj) & OCF_CrewMember)
			{
				
			}
			obj->SetObjectStatus(C4OS_INACTIVE);
		}
	}
	
	var rules = FindObjects(Find_Category(C4D_Rule));
	for (var rule in rules)
	{
		if (rule)
		{
			HashPut(objects, rule, [0, 0]);
			rule->SetPosition(0,0);
			rule->SetObjectStatus(C4OS_INACTIVE);
		}
	}
	
	base->SetPosition(0, 0);
	base->SetObjectStatus(C4OS_INACTIVE);
	
	// DANGER
	LoadScenarioSection(current_section[0] || "main");
	// DANGER
	
	GameCallEx("SectionLoaded", current_section[0]);
	
	// Load
	base->SetObjectStatus(C4OS_NORMAL);
	base->SetPosition(base_x, base_y);
	base->PlaceBase();
	
	var iter = HashIter(objects);
	var node;
	while (node = HashIterNext(iter))
	{
		node[0]->SetObjectStatus(C4OS_NORMAL);
		var x = base_x + node[1][0], y = base_y + node[1][1];
		node[0]->SetPosition(x, y);
		//ScheduleCall(node[0], "SetPosition", x, y);
	}
	objects = CreateHash();
}

//Dies ist ein CMC Beta Szenario.
//Ersteller: Henry / Michael14 / CMC Entwicklerteam
