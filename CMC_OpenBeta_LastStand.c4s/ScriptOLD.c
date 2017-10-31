/*-- Last Stand --*/

#strict
#include CSTD

static const FKDT_SuicideTime = 30; //Standardzeit bei Fake Death

static aAutomat;

//Dies ist ein CMC Beta Szenario.
//Ersteller: Henry / Michael14 / CMC Entwicklerteam

//GDEF-Spielziel

public func GDEF_CenterX()		{return(1000);}
public func GDEF_CenterY()		{return(840);}

public func GDEF_Waves()		{return(10);}
public func GDEF_MaxActive()		{return(20);}
public func GDEF_WaveCooldown(int iWave){return(30);}
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
    return(40);
  else if(iWave == 8)
    return(24);
  else if(iWave == 9)
    return(30);
  else if(iWave == 10)
    return(40);
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
    return([1]);
  else if(iWave == 8)
    return([1,2,2]);
  else if(iWave == 9)
    return([1,2,2]);
  else if(iWave == 10)
    return([1,2,2]);
}

public func GDEF_MonsterType1()
{
  var x,y; MonsterSpawn(x,y);
  var m = CreateObject(HCRB,x,y,-1);
  m->SetCmd(true,"MoveTo",0,GDEF_CenterX(),GDEF_CenterY());
  return(m);
}

