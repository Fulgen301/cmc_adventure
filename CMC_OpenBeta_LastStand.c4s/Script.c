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

  //Zeitverzögerter Stromausfall
  Schedule("GameCall(\"Blackout\")", RandomX(3000,6000));

  ScriptGo(true);

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
  CreateObject(LTBL, 1070, 1089, -1);
  CreateObject(CCP2, 1278, 1090, -1);
  CreateObject(CCP2, 1241, 1090, -1);
  CreateObject(MPPJ, 1163, 1089, -1);
  CreateObject(SCR3, 1072, 1049, -1);
  CreateObject(MVNT, 1000, 790, -1)->SetCon(30);

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
  aAutomat = CreateObject(WPVM, 1000, 850, -1);
  SetUpStore(aAutomat);

  //Dragninautomat
  CreateObject(DGND, 1435, 810, -1);

  //Munitionskisten
  CreateAmmoCrate(385,860);
  CreateAmmoCrate(730,810);
  CreateAmmoCrate(770,860);
  CreateAmmoCrate(1300,860);
  CreateAmmoCrate(1330,810);
  CreateAmmoCrate(1665,860);
}

func CreateDecoration()
{
  Log("$CreatingDecoration$");

  //Denkmal
  CreateObject(MUMT, 1000, 760, -1);

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

  //Feuerlöscher
  CreateObject(FIE2, 675, 855, -1);
  CreateObject(FIE2, 1035, 805, -1);
  CreateObject(FIE2, 1435, 855, -1);

  //Monitore
  CreateObject(MNI2, 1070, 1078, -1);
  CreateObject(MNI2, 1410, 799, -1);

  //Topfpflanzen
  CreateObject(PLT3, 660, 860, -1);
  CreateObject(PLT3, 1350, 860, -1);
}

public func SetUpStore(aAutomat)
{
  //Munition
  aAutomat->AddWare(ABOX,-1);
  aAutomat->AddWare(GBOX,-1);
  aAutomat->AddWare(MIAP,-1);

  //Ausrüstung
  aAutomat->AddWare(FAPK,3);
  aAutomat->AddWare(CDBT,3);

  //Handgranaten
  aAutomat->AddWare(FGRN,10);
  aAutomat->AddWare(FRAG,10);
  aAutomat->AddWare(PGRN,10);

  //Ausrüstung
  aAutomat->AddWare(C4PA,10);
  aAutomat->AddWare(DGNN,10);
  aAutomat->AddWare(WATC,10);

  //Waffen
  aAutomat->AddWare(RVLR,5);
  aAutomat->AddWare(PSTL,0);
  aAutomat->AddWare(SMGN,3);
  aAutomat->AddWare(ASTR,3);
  aAutomat->AddWare(PPGN,3);
  aAutomat->AddWare(MNGN,3);
  aAutomat->AddWare(SGST,3);
  aAutomat->AddWare(RTLR,3);
  aAutomat->AddWare(ATWN,10);
}

public func CMC(pStore)
{
  Log("Sonderangebot! Jetzt zuschlagen omg!1!");
  Sound("Cheer.ogg");
  Sound("Cash");
  aAutomat->AddWare(ACCN,-1); 
  aAutomat->AddWare(MISA,-1); 
}

public func TestTravel()
{
	if (FindObject(_BAS))
	{
		FindObject(_BAS)->Travel("Dunkelfels", 576, 817);
	}
}

/* Stromausfall */

func Blackout()
{
  //Dunkelheit erhöhen
  if(GetDarkness() < 2)
   FadeDarkness(2,100);

  //Lichter ausschalten
  LightsOff();
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

/* Munitionskistenerstellung */

func CreateAmmoCrate(int x, int y)
{
  var crate = CreateObject(WCR2,x,y,-1);
  CreateContents(ABOX,crate,2);
}

/* Respawn */

public func OnClonkEquip(object pClonk)
{
  //SetPosition(1055,795,pClonk);
  //Enter(spawn_gate,pClonk);
  var wpn = CreateContents(PSTL, pClonk);
  wpn->DoAmmo(wpn->GetFMData(FM_AmmoID),wpn->GetFMData(FM_AmmoLoad));
  //pClonk->DoAmmo(wpn->GetFMData(FM_AmmoID),wpn->GetFMData(FM_AmmoLoad)*2);
  var wpn = CreateContents(ASTR, pClonk);
  wpn->DoAmmo(wpn->GetFMData(FM_AmmoID),wpn->GetFMData(FM_AmmoLoad));
  DoAmmo(STAM,100,pClonk);
}

public func OnClassSelection(object pClonk)
{
  //SetPosition(1055,795,pClonk);
  //Enter(spawn_gate,pClonk);
}

public func RelaunchPosition(& iX, & iY, int iTeam)
{
  iX = 1055;
  iY = 795;
}

public func RejectRelaunch()
{
  return true;
}

/* Kistenabwurf */

public func Script5()
{
  if(!Random(BoundBy(40-(GetPlayerCount(C4PT_User)-1)*4,0,40)))
  {
    var x = RandomX(500,1540);
    var y = 460;

    var crate = CreateObject(WCR2,x,y,-1);
    var rope = CreateObject(IROP,x,y,-1);
    rope->Set(crate);

    for(var i = Random(3)+1; i > 0; i--)
    {
      var rnd = 3;
      
      if(!Random(rnd))
        CreateContents(RandomIndex4K([ABOX,GBOX,DGNN,FGRN,FRAG,PGRN,RLGN]),crate);
      else
        rnd = 0;
      
      if(!Random(rnd))
        CreateContents(RandomIndex4K([ABOX,GBOX,DGNN,FGRN,FRAG,PGRN]),crate);

      if(!Random(5))
      {
        var attachment = CreateObject(WNAT,x,y,-1);
        attachment->SetAttachment(RandomIndex4K([AT_ExtendedMag,AT_Bayonet,AT_Laserpointer]));
        Enter(crate, attachment);
      }
    }
  }
  goto(0);
}

//Dies ist ein CMC Beta Szenario.
//Ersteller: Henry / Michael14 / CMC Entwicklerteam
