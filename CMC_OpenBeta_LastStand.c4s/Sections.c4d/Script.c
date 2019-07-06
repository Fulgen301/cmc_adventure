#strict 2

static current_section;

protected func Initialize()
{
	Log("Don't create %i", GetID());
	return RemoveObject();
}

public func IsSection()
{
	return true;
}

public func IsFulfilled()
{
	return false;
}
