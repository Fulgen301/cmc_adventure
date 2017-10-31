/*-- Holzkiste --*/

//Inhalte aus zerst�rten Kisten werden herausgeschmissen / Kisten verf�gen �ber keine SolidMask mehr.

#strict 2
#appendto WCR2


/* Initialisierung */

public func Initialize() 
{
  //SolidMask entfernen
  SetSolidMask();

  //Kiste gelblich f�rben
  SetClrModulation(RGB(255,255,0));

  _inherited();
}

/* Zerst�rung */

func Damage()
{
  if(GetDamage() > 50)
  {
    //Effekte
    if(GetEffectData(EFSM_ExplosionEffects) > 1) CastParticles("WoodSplinter", 4, 40, 0,0, 50, 75, RGBa(255,255,255,0), RGBa(255,255,255,0));
    CastParticles("WoodCrateSplinter", 4, 50, 0,0, 141);
    Sound("CrateDestruct*.ogg");
    Sound("WoodCrack*.ogg");

    //Inhalte herausschmei�en
    while(Contents())
      Exit(Contents(),0,0,Random(360),RandomX(-1,+1)+GetXDir(),GetYDir(),RandomX(-6,+6));

    //Verschwinden
    RemoveObject(0, 1);
  }
}