public func GDEF_MonsterType2()
{
  var x,y; MonsterSpawn(x,y);
  var m = CreateObject(ZOMB,x,y,-1);
  m->SetCmd(true,"MoveTo",0,GDEF_CenterX(),GDEF_CenterY());
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


//Stuff

public func Initialize()
{
  _inherited();
  CreateFurniture();
}

static spawn_gate;

public func CreateFurniture()
{
  var tmp;

  //Leitern
  CreateObject (LADR, 1561, 315, -1)->Set(8);
  CreateObject (LADR, 1411, 1017, -1)->Set(21);
  CreateObject (LADR, 1001, 849, -1)->Set(6);
  CreateObject (LADR, 691, 978, -1)->Set(16);
  CreateObject (LADR, 561, 1037, -1)->Set(7);
  CreateObject (LADR, 271, 298, -1)->Set(7);
  CreateObject (LADR, 811, 318, -1)->Set(9);
  CreateObject (LADR, 1371, 247, -1)->Set(12);
  CreateObject (LADR, 1281, 148, -1)->Set(15);
  CreateObject (LADR, 931, 798, -1)->Set(6);

  //Waffenautomat
  aAutomat = CreateObject (WPVM, 1054, 810, -1);
  SetUpStore(aAutomat);

  //Liftplatten
  CreateObject (LFTP, 45, 1038, -1);
  CreateObject (LFTP, 985, 1038, -1);
  CreateObject (LFTP, 1765, 566, -1);

  //Türen, Tore und Luken
  spawn_gate = CreateObject (GAT1, 959, 804, -1);
  CreateObject (GAT2, 635, 915, -1);
  CastPXS ("Water",300,10,635,915);

    //diese Lucken sind zu und unzerstörbar!

    tmp = CreateObject (HA4K, 1410, 861, -1);
    tmp->Lock();
    tmp->SetMaxDamage(-1);

    tmp = CreateObject (HA4K, 690, 861, -1);
    tmp->Lock();
    tmp->SetMaxDamage(-1);

    tmp = CreateObject (HA4K, 1560, 261, -1);
    tmp->Lock();
    tmp->SetMaxDamage(-1);

    tmp = CreateObject (HA4K, 270, 251, -1);
    tmp->Lock();
    tmp->SetMaxDamage(-1);

    tmp = CreateObject (SLDR, 365, 690, -1);
    tmp->Lock();
    tmp->SetMaxDamage(-1);

  CreateObject (HA4K, 810, 251, -1);
  CreateObject (HA4K, 1000, 811, -1);
  CreateObject (HA4K, 930, 761, -1);
  //CreateObject (HNG2, 1714, 861, -1);
  //CreateObject (HNG2, 321, 861, -1);
  CreateObject (STDR, 254, 691, -1);
  CreateObject (STDR, 1104, 161, -1);
  CreateObject (STDR, 1047, 252, -1);
  CreateObject (SLDR, 1335, 1090, -1);
  CreateObject (LBDR, 682, 810, -1)->DoDamage (1000);

  /*
  tmp = CreateObject (SLDR, 915, 860, -1);
  tmp->Lock();
  tmp->Open();
  CreateObject (SWTH, 930, 860, -1)->Set(tmp);

  tmp = CreateObject (SLDR, 1085, 860, -1);
  tmp->Lock();
  tmp->Open();
  CreateObject (SWTH, 1072, 860, -1)->Set(tmp);
  */

  //Sonstiges
  //CreateObject (DEB1, 1261, 862, -1);
  CreateObject (LCKR, 1305, 809, -1)->SetR(-41);
  CreateObject (CHAR, 1398, 809, -1);
  CreateObject (OTBL, 1405, 809, -1);
  CreateObject (OCHR, 1295, 1089, -1);
  CreateObject (OCHR, 1257, 1089, -1);
  CreateObject (MONI, 1409, 795, -1);
  CreateObject (LTBL, 1070, 1089, -1);
  CreateObject (MONI, 1071, 1070, -1)->On();
  CreateObject (CCP2, 1278, 1090, -1);
  CreateObject (CCP2, 1241, 1090, -1);
  CreateObject (MPPJ, 1163, 1089, -1);
  CreateObject (FIEX, 1022, 802, -1);
  CreateObject (SCR3, 1072, 1049, -1);
  CreateObject (MVNT, 1000, 790, -1)->SetCon(30);

  //Lichter
  CreateObject (CLGH, 1045, 823, -1);
  CreateObject (CLGH, 959, 823, -1);
  CreateObject (CLGH, 1044, 773, -1);
  CreateObject (CLGH, 959, 773, -1);
  
  //Atmosphärische Sound-Effekte...
  CreateObject(SE4K,10,10,-1)->Set("BattleLoop*.ogg",35*5,35*2,-1);
  CreateObject(SE4K,10,10,-1)->Set("DistantZombie*.ogg",35*20,35*5,-1);

  SetupVehicleSpawn([H_HE],DIR_Right,CreateObject(VSPW,1010,730,-1),100*21);

  return(1);
}

public func SetUpStore(aAutomat)
{
  aAutomat->AddWare(PSTL,-1);
  aAutomat->AddWare(RVLR,-1);
  aAutomat->AddWare(SMGN,-1);
  aAutomat->AddWare(ASTR,-1);
  aAutomat->AddWare(PPGN,-1);
  aAutomat->AddWare(MNGN,-1);
  aAutomat->AddWare(SGST,-1);
  aAutomat->AddWare(RTLR,-1);

  aAutomat->AddWare(ABOX,-1);
  aAutomat->AddWare(GBOX,-1);
  aAutomat->AddWare(MIAP,-1);

  aAutomat->AddWare(AMPK,-1);
  aAutomat->AddWare(FAPK,-1);
  aAutomat->AddWare(CDBT,-1);
  aAutomat->AddWare(C4PA,-1);

  aAutomat->AddWare(FGRN,-1);
  aAutomat->AddWare(FRAG,-1);
  aAutomat->AddWare(PGRN,-1);
}

public func CMC(pStore)
{
  Log("Sonderangebot! Jetzt zuschlagen omg!1!");
  Sound("Cheer.ogg");
  Sound("Cash");
  aAutomat->AddWare(ACCN,-1); 
  aAutomat->AddWare(MISA,-1); 
}

public func OnClonkEquip(object pClonk)
{
  pClonk->Enter(spawn_gate);

  var wpn = CreateContents(PSTL, pClonk);
  wpn->DoAmmo(wpn->GetFMData(FM_AmmoID),wpn->GetFMData(FM_AmmoLoad));
  //pClonk->DoAmmo(wpn->GetFMData(FM_AmmoID),wpn->GetFMData(FM_AmmoLoad)*2);
  var wpn = CreateContents(ASTR, pClonk);
  wpn->DoAmmo(wpn->GetFMData(FM_AmmoID),wpn->GetFMData(FM_AmmoLoad));
  DoAmmo(STAM,150,pClonk);
}

public func OnClassSelection(object pClonk)
{
  pClonk->Enter(spawn_gate);
}

public func RejectRelaunch()
{
  return(true);
}

//Dies ist ein CMC Beta Szenario.
//Ersteller: Henry / Michael14 / CMC Entwicklerteam