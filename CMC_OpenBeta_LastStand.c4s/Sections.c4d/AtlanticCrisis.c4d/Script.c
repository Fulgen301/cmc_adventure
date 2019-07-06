/* Atlantic Crisis */
#strict 2
#include _SEC

public func Initialize()
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
  crate->CreateObject(ENAP,0,-10,-1);

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
  SetMatAdjust(RGBa(255,255,255,127));
  SetSkyAdjust(0);
}

public func IsFulfilled()
{
  return true;
}

public func Destruction()
{
	SetMatAdjust(0);
	SetSkyAdjust(RGB(255,255,255));
}

public func GetCoordinates()
{
  return [601, 754];
}
