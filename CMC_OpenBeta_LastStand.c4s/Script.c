/*-- Last Stand --*/

#strict 2
#include CSTD

static const FKDT_SuicideTime = 40; //Standardzeit bei Fake Death

static aAutomat, aLights, iLightsCounter;

/* Initialisierung */

public func Initialize()
{
  _inherited();
  sections = [];
  for (var i = 0, def; def = GetDefinition(i); i++)
  {
    if (def != _SEC && def->~IsSection())
    {
      sections[GetLength(sections)] = def;
    }
  }
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
static old_section;
static sections;

func Script0()
{
	ScriptGo(false);
	var base;
	if (!(base = FindObject2(Find_ID(_BAS)))) return;
	var objects = CreateHash();
	var sect = sections[Random(GetLength(sections))];
	while (old_section && sect == old_section)
	{
		sect = sections[Random(GetLength(sections))];
	}
  var coords = sect->GetCoordinates();
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
	if (current_section)
	{
		Log("%v", current_section);
		old_section = current_section->GetID();
	}
		
	// DANGER
	LoadScenarioSection(GetName(0,sect) || "main");
	// DANGER
	
	current_section = CreateObject(sect);
	
	// Load
	base->SetObjectStatus(C4OS_NORMAL);
	base->SetPosition(coords[0], coords[1]);
	base->PlaceBase();
	
	var iter = HashIter(objects);
	var node;
	while (node = HashIterNext(iter))
	{
		node[0]->SetObjectStatus(C4OS_NORMAL);
		var x = coords[0] + node[1][0], y = coords[1] + node[1][1];
		node[0]->SetPosition(x, y);
		//ScheduleCall(node[0], "SetPosition", x, y);
	}
	objects = CreateHash();
}

//Dies ist ein CMC Beta Szenario.
//Ersteller: Henry / Michael14 / CMC Entwicklerteam
