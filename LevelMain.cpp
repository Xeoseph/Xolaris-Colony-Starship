#include <Outpost2DLL/Outpost2DLL.h>	// Main Outpost 2 header to interface with the game
#include <OP2Helper/OP2Helper.h>		// Optional header to make level building easier


// Note: These exports are required by Outpost2.exe from every level
//		 DLL. They give values for the map and tech trees used by the
//		 level and a description to place in the level listbox. The
//		 last export is used to define characteristics of the level.
//		 See RequiredExports.h for more details.
//		 ** Be sure to set these when you build your own level**
// Required data exports  (Description, Map, TechTree, GameType, NumPlayers)
ExportLevelDetails("Xolaris Starship", "Outcaster.map", "MULTITEK.TXT", MissionTypes::Colony, 3)
//char MapName[] = "Outcaster.map";
//char LevelDesc[] = "Colony, '<Xolaris Starship>' map";
//char TechtreeName[] = "MULTITEK.TXT";
// Alternative style allowing more advanced settings such as AI players and max tech level:
// Required data exports  (Description, Map, TechTree, GameType, NumPlayers, maxTechLevel, bUnitOnlyMission, numAIPlayers)
// ExportLevelDetailsFullEx("5P, LoS, '<map name>'", "on6_01.map", "MULTITEK.TXT", MultiLastOneStanding, 6, 12, false, 1)


// Note: Place any global variables in the following struct so that your
//		level works right when saving and loading.
// Note: Feel free to rename the following struct and variable declaration to whatever you want
// Holder for global script variables (for Saved game files)
//
struct ScriptGlobal
{
} scriptGlobal;
// This macro automatically generates the GetSaveRegions export which tells Outpost2.exe about
// the scriptGlobal variable. Data in this struct is preserved during game save/load.
// Note: This implies all level data must be statically sized.
Unit AI_VF1;
Unit AI_SF1;
Unit AI_COS1;
Unit AI_COS2;
Unit AI_COM1;
Unit AI_COM2;
Unit AI_ROM1;
Unit AI_RM;
Unit AI_EW;
Unit AI_CT1;
Unit AI_CT2;
Unit AI_CT3;
Unit AI_CT4;
Unit AI_CV1;
Unit AI_CV2;
Unit AI_CV3;
MiningGroup CommonMining1;
MiningGroup CommonMining2;
BuildingGroup Construction;
BuildingGroup RebuildMines;
BuildingGroup Reinforce;
ExportSaveLoadData(scriptGlobal);

//Stuff Goes Below Here First

