/*-- Waffenaufsatz - Auswahlbox --*/

#strict 2

local iAttachment;

local choosableAttachments;

public func IsDrawable()  {return true;}  //Wird sichtbar getragen
public func HandSize()    {return 800;}
public func HandX()    {return 6000;}
public func HandY()    {return -1000;}


/* Initialisierung */

protected func Initialize()
{
  choosableAttachments = CreateArray(12);
  choosableAttachments = [1,2,4,8,16];

  //Keine Waffenaufsätze-Regel vorhanden? Verschwinden
  if(NoAttachments())
    return RemoveObject();

  return true;
}

/* Aktivierung */

protected func Activate(object pClonk)
{
  if(NoAttachments())
    return;

  AttachmentMenu(pClonk);
}

/* Menü */

protected func AttachmentMenu(object pByObj)
{

  //Falsche Aktion?
  if(!WildcardMatch(GetAction(pByObj), "*Walk*") && !WildcardMatch(GetAction(pByObj), "*Swim*") && !WildcardMatch(GetAction(pByObj), "*Crawl*") && !WildcardMatch(GetAction(pByObj), "*Jump*"))
  {
    PlayerMessage(GetOwner(pByObj), "$CantUpgrade$", pByObj);
    return;
  }

  //Clonk anhalten
  SetComDir(COMD_Stop, pByObj);

  //Menü öffnen
  CreateMenu(GetID(this), pByObj, this, 0, Format("$Upgrade$", GetName(0, GetID())), 0, C4MN_Style_Context);
  var fItemExists = false;

  //Kompatible Waffen auflisten
  for(var i = 0; i < GetLength(choosableAttachments); i++)
  {
    if(choosableAttachments[i]){
      var UpName = Format("%s: %s",GetName(0,GetID()),GetName(0,AttachmentToID(choosableAttachments[i])));
      fItemExists = true;
      AddMenuItem(Format("%s",UpName), "ChangeToAttachment", AttachmentToID(choosableAttachments[i]), pByObj, 0, pByObj);
     }
  }

  //Keine Waffe gefunden: Menü schließen
  if(!fItemExists)
  {
    PlayerMessage(GetOwner(pByObj), "$NothingUpgradeable$", pByObj);
    CloseMenu(pByObj);
  }
}

protected func AttachmentToID(val){
if(val == 1) return(AI01);
if(val == 2) return(AI02);
if(val == 4) return(AI03);
if(val == 8) return(AI04);
if(val ==16) return(AI05);
}
protected func IdToAttachment(eidy){
if(eidy == AI01) return(1);
if(eidy == AI02) return(2);
if(eidy == AI03) return(4);
if(eidy == AI04) return(8);
if(eidy == AI05) return(16);
}

protected func ChangeToAttachment(iedy){
 ChangeDef(WNAT);
 this()->SetAttachment(IdToAttachment(iedy));
}

/* Sonstiges */

protected func Hit()
{
  Sound("AmmoBoxHit*.ogg");
  return 1;
}

protected func Selection()
{
  Sound("FAPK_Charge.ogg");
  return 1;
}

/* Übergabe an andere */

func ControlThrow(object pByObj)
{
  for(var obj in FindObjects(Find_InRect(-10,-10,20,20),Find_OCF(OCF_CrewMember),Find_Exclude(pByObj),Find_Allied(GetOwner(pByObj)),Find_NoContainer()))
    if(Collect(this, obj))
    {
      Sound("FAPK_Charge.ogg");
      break;
    }

  return true;
}