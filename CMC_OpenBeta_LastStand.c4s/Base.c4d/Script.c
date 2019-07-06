/*-- Peacemakerbasis --*/

#strict 2

local automat;
local lights;
local drive;

protected func Construction()
{
	_inherited(...);
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
	/*DrawMaterialQuad("BackWall-Concrete2",
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
					 true);*/
	
	// Position: 1000, 790
	CreateObject(MVNT, 0, 0, -1)->SetCon(30);
	CreateObject(GAT1, 55, 5, -1);
	CreateObject(FIE2, 35, 15, -1);
	lights = [CreateObject(BLGH, 45, 55, -1), CreateObject(BLGH, -55, 55, -1)];
	automat = CreateObject(WPVM, 0, 60, -1);
	SetUpStore();
	
	CreateObject(LADR, -70, 18, -1)->Set(5);
	CreateObject(HA4K, -70, -27, -1);
	CreateObject(MUMT, 0, -29, -1);
	drive = CreateObject(DDRV, 41, 23, -1);
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
