/* Research Facility */
#strict 2
#include _SEC

static current_section;

public func Initialize()
{
  var aDoorWay = [];
  var aDoor = [];
  //Rampen
  DrawMaterialQuad("Wall-Concrete2",1141,810,1141,800,1161,810,1141,810,true);
  DrawMaterialQuad("Wall-Stripes",1210,170,1235,190,1235,190,1210,190,true);
  DrawMaterialQuad("Wall-Stripes",1220,1660,1240,1640,1240,1700,1220,1680,true);
  DrawMaterialQuad("Wall-Stripes",1400,1640,1420,1660,1420,1680,1400,1700,true);
  DrawMaterialQuad("Wall-Stripes",1501,1890,1501,1870,1531,1890,1501,1890,true);
  DrawMaterialQuad("Wall-Stripes",1510,821,1510,811,1440,821,1510,821,true);
  DrawMaterialQuad("BackWall-Grid1",1520,1899,1542,1899,1542,1901,1520,1901,true);
  DrawMaterialQuad("Wall-Concrete3",1991,1110,1991,1100,1961,1110,1991,1110,true);
  DrawMaterialQuad("Wall-Stripes",2021,820,2021,810,2091,820,2021,820,true);
  DrawMaterialQuad("Wall-Concrete2",2640,1270,2670,1290,2640,1290,2640,1270,true);

  //Leitern
  CreateObject(LADR, 230, 694, -1)->Set(27);
  CreateObject(LADR, 280, 796, -1)->Set(6);
  CreateObject(LADR, 325, 1007, -1)->Set(10);
  CreateObject(LADR, 325, 1955, -1)->Set(33);
  CreateObject(LADR, 405, 545, -1)->Set(6);
  CreateObject(LADR, 480, 1777, -1)->Set(31);
  CreateObject(LADR, 575, 545, -1)->Set(6);
  CreateObject(LADR, 525, 900, -1)->Set(8);
  CreateObject(LADR, 690, 712, -1)->Set(18);
  CreateObject(LADR, 710, 1154, -1)->Set(17);
  CreateObject(LADR, 785, 1955, -1)->Set(9);
  CreateObject(LADR, 835, 1955, -1)->Set(10);
  CreateObject(LADR, 840, 534, -1)->Set(37);
  CreateObject(LADR, 870, 984, -1)->Set(7);
  CreateObject(LADR, 1020, 522, -1)->Set(13);
  CreateObject(LADR, 1050, 278, -1)->Set(5);
  CreateObject(LADR, 1105, 133, -1)->Set(6);
  CreateObject(LADR, 1110, 988, -1)->Set(50);
  CreateObject(LADR, 1020, 1750, -1)->Set(49);
  CreateObject(LADR, 1130, 1346, -1)->Set(41);
  CreateObject(LADR, 1175, 1907, -1)->Set(11);
  CreateObject(LADR, 1240, 1344, -1)->Set(131);
  CreateObject(LADR, 1307, 153, -1)->Set(6);
  CreateObject(LADR, 1320, 1772, -1)->Set(3);
  CreateObject(LADR, 1367, 253, -1)->Set(6);
  CreateObject(LADR, 1420, 790, -1)->Set(20);
  CreateObject(LADR, 1460, 988, -1)->Set(5);
  CreateObject(LADR, 1520, 702, -1)->Set(9);
  CreateObject(LADR, 1530, 1530, -1)->Set(27);
  CreateObject(LADR, 1565, 1623, -1)->Set(7);
  CreateObject(LADR, 1565, 1875, -1)->Set(16);
  CreateObject(LADR, 1575, 1080, -1)->Set(8);
  CreateObject(LADR, 1580, 920, -1)->Set(8);
  CreateObject(LADR, 1620, 702, -1)->Set(9);
  CreateObject(LADR, 1700, 1075, -1)->Set(28);
  CreateObject(LADR, 1760, 1510, -1)->Set(19);
  CreateObject(LADR, 1830, 1075, -1)->Set(28);
  CreateObject(LADR, 1905, 1860, -1)->Set(14);
  CreateObject(LADR, 1940, 702, -1)->Set(9);
  CreateObject(LADR, 1950, 904, -1)->Set(6);
  CreateObject(LADR, 2040, 702, -1)->Set(9);
  CreateObject(LADR, 2140, 790, -1)->Set(20);
  CreateObject(LADR, 2140, 1014, -1)->Set(12);
  CreateObject(LADR, 2140, 1542, -1)->Set(28);
  CreateObject(LADR, 2400, 1422, -1)->Set(23);
  CreateObject(LADR, 2410, 1076, -1)->Set(41);
  CreateObject(LADR, 2575, 721, -1)->Set(13);
  CreateObject(LADR, 2730, 1530, -1)->Set(28);
  CreateObject(LADR, 2880, 886, -1)->Set(76);
  CreateObject(LADR, 2935, 881, -1)->Set(4);
  CreateObject(LADR, 2995, 1089, -1)->Set(30);
  CreateObject(LADR, 3200, 1065, -1)->Set(27);
  CreateObject(LADR, 3065, 881, -1)->Set(4);
  CreateObject(LADR, 3130, 884, -1)->Set(17);
  CreateObject(LADR, 3145, 1275, -1)->Set(21);
  CreateObject(LADR, 3325, 1083, -1)->Set(37);

  //Stahlbrücken
  CreateObject(_HBR, 635, 1792, -1)->SwitchMode();
  CreateObject(_HBR, 810, 1792, -1)->SwitchMode();
  CreateObject(_HBR, 1577, 952, -1);
  CreateObject(_HBR, 1955, 922, -1);
  CreateObject(_HBR, 2335, 1832, -1)->SwitchMode();
  CreateObject(_HBR, 3070, 992, -1);
  CreateObject(_HBR, 3141, 922, -1);
  CreateObject(_HBR, 3141, 992, -1);

  //Bodenluken
  CreateObject(HA4K, 230, 473, -1);
  aDoor[01] = CreateObject(HA4K, 280, 743, -1);
  CreateObject(HA4K, 450, 563, -1);
  CreateObject(HA4K, 690, 563, -1);
  aDoor[08] = CreateObject(HA4K, 710, 1013, -1);
  CreateObject(HA4K, 840, 233, -1);
  CreateObject(HA4K, 870, 923, -1);
  CreateObject(HA4K, 1020, 413, -1);
  CreateObject(HA4K, 1020, 1563, -1);
  CreateObject(HA4K, 1050, 233, -1);
  CreateObject(HA4K, 1110, 583, -1);
  aDoor[02] = CreateObject(HA4K, 1110, 713, -1);
  CreateObject(HA4K, 1110, 803, -1);
  CreateObject(HA4K, 1110, 893, -1);
  CreateObject(HA4K, 1130, 1013, -1);
  CreateObject(HA4K, 1240, 293, -1);
  CreateObject(HA4K, 1240, 523, -1);
  CreateObject(HA4K, 1240, 813, -1);
  CreateObject(HA4K, 1240, 1013, -1);
  CreateObject(HA4K, 1320, 1743, -1);
  CreateObject(HA4K, 1460, 943, -1);
  CreateObject(HA4K, 2060, 1783, -1);
  CreateObject(HA4K, 2110, 1783, -1);
  CreateObject(HA4K, 2140, 913, -1);
  CreateObject(HA4K, 2140, 1023, -1);
  CreateObject(HA4K, 2140, 1313, -1);
  aDoor[06] = CreateObject(HA4K, 2730, 1303, -1);
  CreateObject(HA4K, 2270, 1023, -1);
  CreateObject(HA4K, 2400, 1233, -1);
  CreateObject(HA4K, 2410, 743, -1);
  CreateObject(HA4K, 2410, 913, -1);
  CreateObject(HA4K, 2880, 273, -1);
  CreateObject(HA4K, 2880, 553, -1);
  CreateObject(HA4K, 2880, 743, -1);
  CreateObject(HA4K, 3130, 743, -1);
  aDoor[10] = CreateObject(HA4K, 1020, 1663, -1);

  //Große Bodenluken
  CreateObject(H24K, 325, 928, -1);
  CreateObject(H24K, 405, 498, -1);
  CreateObject(H24K, 575, 498, -1);
  CreateObject(H24K, 1565, 1568, -1);
  CreateObject(H24K, 1565, 1748, -1);
  CreateObject(H24K, 2575, 618, -1);
  CreateObject(H24K, 3325, 788, -1);
  CreateObject(H24K, 3325, 918, -1);
  aDoor[09] = CreateObject(H24K, 3145, 1108, -1);

  //Glasscheiben
  CreateObject(PANE, 712, 490, -1);
  CreateObject(PANE, 732, 810, -1);
  CreateObject(PANE, 732, 860, -1);
  CreateObject(PANE, 732, 1080, -1);
  CreateObject(PANE, 732, 1130, -1);
  CreateObject(PANE, 738, 490, -1);
  CreateObject(PAN2, 745, 300, -1);
  CreateObject(PAN2, 745, 360, -1);
  CreateObject(PAN2, 745, 420, -1);
  CreateObject(PANE, 748, 810, -1);
  CreateObject(PANE, 748, 860, -1);
  CreateObject(PANE, 748, 1080, -1);
  CreateObject(PANE, 748, 1130, -1);
  CreateObject(PANE, 822, 269, -1);
  CreateObject(PANE, 822, 298, -1);
  CreateObject(PANE, 1158, 140, -1);
  CreateObject(PANE, 1212, 140, -1);
  CreateObject(PAN2, 1665, 1896, -1);
  CreateObject(PAN2, 1685, 1896, -1);
  CreateObject(PAN2, 1705, 1896, -1);
  CreateObject(PAN2, 1885, 1896, -1);
  CreateObject(PAN2, 1905, 1896, -1);
  CreateObject(PAN2, 1925, 1896, -1);
  CreateObject(PANE, 2392, 669, -1);
  CreateObject(PANE, 2392, 698, -1);
  CreateObject(PANE, 2392, 779, -1);
  CreateObject(PANE, 2392, 808, -1);
  CreateObject(PANE, 2392, 837, -1);
  CreateObject(PANE, 2392, 866, -1);
  CreateObject(PANE, 2392, 949, -1);
  CreateObject(PANE, 2392, 978, -1);
  CreateObject(PANE, 2392, 1007, -1);
  CreateObject(PANE, 2392, 1036, -1);
  CreateObject(PANE, 2862, 309, -1);
  CreateObject(PANE, 2862, 338, -1);
  CreateObject(PANE, 2862, 367, -1);
  CreateObject(PANE, 2862, 396, -1);
  CreateObject(PANE, 2862, 425, -1);
  CreateObject(PANE, 2862, 454, -1);
  CreateObject(PANE, 2862, 483, -1);
  CreateObject(PANE, 2862, 512, -1);
  CreateObject(PANE, 2862, 589, -1);
  CreateObject(PANE, 2862, 618, -1);
  CreateObject(PANE, 2862, 647, -1);
  CreateObject(PANE, 2862, 676, -1);
  CreateObject(PANE, 2862, 705, -1);
  CreateObject(PANE, 2862, 779, -1);
  CreateObject(PANE, 2862, 808, -1);
  CreateObject(PANE, 2862, 837, -1);

  //Fenster
  var window = CreateObject(WNDW, 1075, 171, -1);
  window->Set();
  window->DoDmg(100);
  window->AddSmokeEffect4K(50,-15,-25,true,this);
  CreateObject(WNDW, 1335, 191, -1)->Set(1);
  CreateObject(WNDW, 1355, 1381, -1)->Set(1);
  CreateObject(WNDW, 1395, 291, -1)->Set(1);
  CreateObject(WNDW, 2185, 1451, -1)->Set();

  //Schutztüren
  CreateObject(GDDR, 500, 230, -1)->Lock();
  CreateObject(GDDR, 505, 740, -1)->SetColorDw(HSL(0,0, 220));
  CreateObject(GDDR, 505, 830, -1)->SetColorDw(HSL(0,0, 220));
  CreateObject(GDDR, 505, 920, -1)->SetColorDw(HSL(0,0, 220));
  CreateObject(GDDR, 525, 490, -1)->SetColorDw(HSL(80, 150, 100, 127));
  CreateObject(GDDR, 525, 560, -1)->SetColorDw(HSL(80, 150, 100, 127));
  CreateObject(GDDR, 550, 230, -1)->SetColorDw(HSL(145, 210, 100, 127));
  CreateObject(GDDR, 725, 560, -1)->SetColorDw(HSL(80, 150, 100, 127));
  CreateObject(GDDR, 825, 740, -1)->SetColorDw(HSL(0,0, 220));
  CreateObject(GDDR, 825, 830, -1)->SetColorDw(HSL(0,0, 220));
  CreateObject(GDDR, 825, 920, -1)->SetColorDw(HSL(0,0, 220));
  CreateObject(GDDR, 930, 560, -1)->SetColorDw(HSL(80, 150, 100, 127));
  CreateObject(GDDR, 1265, 520, -1)->SetColorDw(HSL(145, 210, 100, 127));
  CreateObject(GDDR, 1270, 290, -1)->SetColorDw(HSL(145, 210, 100, 127));
  CreateObject(GDDR, 2755, 140, -1)->Lock();
  CreateObject(GDDR, 3220, 910, -1)->SetColorDw(HSL(0, 0, 100));
  CreateObject(GDDR, 3220, 1100, -1)->SetColorDw(HSL(0, 0, 100));

  //Gitter
  CreateObject(GTNG, 1290, 1280, -1);
  CreateObject(GTNG, 1347, 610, -1);
  CreateObject(GTNG, 1397, 940, -1);
  CreateObject(GTNG, 1627, 1740, -1);
  CreateObject(GTNG, 1993, 1020, -1);
  CreateObject(GTNG, 2183, 610, -1);
  CreateObject(GTNG, 2257, 1780, -1);
  CreateObject(GTNG, 2297, 1230, -1);
  CreateObject(GTNG, 2307, 1020, -1);
  CreateObject(GTNG, 2455, 1270, -1);
  CreateObject(GTNG, 2777, 610, -1);
  CreateObject(GTNG, 3143, 780, -1);

  //Dekoschleusen
  CreateObject(GAT1, 1640, 700, -1);
  CreateObject(GAT1, 1890, 700, -1);

  //Paletten
  CreateObject(PLLT, 280, 920, -1);
  CreateObject(PLLT, 1540, 1110, -1);
  CreateObject(PLLT, 1490, 1740, -1);

  //Benzinfässer
  CreateObject(PBRL, 330, 1190, -1)->AutoRespawn();
  CreateObject(PBRL, 430, 1110, -1)->AutoRespawn();
  CreateObject(PBRL, 440, 1110, -1)->AutoRespawn();
  CreateObject(PBRL, 1940, 1110, -1)->AutoRespawn();

  //Explosivfässer
  CreateObject(XBRL, 450, 830, -1)->AutoRespawn();
  CreateObject(XBRL, 460, 830, -1)->AutoRespawn();
  CreateObject(XBRL, 880, 1780, -1)->AutoRespawn();
  CreateObject(XBRL, 2685, 1100, -1)->AutoRespawn();
  CreateObject(XBRL, 2730, 270, -1)->AutoRespawn();

  //Giftfässer
  CreateObject(TBRL, 890, 1780, -1)->AutoRespawn();
  CreateObject(TBRL, 320, 1190, -1)->AutoRespawn();
  CreateObject(TBRL, 1200, 1740, -1)->AutoRespawn();
  CreateObject(TBRL, 1210, 1740, -1)->AutoRespawn();
  CreateObject(TBRL, 1500, 1360, -1);
  CreateObject(TBRL, 1500, 1510, -1);
  CreateObject(TBRL, 1890, 1360, -1);
  CreateObject(TBRL, 2420, 1230, -1)->AutoRespawn();

  //Gasflaschen
  CreateObject(GSBL, 365, 230, -1);
  CreateObject(GSBL, 365, 435, -1)->SetR(90);
  CreateObject(GSBL, 460, 1110, -1)->AutoRespawn();
  CreateObject(GSBL, 630, 1190, -1)->AutoRespawn();
  CreateObject(GSBL, 680, 230, -1)->AutoRespawn();
  CreateObject(GSBL, 690, 230, -1)->AutoRespawn();
  CreateObject(GSBL, 1480, 1870, -1)->AutoRespawn();
  CreateObject(GSBL, 1950, 1890, -1)->AutoRespawn();
  CreateObject(GSBL, 2570, 270, -1);
  CreateObject(GSBL, 2695, 1100, -1)->AutoRespawn();
  CreateObject(GSBL, 3110, 1100, -1)->AutoRespawn();

  //Explosivtanks
  CreateObject(XTNK, 585, 1190, -1)->AutoRespawn();
  CreateObject(XTNK, 1430, 1740, -1)->AutoRespawn();
  CreateObject(XTNK, 1460, 1660, -1)->AutoRespawn();
  CreateObject(XTNK, 1600, 1110, -1)->AutoRespawn();
  CreateObject(XTNK, 1680, 1110, -1)->AutoRespawn();
  CreateObject(XTNK, 1850, 1110, -1)->AutoRespawn();
  CreateObject(XTNK, 1930, 1110, -1)->AutoRespawn();

  //Container
  CreateObject(CON1, 1160, 1661, -1)->SetPerspective(3);
  CreateObject(CON1, 1160, 1741, -1);
  CreateObject(CON1, 1440, 1871, -1)->SetPerspective(3);
  CreateObject(CON1, 1560, 1661, -1);
  CreateObject(CON1, 1606, 1891, -1)->SetPerspective(2);
  CreateObject(CON1, 1650, 1560, -1)->SetPerspective(2);
  CreateObject(CON1, 1690, 1561, -1);
  CreateObject(CON1, 1800, 1560, -1);
  CreateObject(CON1, 1825, 1533, -1)->SetPerspective(2);
  CreateObject(CON1, 1855, 1561, -1)->SetPerspective(3);
  CreateObject(CON1, 1980, 1890, -1)->SetPerspective(2);
  CreateObject(CON1, 2015, 1100, -1)->SetPerspective(2);
  CreateObject(CON1, 2105, 1100, -1);
  CreateObject(CON1, 2935, 1100, -1);
  CreateObject(CON1, 2935, 1073, -1)->SetPerspective(2);
  CreateObject(CON1, 3316, 1160, -1)->SetPerspective(2);

  //Explosive Kisten
  CreateObject(XWCR, 640, 740, -1)->AutoRespawn();
  CreateObject(XWCR, 970, 410, -1)->AutoRespawn();
  CreateObject(XWCR, 1030, 1780, -1)->AutoRespawn();
  CreateObject(XWCR, 1055, 180, -1);
  CreateObject(XWCR, 1340, 1560, -1)->AutoRespawn();
  CreateObject(XWCR, 1370, 1010, -1)->AutoRespawn();
  CreateObject(XWCR, 1370, 1852, -1);
  CreateObject(XWCR, 1430, 820, -1);
  CreateObject(XWCR, 2000, 1560, -1)->AutoRespawn();
  CreateObject(XWCR, 2090, 910, -1)->AutoRespawn();
  CreateObject(XWCR, 2100, 820, -1);
  CreateObject(XWCR, 3230, 1290, -1)->AutoRespawn();
  CreateObject(XWCR, 2630, 140, -1)->AutoRespawn();

  //Kisten
  CreateObject(WCR2, 270, 1290, -1)->AutoRespawn();
  CreateObject(WCR2, 270, 1430, -1)->AutoRespawn();
  CreateObject(WCR2, 290, 1110, -1)->AutoRespawn();
  CreateObject(WCR2, 290, 1190, -1)->AutoRespawn();
  CreateObject(WCR2, 290, 1430, -1)->AutoRespawn();
  CreateObject(WCR2, 310, 1110, -1)->AutoRespawn();
  CreateObject(WCR2, 310, 1430, -1)->AutoRespawn();
  CreateObject(WCR2, 350, 490, -1)->AutoRespawn();
  CreateObject(WCR2, 650, 1190, -1)->AutoRespawn();
  CreateObject(WCR2, 660, 1172, -1);
  CreateObject(WCR2, 670, 1190, -1)->AutoRespawn();
  CreateObject(WCR2, 1140, 1560, -1);
  CreateObject(WCR2, 1310, 610, -1);
  CreateObject(WCR2, 1305, 810, -1);
  CreateObject(WCR2, 1315, 792, -1);
  CreateObject(WCR2, 1325, 810, -1);
  CreateObject(WCR2, 1340, 1870, -1);
  CreateObject(WCR2, 1360, 1560, -1)->AutoRespawn();
  CreateObject(WCR2, 1360, 1870, -1);
  CreateObject(WCR2, 1380, 1870, -1);
  CreateObject(WCR2, 1390, 1010, -1)->AutoRespawn();
  CreateObject(WCR2, 1410, 820, -1)->AutoRespawn();
  CreateObject(WCR2, 1410, 1010, -1);
  CreateObject(WCR2, 1430, 1010, -1);
  CreateObject(WCR2, 1520, 1660, -1)->AutoRespawn();
  CreateObject(WCR2, 1600, 1310, -1)->AutoRespawn();
  CreateObject(WCR2, 1765, 1840, -1);
  CreateObject(WCR2, 2070, 910, -1)->AutoRespawn();
  CreateObject(WCR2, 2075, 892, -1);
  CreateObject(WCR2, 2110, 1072, -1);
  CreateObject(WCR2, 2120, 820, -1)->AutoRespawn();
  CreateObject(WCR2, 2170, 1050, -1);
  CreateObject(WCR2, 2220, 1560, -1);
  CreateObject(WCR2, 2240, 1523, -1);
  CreateObject(WCR2, 2240, 1542, -1);
  CreateObject(WCR2, 2240, 1560, -1);
  CreateObject(WCR2, 2250, 810, -1);
  CreateObject(WCR2, 2260, 792, -1);
  CreateObject(WCR2, 2260, 1523, -1);
  CreateObject(WCR2, 2260, 1542, -1);
  CreateObject(WCR2, 2260, 1560, -1);
  CreateObject(WCR2, 2270, 810, -1);
  CreateObject(WCR2, 2285, 610, -1);
  CreateObject(WCR2, 2896, 1064, -1);
  CreateObject(WCR2, 2896, 1082, -1);
  CreateObject(WCR2, 3040, 1064, -1);
  CreateObject(WCR2, 3058, 1064, -1);
  CreateObject(WCR2, 3058, 1082, -1);
  CreateObject(WCR2, 3058, 1100, -1);
  CreateObject(WCR2, 3076, 1064, -1);
  CreateObject(WCR2, 3076, 1082, -1);
  CreateObject(WCR2, 3076, 1100, -1);
  CreateObject(WCR2, 3094, 1064, -1);
  CreateObject(WCR2, 3094, 1082, -1);
  CreateObject(WCR2, 3210, 1290, -1)->AutoRespawn();

  //Metallkisten
  CreateObject(MWCR, 300, 830, -1)->AutoRespawn();
  CreateObject(MWCR, 890, 920, -1)->AutoRespawn();
  CreateObject(MWCR, 2405, 1100, -1)->AutoRespawn();
  CreateObject(MWCR, 2730, 1100, -1)->AutoRespawn();
  CreateObject(MWCR, 2896, 1100, -1);
  CreateObject(MWCR, 3040, 1082, -1);
  CreateObject(MWCR, 3040, 1100, -1);
  CreateObject(MWCR, 3094, 1100, -1);
  CreateObject(MWCR, 3275, 910, -1)->AutoRespawn();

  //Verbandskisten
  CreateObject(BECR, 350, 920, -1)->AutoRespawn();
  CreateObject(BECR, 510, 1360, -1)->AutoRespawn();
  CreateObject(BECR, 980, 1870, -1)->AutoRespawn();
  CreateObject(BECR, 1200, 1660, -1)->AutoRespawn();
  CreateObject(BECR, 1360, 1110, -1)->AutoRespawn();
  CreateObject(BECR, 1600, 1410, -1)->AutoRespawn();
  CreateObject(BECR, 1865, 1840, -1);
  CreateObject(BECR, 2070, 1560, -1)->AutoRespawn();
  CreateObject(BECR, 2090, 1072, -1);
  CreateObject(BECR, 2750, 910, -1)->AutoRespawn();
  CreateObject(BECR, 3100, 980, -1);
  CreateObject(BECR, 3480, 910, -1)->AutoRespawn();

  //Gerüste
  CreateObject(SFFG, 860, 510, -1)->Set(5);
  CreateObject(SFFG, 860, 560, -1)->Set(5);
  CreateObject(SFFG, 880, 1780, -1)->Set(5);
  CreateObject(SFFG, 940, 1780, -1)->Set(3);
  CreateObject(SFFG, 1250, 1870, -1)->Set(5);
  CreateObject(SFFG, 1280, 1690, -1)->Set(3);
  CreateObject(SFFG, 1280, 1740, -1)->Set(4);
  CreateObject(SFFG, 1360, 1690, -1)->Set(4);
  CreateObject(SFFG, 1360, 1740, -1)->Set(2);
  CreateObject(SFFG, 1480, 1360, -1)->Set(3);
  CreateObject(SFFG, 1480, 1410, -1)->Set(2);
  CreateObject(SFFG, 1480, 1460, -1)->Set(3);
  CreateObject(SFFG, 1480, 1510, -1)->Set(2);
  CreateObject(SFFG, 1480, 1560, -1)->Set(3);
  CreateObject(SFFG, 1630, 1360, -1)->Set(4);
  CreateObject(SFFG, 1630, 1410, -1)->Set(5);
  CreateObject(SFFG, 1630, 1460, -1)->Set(4);
  CreateObject(SFFG, 1630, 1510, -1);
  CreateObject(SFFG, 1630, 1560, -1)->Set(5);
  CreateObject(SFFG, 1640, 1010, -1)->Set(5);
  CreateObject(SFFG, 1640, 1060, -1)->Set(4);
  CreateObject(SFFG, 1640, 1110, -1)->Set(5);
  CreateObject(SFFG, 1710, 1410, -1)->Set(4);
  CreateObject(SFFG, 1710, 1460, -1)->Set(2);
  CreateObject(SFFG, 1710, 1510, -1)->Set(4);
  CreateObject(SFFG, 1710, 1560, -1)->Set(5);
  CreateObject(SFFG, 1735, 1790, -1)->Set(4);
  CreateObject(SFFG, 1735, 1840, -1)->Set(5);
  CreateObject(SFFG, 1735, 1890, -1);
  CreateObject(SFFG, 1765, 1010, -1)->Set(2);
  CreateObject(SFFG, 1765, 1060, -1);
  CreateObject(SFFG, 1765, 1110, -1)->Set(3);
  CreateObject(SFFG, 1790, 1410, -1)->Set(5);
  CreateObject(SFFG, 1790, 1460, -1)->Set(5);
  CreateObject(SFFG, 1790, 1510, -1)->Set(5);
  CreateObject(SFFG, 1790, 1560, -1)->Set(5);
  CreateObject(SFFG, 1795, 1840, -1)->Set(5);
  CreateObject(SFFG, 1855, 1790, -1)->Set(4);
  CreateObject(SFFG, 1855, 1840, -1)->Set(4);
  CreateObject(SFFG, 1855, 1890, -1);
  CreateObject(SFFG, 1870, 1410, -1);
  CreateObject(SFFG, 1870, 1460, -1)->Set(3);
  CreateObject(SFFG, 1870, 1510, -1)->Set(4);
  CreateObject(SFFG, 1870, 1560, -1)->Set(5);
  CreateObject(SFFG, 1890, 1010, -1)->Set(5);
  CreateObject(SFFG, 1890, 1060, -1)->Set(4);
  CreateObject(SFFG, 1890, 1110, -1)->Set(5);
  CreateObject(SFFG, 2060, 1890, -1);
  CreateObject(SFFG, 2080, 1100, -1)->Set(5);
  CreateObject(SFFG, 2140, 1100, -1)->Set(5);
  CreateObject(SFFG, 2200, 1100, -1)->Set(4);
  CreateObject(SFFG, 2260, 1100, -1)->Set(4);
  CreateObject(SFFG, 2780, 1100, -1)->Set(5);
  CreateObject(SFFG, 2840, 1100, -1)->Set(5);

  //Sandsackbarrieren
  CreateObject(SBBA, 600, 230, -1)->Right();
  CreateObject(SBBA, 620, 1010, -1)->Right();
  CreateObject(SBBA, 700, 230, -1)->Right();
  CreateObject(SBBA, 945, 1010, -1);
  CreateObject(SBBA, 1000, 1010, -1)->Right();
  CreateObject(SBBA, 1725, 1110, -1);
  CreateObject(SBBA, 1731, 1890, -1);
  CreateObject(SBBA, 1805, 1110, -1)->Right();
  CreateObject(SBBA, 1830, 1740, -1);
  CreateObject(SBBA, 1860, 1890, -1)->Right();
  CreateObject(SBBA, 2285, 1100, -1)->Right();
  CreateObject(SBBA, 2300, 910, -1)->Right();
  CreateObject(SBBA, 2315, 1560, -1);
  CreateObject(SBBA, 2680, 140, -1)->Right();
  CreateObject(SBBA, 2750, 270, -1)->Right();
  CreateObject(SBBA, 2575, 1100, -1);
  CreateObject(SBBA, 2585, 910, -1);

  //Hinweisschilder
  var sign = CreateObject(SNPT, 985, 180, -1);
  sign->SetAction("Sign6");
  sign->Light();
  var sign = CreateObject(SNPT, 2700, 140, -1);
  sign->SetAction("Sign6");
  sign->Light();

  //Schilder
  CreateObject(WLSN, 785, 225, -1)->Set("Heights");
  CreateObject(WLSN, 1065, 1375, -1)->Set("Heights");
  CreateObject(WLSN, 1185, 225, -1)->Set("Heights");
  CreateObject(WLSN, 2355, 735, -1)->Set("Heights");
  CreateObject(WLSN, 2825, 140, -1)->Set("Heights");

  //Wald
  CreateObject(TRE1, 585, 105,-1);
  CreateObject(GRAS, 575, 100, -1);
  CreateObject(GRAS, 590, 100, -1);
  CreateObject(TRE1, 2300, 380,-1)->SetR(-10);
  CreateObject(GRAS, 2295, 380, -1);
  CreateObject(GRAS, 2310, 370, -1);
  CreateObject(GRAS, 2325, 360, -1);
  CreateObject(TRE1, 2990, 105,-1)->SetR(10);
  CreateObject(GRAS, 2970, 80, -1);
  CreateObject(GRAS, 2980, 80, -1);
  CreateObject(GRAS, 2990, 80, -1);

  //Steine
  CreateObject(STNE, 280, 70, -1);
  CreateObject(STNE, 650, 90, -1);
  CreateObject(STNE, 690, 90, -1);
  CreateObject(STNE, 1510, 510, -1);
  CreateObject(STNE, 2035, 500, -1);
  CreateObject(STNE, 2480, 170, -1);
  CreateObject(STNE, 3100, 60, -1);
  CreateObject(STNE, 3250, 70, -1);

  //Glastische
  CreateObject(GTBL, 340, 740, -1);
  CreateObject(GTBL, 460, 490, -1);
  CreateObject(GTBL, 420, 830, -1);
  CreateObject(GTBL, 465, 740, -1);
  CreateObject(GTBL, 610, 920, -1);
  CreateObject(GTBL, 640, 490, -1);
  CreateObject(GTBL, 690, 920, -1);
  CreateObject(GTBL, 900, 830, -1);
  CreateObject(GTBL, 2640, 910, -1);
  CreateObject(GTBL, 2700, 910, -1);
  CreateObject(GTBL, 3370, 910, -1);

  //Labortisch
  CreateObject(LTBL, 1110, 280, -1);

  //Monitore
  CreateObject(MNI2, 310, 1412, -1);
  CreateObject(MNI2, 478, 728, -1);
  CreateObject(MNI2, 905, 818, -1);
  CreateObject(MNI2, 1100, 268, -1);
  CreateObject(MNI2, 1120, 268, -1);
  CreateObject(MNI2, 1337, 1852, -1);
  CreateObject(MNI2, 2635, 898, -1);
  CreateObject(MNI2, 2650, 898, -1);
  CreateObject(MNI2, 2695, 898, -1);

  //Lampen
  CreateObject(CLGH,315,685,-1);
  CreateObject(CLGH,315,775,-1);
  CreateObject(CLGH,315,865,-1);
  CreateObject(LLGH,380,1760,-1);
  CreateObject(CLGH,430,445,-1);
  CreateObject(CLGH,430,505,-1);
  CreateObject(BLGH,580,1140,-1);
  CreateObject(CLGH,630,445,-1);
  CreateObject(CLGH,630,505,-1);
  CreateObject(LLGH,780,1760,-1);
  CreateObject(LLGH,980,1760,-1);
  CreateObject(BLGH,1020,530,-1);
  CreateObject(CLGH,1020,685,-1);
  CreateObject(CLGH,1020,775,-1);
  CreateObject(CLGH,1020,865,-1);
  CreateObject(LLGH,1000,1850,-1);
  CreateObject(STLH,1130,95,-1);
  CreateObject(CLGH,1185,845,-1);
  CreateObject(LLGH,1320,1675,-1);
  CreateObject(LLGH,1200,1850,-1);
  CreateObject(STLH,1235,205,-1);
  CreateObject(STLH,1255,115,-1);
  CreateObject(STLH,1320,215,-1);
  CreateObject(LBGH,1335,1200, -1);
  CreateObject(LLGH,1415,1075,-1);
  CreateObject(LBGH,2120,1200, -1);
  CreateObject(LLGH,2140,1075,-1);
  CreateObject(LLGH,2470,1075,-1);
  CreateObject(LLGH,2590,210,-1);
  CreateObject(CLGH,2680,1335,-1);
  CreateObject(STLH,2730,1257,-1);
  CreateObject(LLGH,2880,210,-1);
  CreateObject(CLGH,2930,1335,-1);
  CreateObject(STLH,2960,1257,-1);
  CreateObject(BLGH,3020,890,-1);
  CreateObject(BLGH,3020,1050,-1);
  CreateObject(STLH,3150,1257,-1);
  CreateObject(CLGH,3175,1335,-1);
  CreateObject(BLGH,2270,1380,-1);
  CreateObject(CLGH,3420,865,-1);

  //Generator
  var generator = CreateObject(GNRT, 1795, 1890, -1);
  generator->SetCategory(C4D_StaticBack);
  generator->TurnOn();

  //Verbundene Räume
  aDoorWay[22] = CreateObject(GAT3, 250, 465, -1);
  aDoorWay[23] = CreateObject(GAT3, 300, 735, -1);
  aDoorWay[22]->Connect(aDoorWay[23]);
  aDoorWay[00] = CreateObject(GAT3, 380, 1005, -1);
  aDoorWay[01] = CreateObject(GAT3, 480, 1105, -1);
  aDoorWay[00]->Connect(aDoorWay[01]);
  aDoorWay[02] = CreateObject(GAT3, 660, 639, -1);
  aDoorWay[02]->SetClrModulation(RGB(125,125,205));
  aDoorWay[03] = CreateObject(GAT3, 840, 639, -1);
  aDoorWay[03]->SetClrModulation(RGB(125,125,205));
  aDoorWay[02]->Connect(aDoorWay[03]);
  aDoorWay[04] = CreateObject(ROM2, 4575, 900, -1);
  aDoorWay[05] = CreateObject(ROM2, 4530, 790, -1);
  aDoorWay[04]->Connect(aDoorWay[05]);
  aDoorWay[06] = CreateObject(GAT1, 4575, 525, -1);
  aDoorWay[07] = CreateObject(ROOM, 5390, 940, -1);
  aDoorWay[06]->Connect(aDoorWay[07]);
  aDoorWay[08] = CreateObject(GAT3, 950, 1180, -1);
  aDoorWay[08]->SetClrModulation(RGB(125,125,205));
  aDoorWay[09] = CreateObject(GAT3, 972, 1005, -1);
  aDoorWay[08]->Connect(aDoorWay[09]);
  aDoorWay[10] = CreateObject(GAT3, 955, 1395, -1);
  aDoorWay[10]->SetClrModulation(RGB(125,125,205));
  aDoorWay[11] = CreateObject(GAT3, 2460, 1525, -1);
  aDoorWay[11]->SetClrModulation(RGB(125,125,205));
  aDoorWay[10]->Connect(aDoorWay[11]);
  aDoorWay[12] = CreateObject(GAT3, 1125, 1375, -1);
  aDoorWay[13] = CreateObject(GAT3, 1300, 1555, -1);
  aDoorWay[12]->Connect(aDoorWay[13]);
  aDoorWay[14] = CreateObject(GAT3, 2390, 1445, -1);
  aDoorWay[15] = CreateObject(GAT3, 2680, 1285, -1);
  aDoorWay[14]->Connect(aDoorWay[15]);
  aDoorWay[16] = CreateObject(GAT3, 2320, 1445, -1);
  aDoorWay[17] = CreateObject(GAT3, 2345, 1555, -1);
  aDoorWay[16]->Connect(aDoorWay[17]);
  aDoorWay[18] = CreateObject(GAT3, 880, 669, -1);
  aDoorWay[18]->SetClrModulation(RGB(125,125,205));
  aDoorWay[19] = CreateObject(GAT3, 880, 1041, -1);
  aDoorWay[19]->SetClrModulation(RGB(125,125,205));
  aDoorWay[18]->Connect(aDoorWay[19]);
  aDoorWay[24] = CreateObject(GAT1, 1420, 455, -1);
  aDoorWay[25] = CreateObject(GAT3, 1325, 609, -1);
  aDoorWay[24]->Connect(aDoorWay[25]);
  aDoorWay[26] = CreateObject(GAT1, 2140, 455, -1);
  aDoorWay[27] = CreateObject(GAT3, 2225, 609, -1);
  aDoorWay[26]->Connect(aDoorWay[27]);
  aDoorWay[28] = CreateObject(GAT1, 860, 1740, -1);
  aDoorWay[29] = CreateObject(GAT3, 2390, 1815, -1);
  aDoorWay[28]->Connect(aDoorWay[29]);
  aDoorWay[33] = CreateObject(GAT1, 1795, 1610, -1);
  aDoorWay[34] = CreateObject(GAT3, 2085, 1779, -1);
  aDoorWay[33]->Connect(aDoorWay[34]);

  //Stahltore und Konsolen
  aDoorWay[39] = CreateObject(HNG4, 1440, 540, -1);
  aDoorWay[40] = CreateObject(HNG4, 2080, 540, -1);
  var autod = CreateObject(HNG4, 1450, 850, -1);
  CreateObject(CONS, 1500, 935, -1)->Set(autod);
  autod = CreateObject(HNG4, 2080, 850, -1);
  CreateObject(CONS, 2020, 905, -1)->Set(autod);
  aDoorWay[41] = CreateObject(HNG4, 2990, 520, -1);

  //Kräne
  CreateObject(CRN1, 1770, 620, -1)->Set(53);
  CreateObject(CRN1, 2925, 960, -1)->Set(40);

  //Soundkulisse

  //Lava
  CreateObject(SE4K, 400, 2030, -1)->Set("Lava*",1200,300, 75);
  CreateObject(SE4K, 1100, 2030, -1)->Set("Lava*",1200,300, 75);
  CreateObject(SE4K, 1800, 2030, -1)->Set("Lava*",1200,300, 75);
  CreateObject(SE4K, 2900, 2030, -1)->Set("Lava*",1200,300, 75);

  //Erdrutsche
  CreateObject(SE4K, 480, 1600, -1)->Set("FallingDirt*.ogg",800,200, 75);
  CreateObject(SE4K, 1240, 1900, -1)->Set("FallingDirt*.ogg",800,200, 75);
  CreateObject(SE4K, 2830, 1870, -1)->Set("FallingDirt*.ogg",800,200, 75);

  //Wind
  CreateObject(SE4K, 1860, 200, -1)->Set("WindSound*.ogg",1000,200, 75);

  //Innenbereich
  CreateObject(SE4K, 580, 600, -1)->Set("Interior*.ogg",700,100, 75);
  CreateObject(SE4K, 600, 1100, -1)->Set("InteriorMetal*.ogg",1000,300, 25,50);
  CreateObject(SE4K, 620, 1100, -1)->Set("Interior*.ogg",700,100, 75);
  CreateObject(SE4K, 1230, 220, -1)->Set("InteriorStress*.ogg",700,100, 75);
  CreateObject(SE4K, 1770, 700, -1)->Set("Interior*.ogg",700,100, 75);
  CreateObject(SE4K, 1770, 1000, -1)->Set("Interior*.ogg",700,100, 75);
  CreateObject(SE4K, 1800, 1400, -1)->Set("Interior*.ogg",700,100, 75);
  CreateObject(SE4K, 2015, 1370, -1)->Set("InteriorMetal*.ogg",1000,300, 25,50);
  CreateObject(SE4K, 2380, 850, -1)->Set("InteriorStress*.ogg",700,100, 75);
  CreateObject(SE4K, 3740, 210, -1)->Set("Interior*.ogg",700,100, 75);
  CreateObject(SE4K, 3080, 1170, -1)->Set("Interior*.ogg",700,100, 75);
  CreateObject(SE4K, 3380, 980, -1)->Set("InteriorMetal*.ogg",1000,300, 25,50);
  
      //Aufzüge
    CreateObject(LFTP, 785, 244, -1)->SetLimits(235,670);
    CreateObject(LFTP, 785, 754, -1)->SetLimits(745,1320);
    CreateObject(LFTP, 1185, 184, -1)->SetLimits(175,820);
    CreateObject(LFTP, 1550, 734, -1)->DisableVertical();
    CreateObject(LFTP, 2355, 754, -1)->SetLimits(745,1460);
    CreateObject(LFTP, 2825, 154, -1)->SetLimits(145,920);

    //Stahltore und Konsolen
    CreateObject(CONS, 1540, 505, -1)->Set(aDoorWay[39]);
    CreateObject(CONS, 1985, 505, -1)->Set(aDoorWay[40]);

    //Boden
    DrawMaterialQuad("Wall-Metal4", 330,1200, 440,1200, 440,1240, 330,1240);
    DrawMaterialQuad("Wall-Stripes", 360,1200, 410,1200, 410,1210, 360,1210);
    DrawMaterialQuad("Wall-Concrete2", 340,1240, 430,1240, 430,1250, 340,1250);

    DrawMaterialQuad("Wall-Concrete2", 440,560, 460,560, 460,600, 440,600);

    DrawMaterialQuad("Wall-Stripes", 760,1200, 810,1200, 810,1210, 760,1210);
    DrawMaterialQuad("Wall-Metal4", 750,1210, 820,1210, 820,1240, 750,1240);
    DrawMaterialQuad("Wall-Bricks1", 750,1240, 820,1240, 820,1280, 750,1280);
    DrawMaterialQuad("Earth-ROUGH", 750,1280, 820,1280, 820,1331, 750,1331);

    DrawMaterialQuad("Wall-Concrete3", 1110,1110, 1140,1110, 1160,1120, 1110,1120);
    DrawMaterialQuad("Wall-Concrete3", 1260,1110, 1230,1110, 1210,1120, 1260,1120);
    DrawMaterialQuad("Wall-Plate", 1100,1120, 1260,1120, 1260,1230, 1100,1230);
    DrawMaterialQuad("Wall-Concrete2", 1110,1230, 1260,1230, 1260,1240, 1110,1240);

    DrawMaterialQuad("Wall-Stripes", 1380,1110, 1450,1110, 1450,1120, 1380,1120);
    DrawMaterialQuad("Wall-Plate", 1370,1120, 1460,1120, 1460,1210, 1370,1210);
    DrawMaterialQuad("Wall-Stripes", 1380,1210, 1450,1210, 1450,1221, 1380,1221);

    DrawMaterialQuad("Wall-Stripes", 2320,1110, 2390,1110, 2390,1120, 2320,1120);
    DrawMaterialQuad("Wall-Bricks1", 2290,1120, 2440,1120, 2440,1160, 2290,1160);
    DrawMaterialQuad("Wall-Concrete2", 2300,1160, 2430,1160, 2430,1170, 2300,1170);

    DrawMaterialQuad("Wall-Concrete3", 3130,1100, 3160,1100, 3160,1110, 3130,1110);
    DrawMaterialQuad("Wall-Metal4", 3130,1110, 3160,1110, 3160,1120, 3130,1120);
    DrawMaterialQuad("Wall-Bricks1", 3130,1120, 3160,1120, 3160,1160, 3130,1160);

    DrawMaterialQuad("Wall-Stripes", 3250,1100, 3300,1100, 3300,1120, 3250,1120);

    //Automaten
    var store = CreateObject(WPVM,610, 560,-1);
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
    store = CreateObject(WPVM,2840, 1100,-1);
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

    //Artilleriebatterien
    CreateObject(ATBY,1185,100,-1);
    CreateObject(ATBY,2825,100,-1);

    //Geschützstellungen
    CreateObject(GNET, 610, 1010, -1)->Set(SATW,90);
    CreateObject(GNET, 2580, 1100, -1)->Set(SATW,-90);

    //Versorgungskisten (Dragnin)
    CreateObject(AMCT, 1110, 280, -1)->Set(DGNN);
    CreateObject(AMCT, 2870, 910, -1)->Set(DGNN);

    //Versorgungskisten (Handgranaten)
    CreateObject(AMCT, 365, 830, -1)->Set(FGRN);
    CreateObject(AMCT, 1022, 580, -1)->Set(FGRN);
    CreateObject(AMCT, 2440, 910, -1)->Set(FGRN);
    CreateObject(AMCT, 3425, 910, -1)->Set(FGRN);

    //Versorgungskiste (Phosphorgranaten)
    CreateObject(AMCT, 1765, 820, -1)->Set(PGRN);

    //Versorgungskisten (Revolver)
    CreateObject(AMCT, 385, 230, -1)->Set(RVLR);
    CreateObject(AMCT, 2620, 270, -1)->Set(RVLR);

    //Versorgungskisten (APW)
    CreateObject(AMCT, 515, 1190, -1)->Set(ATWN);
    CreateObject(AMCT, 3275, 1100, -1)->Set(ATWN);

    //Hinweisschilder
    CreateObject(SGNP, 65, 90, -1);
    CreateObject(SGNP, 210, 40, -1);
    CreateObject(SGNP, 3370, 30, -1);
    CreateObject(SGNP, 3590, 70, -1);
    CreateObject(LADR, 385, 1195, -1)->Set(17);
    CreateObject(LADR, 1130, 1098, -1)->Set(10);

    CreateObject(LADR, 1240, 1098, -1)->Set(100);

    //Munition
    if(!FindObject(NOAM))
    {
      //Versorgungskisten (Kugeln)
      CreateObject(AMCT, 525, 230, -1)->Set(ABOX);
      CreateObject(AMCT, 1640, 1110, -1)->Set(ABOX);
      CreateObject(AMCT, 2645, 270, -1)->Set(ABOX);

      //Versorgungskiste (Gewehrgranaten)
      CreateObject(AMCT, 1890, 1110, -1)->Set(GBOX);

      //Kugeln
      PlaceSpawnpoint(ABOX, 740, 915);
      PlaceSpawnpoint(ABOX, 2780, 905);

      //Gewehrgranaten
      PlaceSpawnpoint(GBOX, 580, 735);
      PlaceSpawnpoint(GBOX, 3220, 785);

      //Raketen
      PlaceSpawnpoint(MBOX, 960, 825);
      PlaceSpawnpoint(MBOX, 2220, 905);
    }
  PlaceAnimal(ST5B)->CreateContents(ENAP);
  for (var i = 0; i < 5; i++)
  {
    PlaceAnimal(ST5B);
  }
}

public func Destruction()
{
	EliminatePlayer(GetPlayerByName("Stippel"));
}

public func IsFulfilled()
{
	return true;
}

public func GetCoordinates()
{
	return [1000, 1000];
}