// Note: The following function is called once by Outpost2.exe when the
//		 level is first initialized. This is where you want to create
//		 all the initial units and structures as well as setup any 
//		 map/level environment settings such as day and night.
// Note: Returns true if level loaded successfully and is playable, false to abort
Export int InitProc()
{
	// Player 0 Yellow Plymouth Human.
	Player[0].GoPlymouth();
	Player[0].SetColorNumber(3);
	Unit x;
	TethysGame::FreeMoraleLevel(0);	// Set morale to unsteady
	TethysGame::CreateUnit(x, mapCommandCenter, LOCATION(113 + 31, 111 - 1), 0, mapNone, 0);
	TethysGame::CreateUnit(x, mapStructureFactory, LOCATION(113 + 31, 100 - 1), 0, mapNone, 0);
	x.SetFactoryCargo(0, mapNursery, mapNone);
	x.SetFactoryCargo(1, mapUniversity, mapNone);
	x.SetFactoryCargo(2, mapMedicalCenter, mapNone);
	x.SetFactoryCargo(3, mapResidence, mapNone);
	x.SetFactoryCargo(4, mapResidence, mapNone);
	TethysGame::CreateUnit(x, mapAgridome, LOCATION(119 + 31, 111 - 1), 0, mapNone, 0);
	TethysGame::CreateUnit(x, mapAgridome, LOCATION(119 + 31, 117 - 1), 0, mapNone, 0);
	TethysGame::CreateUnit(x, mapStandardLab, LOCATION(104 + 31, 111 - 1), 0, mapNone, 0);
	TethysGame::CreateUnit(x, mapResidence, LOCATION(125 + 31, 111 - 1), 0, mapNone, 0);
	TethysGame::CreateUnit(x, mapResidence, LOCATION(125 + 31, 117 - 1), 0, mapNone, 0);
	TethysGame::CreateUnit(x, mapTokamak, LOCATION(152 + 31, 115 - 1), 0, mapNone, 0);
	TethysGame::CreateUnit(x, mapTokamak, LOCATION(148 + 31, 115 - 1), 0, mapNone, 0);
	TethysGame::CreateUnit(x, mapGuardPost, LOCATION(85 + 31, 122 - 1), 0, mapEMP, 0);
	TethysGame::CreateUnit(x, mapGuardPost, LOCATION(156 + 31, 123 - 1), 0, mapEMP, 0);
	TethysGame::CreateUnit(x, mapGuardPost, LOCATION(144 + 31, 132 - 1), 0, mapEMP, 0);
	TethysGame::CreateUnit(x, mapGuardPost, LOCATION(149 + 31, 123 - 1), 0, mapEMP, 0);
	TethysGame::CreateUnit(x, mapGuardPost, LOCATION(91 + 31, 94 - 1), 0, mapEMP, 0);
	TethysGame::CreateUnit(x, mapGuardPost, LOCATION(80 + 31, 110 - 1), 0, mapEMP, 0);
	TethysGame::CreateUnit(x, mapGuardPost, LOCATION(149 + 31, 105 - 1), 0, mapEMP, 0);
	TethysGame::CreateUnit(x, mapGuardPost, LOCATION(145 + 31, 92 - 1), 0, mapEMP, 0);
	TethysGame::CreateUnit(x, mapConVec, LOCATION(122 + 31, 102 - 1), 0, mapTokamak, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapConVec, LOCATION(118 + 31, 102 - 1), 0, mapCommonStorage, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapConVec, LOCATION(120 + 31, 102 - 1), 0, mapAgridome, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapCargoTruck, LOCATION(100 + 31, 122 - 1), 0, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapCargoTruck, LOCATION(101 + 31, 122 - 1), 0, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapCargoTruck, LOCATION(102 + 31, 122 - 1), 0, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapCargoTruck, LOCATION(103 + 31, 122 - 1), 0, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapRoboMiner, LOCATION(105 + 31, 122 - 1), 0, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapRoboMiner, LOCATION(107 + 31, 122 - 1), 0, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapRoboSurveyor, LOCATION(106 + 31, 122 - 1), 0, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapEarthworker, LOCATION(102 + 31, 112 - 1), 0, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapRoboDozer, LOCATION(101 + 31, 112 - 1), 0, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateBeacon(mapMiningBeacon, 109 + 31, 131 - 1, 0, 0, 2);
	TethysGame::CreateBeacon(mapMiningBeacon, 98 + 31, 131 - 1, 0, 0, 2);
	TethysGame::CreateBeacon(mapMiningBeacon, 143 + 31, 99 - 1, 1, 0, 2);
	TethysGame::CreateUnit(x, mapCommonOreSmelter, LOCATION(104 + 31, 120 - 1), 0, mapNone, 0);
	CreateTubeOrWallLine(104 + 31, 118 - 1, 104 + 31, 113 - 1, mapTube);
	CreateTubeOrWallLine(116 + 31, 100 - 1, 119 + 31, 100 - 1, mapTube);
	CreateTubeOrWallLine(110 + 31, 100 - 1, 106 + 31, 100 - 1, mapTube);
	CreateTubeOrWallLine(107 + 31, 111 - 1, 111 + 31, 111 - 1, mapTube);
	CreateTubeOrWallLine(116 + 31, 111 - 1, 117 + 31, 111 - 1, mapTube);
	CreateTubeOrWallLine(122 + 31, 111 - 1, 123 + 31, 111 - 1, mapTube);
	CreateTubeOrWallLine(122 + 31, 117 - 1, 123 + 31, 117 - 1, mapTube);
	CreateTubeOrWallLine(113 + 31, 109 - 1, 113 + 31, 103 - 1, mapTube);
	CreateTubeOrWallLine(119 + 31, 113 - 1, 119 + 31, 115 - 1, mapTube);
	CreateTubeOrWallLine(125 + 31, 113 - 1, 125 + 31, 115 - 1, mapTube);
	CreateTubeOrWallLine(83 + 31, 124 - 1, 83 + 31, 120 - 1, mapWall);
	CreateTubeOrWallLine(84 + 31, 120 - 1, 90 + 31, 120 - 1, mapWall);
	CreateTubeOrWallLine(146 + 31, 136 - 1, 146 + 31, 130 - 1, mapWall);
	CreateTubeOrWallLine(147 + 31, 125 - 1, 158 + 31, 125 - 1, mapWall);
	CreateTubeOrWallLine(158 + 31, 120 - 1, 158 + 31, 124 - 1, mapWall);
	CreateTubeOrWallLine(89 + 31, 96 - 1, 89 + 31, 92 - 1, mapWall);
	CreateTubeOrWallLine(92 + 31, 92 - 1, 90 + 31, 92 - 1, mapWall);
	CreateTubeOrWallLine(142 + 31, 90 - 1, 147 + 31, 90 - 1, mapWall);
	CreateTubeOrWallLine(151 + 31, 106 - 1, 151 + 31, 95 - 1, mapWall);
	CreateTubeOrWallLine(145 + 31, 130 - 1, 139 + 31, 130 - 1, mapWall);
	CreateTubeOrWallLine(111 + 31, 108 - 1, 79 + 31, 108 - 1, mapWall);
	CreateTubeOrWallLine(144 + 31, 108 - 1, 115 + 31, 108 - 1, mapWall);
	CreateTubeOrWallLine(116 + 31, 107 - 1, 116 + 31, 101 - 1, mapWall);
	CreateTubeOrWallLine(116 + 31, 99 - 1, 116 + 31, 97 - 1, mapWall);
	CreateTubeOrWallLine(109 + 31, 107 - 1, 109 + 31, 101 - 1, mapWall);
	CreateTubeOrWallLine(109 + 31, 99 - 1, 109 + 31, 97 - 1, mapWall);
	CreateTubeOrWallLine(110 + 31, 97 - 1, 115 + 31, 97 - 1, mapWall);
	Player[0].SetKids(27); 
	Player[0].SetWorkers(35);  
	Player[0].SetScientists(20);	
	Player[0].SetFoodStored(1200);	
	Player[0].SetOre(6000);  
	//Player[0].MarkResearchComplete(techID);	// Marks specified technology as completed // For Reference
	//Player 1 Blue Eden AI
	Player[1].GoEden();
	Player[1].SetColorNumber(0);
	//Player 2 Red Plymouth AI
	Player[2].GoPlymouth();
	Player[2].SetColorNumber(1);
	TethysGame::CreateBeacon(mapMiningBeacon, 25 + 31, 198 - 1, 1, 0, 2);
	TethysGame::CreateBeacon(mapMiningBeacon, 15 + 31, 198 - 1, 0, 0, 2);
	TethysGame::CreateBeacon(mapMiningBeacon, 35 + 31, 198 - 1, 0, 0, 2);
	TethysGame::CreateUnit(x, mapTokamak, LOCATION(9 + 31, 167 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapCommandCenter, LOCATION(15 + 31, 182 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapAgridome, LOCATION(44 + 31, 182 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(AI_SF1, mapStructureFactory, LOCATION(25 + 31, 182 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(AI_VF1, mapVehicleFactory, LOCATION(35 + 31, 182 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(AI_COS1, mapCommonOreSmelter, LOCATION(15 + 31, 192 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(AI_COM1, mapCommonOreMine, LOCATION(15 + 31, 198 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(AI_CT1, mapCargoTruck, LOCATION(12 + 31, 194 - 1), 2, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(AI_CT2, mapCargoTruck, LOCATION(13 + 31, 194 - 1), 2, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(AI_CV1, mapConVec, LOCATION(22 + 31, 184 - 1), 2, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(AI_CV2, mapConVec, LOCATION(27 + 31, 184 - 1), 2, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(AI_CV3, mapConVec, LOCATION(25 + 31, 184 - 1), 2, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(AI_RM, mapRoboMiner, LOCATION(32 + 31, 184 - 1), 2, mapNone, 2);
	x.DoSetLights(1);
	TethysGame::CreateUnit(AI_EW, mapEarthworker, LOCATION(33 + 31, 184 - 1), 2, mapNone, 2);
	x.DoSetLights(1);
	CreateTubeOrWallLine(38 + 31, 182 - 1, 42 + 31, 182 - 1, mapTube);
	CreateTubeOrWallLine(18 + 31, 182 - 1, 22 + 31, 182 - 1, mapTube);
	CreateTubeOrWallLine(28 + 31, 182 - 1, 32 + 31, 182 - 1, mapTube);
	CreateTubeOrWallLine(15 + 31, 184 - 1, 15 + 31, 190 - 1, mapTube);
	Player[2].SetKids(27); 
	Player[2].SetWorkers(35);  
	Player[2].SetScientists(20);	
	Player[2].SetFoodStored(1200);	
	Player[2].SetOre(6000);  
	//Buildings Contruction for Player 2
	Construction = CreateBuildingGroup(Player[2]);
	MAP_RECT ConVecBox(1 + 31, 161 - 1, 89 + 31, 208 - 1);
	Construction.SetRect(ConVecBox);
	Construction.TakeUnit(AI_SF1);
	Construction.TakeUnit(AI_CV1);
	Construction.TakeUnit(AI_CV2);
	Construction.TakeUnit(AI_CV3);
	Construction.SetTargCount(mapConVec, mapNone, 3);

	Construction.RecordBuilding(LOCATION(15 + 31, 182 - 1), mapCommandCenter, mapNone);
	Construction.RecordBuilding(LOCATION(9 + 31, 167 - 1), mapTokamak, mapNone);
	Construction.RecordBuilding(LOCATION(15 + 31, 192 - 1), mapCommonOreSmelter, mapNone);
	Construction.RecordBuilding(LOCATION(44 + 31, 182 - 1), mapAgridome, mapNone);
	Construction.RecordBuilding(LOCATION(35 + 31, 182 - 1), mapVehicleFactory, mapNone);
	Construction.RecordBuilding(LOCATION(25 + 31, 168 - 1), mapSpaceport, mapNone);
	Construction.RecordBuilding(LOCATION(35 + 31, 192 - 1), mapCommonOreSmelter, mapNone);
	Construction.RecordBuilding(LOCATION(25 + 31, 192 - 1), mapRareOreSmelter, mapNone);
	RebuildMines = CreateBuildingGroup(Player[2]);
	MAP_RECT MinerBox(11 + 31, 189 - 1, 52 + 31, 200 - 1);
	RebuildMines.SetRect(MinerBox);
	RebuildMines.TakeUnit(AI_RM);
	RebuildMines.TakeUnit(AI_COM1);
	RebuildMines.TakeUnit(AI_ROM1);
	RebuildMines.SetTargCount(mapRoboMiner, mapNone, 1);
	RebuildMines.SetTargCount(mapCommonOreMine, mapNone, 2);
	RebuildMines.SetTargCount(mapRareOreMine, mapNone, 1);
	// Sets up the first mining group and assigns it to player 2
	CommonMining1 = CreateMiningGroup(Player[2]); 
	MAP_RECT CommonBox1(14 + 31, 193 - 1, 16 + 31, 198 - 1);
	CommonMining1.Setup(AI_COM1, AI_COS1, CommonBox1);
	CommonMining1.TakeUnit(AI_CT1);
	CommonMining1.TakeUnit(AI_CT2);
	CommonMining1.SetTargCount(mapCargoTruck, mapNone, 2);
	//Sets up 2nd mine for plymouth assigned to player 2 AI
	//CommonMining2 = CreateMiningGroup(Player[2]);
	//MAP_RECT CommonBox2(34 + 31, 193 - 1, 36 + 31, 198 - 1);
	//CommonMining2.Setup(AI_COM2, AI_COS2, CommonBox2);
	//CommonMining2.TakeUnit(AI_CT3);
	//CommonMining2.TakeUnit(AI_CT4);
	//CommonMining2.SetTargCount(mapCargoTruck, mapNone, 2);
	Reinforce = CreateBuildingGroup(Player[2]);
	Reinforce.TakeUnit(AI_VF1);
	Reinforce.RecordVehReinforceGroup(CommonMining1, 1500);
	//Reinforce.RecordVehReinforceGroup(CommonMining2, 1500);
	Reinforce.RecordVehReinforceGroup(Construction, 1000);
	Reinforce.RecordVehReinforceGroup(RebuildMines, 3000);

	return 1; // return 1 if OK; 0 on failure
}


// Note: The following function seems to be intended for use in
//		 controlling an AI. It is called once every game cycle. 
//		 Use it for whatever code needs to run on a continual basis.
// Note: The standard level DLLs released by Sierra leave this function
//		 empty and handle all AI controls through triggers.
Export void AIProc() 
{


}


// Note: This is a trigger callback function. This function is
//		 intentionally left empty and is used as the trigger
//		 callback function for triggers that don't want or need
//		 any special callback function.
// Note: The use of Export is used by all trigger functions
//		 to ensure they are exported correctly.
Export void NoResponseToTrigger()
{
}


