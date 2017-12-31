#strict 2

local energy, base;

protected func Construction(object by)
{
	if (!by)
	{
		FatalError("Created without parent object");
	}
	base = by;
	energy = 0;
	Timer();
}

protected func ControlThrowDouble(object clonk)
{
	var cell = clonk->FindContents(ENAP);
	if (cell)
	{
		energy = 100;
		cell->RemoveObject();
	}
	return true;
}

protected func Timer()
{
	if (GetDamage() < 200)
	{
		energy++;
	}
	
	Message("@<c %x>%d%%</c>", this, RGB(255 - ((energy * 255) / 100), (energy * 255) / 100, 0), energy); 
	
	if (energy >= 100)
	{
		SetSection(GameCall("GetNextMap") || ["main", 100, 100]);
		ScriptGo(true);
	}
}
