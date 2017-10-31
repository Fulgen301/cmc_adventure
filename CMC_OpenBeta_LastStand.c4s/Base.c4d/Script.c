/*-- Peacemakerbasis --*/

#strict 2

local automat;
local objects;

protected func Construction()
{
	_inherited(...);
	objects = CreateHash();
	PlaceBase();
}

private func PlaceBase()
{
	for (var obj in FindObjects(Find_InRect(-89, -29, 180, 109), Find_Exclude(this), Find_Not(Find_OCF(OCF_Living)), Find_NoContainer()))
	{
		if (obj)
		{
			obj->RemoveObject(); // Destruction
		}
	}
	
	// Draw material
	// BackWall -89 -29 +91 -29
	DrawMaterialQuad("BackWall-Concrete2",
					 AbsX(-89), AbsY(-29),
					 AbsX(+91), AbsY(-29),
					 AbsX(+91), AbsY(+80),
					 AbsX(-89), AbsY(+80));
	
	DrawMaterialQuad("Wall-Concrete3",
					 AbsX(-89), AbsY(-29),
					 AbsX(+91), AbsY(-29),
					 AbsX(+91), AbsY(-18),
					 AbsX(-89), AbsY(-18));
	
	// BackWall
	DrawMaterialQuad("BackWall-Concrete3",
					 AbsX(-79), AbsY(-29),
					 AbsX(-61), AbsY(-29),
					 AbsX(-61), AbsY(-18),
					 AbsX(-79), AbsY(-18));
	
	DrawMaterialQuad("Wall-Concrete2",
					 AbsX(-89), AbsY(-18),
					 AbsX(-79), AbsY(-18),
					 AbsX(-79), AbsY(+37),
					 AbsX(-89), AbsY(+37));
	
	DrawMaterialQuad("Wall-Concrete2",
					 AbsX(+81), AbsY(-18),
					 AbsX(+91), AbsY(-18),
					 AbsX(+91), AbsY(+37),
					 AbsX(+81), AbsY(+37));
	
	DrawMaterialQuad("Wall-Concrete3",
					 AbsX(-79), AbsY(+21),
					 AbsX(-29), AbsY(+21),
					 AbsX(-29), AbsY(+31),
					 AbsX(-79), AbsY(+31));
	
	DrawMaterialQuad("Wall-Concrete3",
					 AbsX(+29), AbsY(+21),
					 AbsX(+81), AbsY(+21),
					 AbsX(+81), AbsY(+31),
					 AbsX(+29), AbsY(+31));
	
	DrawMaterialQuad("Wall-Concrete3",
					 AbsX(-109), AbsY(71),
					 AbsX(+112), AbsY(71),
					 AbsX(+112), AbsY(81),
					 AbsX(-109), AbsY(81),
					 true);
	
	//Rampen
	DrawMaterialQuad("Wall-Concrete3",
					 AbsX(-30), AbsY(+72),
					 AbsX(-30), AbsY(+62),
					 AbsX(-60), AbsY(+72),
					 AbsX(-30), AbsY(+72),
					 true);
	
	DrawMaterialQuad("Wall-Concrete3",
					 AbsX(+31), AbsY(+72),
					 AbsX(+31), AbsY(+62),
					 AbsX(+61), AbsY(+72),
					 AbsX(+31), AbsY(+72),
					 true);
	
	DrawMaterialQuad("Wall-Concrete3",
					 AbsX(-30), AbsY(+62),
					 AbsX(+31), AbsY(+62),
					 AbsX(+31), AbsY(+72),
					 AbsX(-30), AbsY(+72),
					 true);
	
	// Position: 1000, 790
	CreateObject(MVNT, 0, 0, -1)->SetCon(30);
	CreateObject(GAT1, 55, 5, -1);
	CreateObject(FIE2, 35, 15, -1);
	CreateObject(BLGH, 45, 55, -1);
	CreateObject(BLGH, -55, 55, -1);
	automat = CreateObject(WPVM, 0, 60, -1);
	SetUpStore();
	
	CreateObject(LADR, -70, 18, -1)->Set(5);
	CreateObject(HA4K, -70, -27, -1);
	CreateObject(MUMT, 0, -29, -1);
}

private func SetUpStore()
{
  //Munition
  automat->AddWare(ABOX,-1);
  automat->AddWare(GBOX,-1);
  automat->AddWare(MIAP,-1);

  //Ausrüstung
  automat->AddWare(FAPK,3);
  automat->AddWare(CDBT,3);

  //Handgranaten
  automat->AddWare(FGRN,10);
  automat->AddWare(FRAG,10);
  automat->AddWare(PGRN,10);

  //Ausrüstung
  automat->AddWare(C4PA,10);
  automat->AddWare(DGNN,10);
  automat->AddWare(WATC,10);

  //Waffen
  automat->AddWare(RVLR,5);
  automat->AddWare(PSTL,0);
  automat->AddWare(SMGN,3);
  automat->AddWare(ASTR,3);
  automat->AddWare(PPGN,3);
  automat->AddWare(MNGN,3);
  automat->AddWare(SGST,3);
  automat->AddWare(RTLR,3);
  automat->AddWare(ATWN,10);
}

private func AbsX(int x)
{
	return GetX() + x;
}

private func AbsY(int y)
{
	return GetY() + y;
}

public func Travel(string section, int base_x, int base_y)
{
	// Save
	for (var obj in FindObjects(Find_Or(Find_OCF(OCF_CrewMember), Find_Category(C4D_Object)), Find_InRect(-89, -29, 180, 109), Find_Not(Find_ID(GetID()))))
	{
		if (obj)
		{
			HashPut(objects, obj, [obj->GetX() - GetX(), obj->GetY() - GetY()]);
			obj->SetPosition(0, 0);
			if (GetOCF(obj) & OCF_CrewMember)
			{
				var x = HashGet(objects, obj);
				Log("Offset: %d %d", x[0], x[1]);
			}
			obj->SetObjectStatus(C4OS_INACTIVE);
		}
	}
	
	this->SetPosition(0, 0);
	this->SetObjectStatus(C4OS_INACTIVE);
	
	// DANGER
	LoadScenarioSection(section || "main");
	// DANGER
	
	GameCallEx("SectionLoaded", section);
	
	// Load
	this->SetObjectStatus(C4OS_NORMAL);
	this->SetPosition(base_x, base_y);
	this->PlaceBase();
	
	var iter = HashIter(objects);
	var node;
	while (node = HashIterNext(iter))
	{
		node[0]->SetObjectStatus(C4OS_NORMAL);
		var x = GetX() + base_x, y = base_y + node[1][1];
		node[0]->SetPosition(base_x, base_y);
		//ScheduleCall(node[0], "SetPosition", x, y);
	}
	objects = CreateHash();
}
