/*-- Anfassen verbieten --*/

//Bestimmte Objekte k�nnen nicht mehr angefasst werden.

#strict 2
#appendto OTBL
#appendto CHAR
#appendto H24K


/* Initialisierung */

public func Initialize() 
{
  SetObjectLayer(this());
  return(_inherited());
}