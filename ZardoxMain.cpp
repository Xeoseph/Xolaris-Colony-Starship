#include <Outpost2DLL/Outpost2DLL.h>	// Main Outpost 2 header to interface with the game
#include <OP2Helper/OP2Helper.h>		// Optional header to make level building easier
#include <Outpost2DLL/game/Structs.h>
#include <Outpost2DLL/game/Groups.h>
#include <Outpost2DLL/game/Globals.h>


ExportLevelDetails("Xolaris Starship", "Outcaster.map", "MULTITEK.TXT", MissionTypes::Colony, 3)

// Put any variables or handles that need to persist across saved games here.
// Things like triggers that are used for victory/defeat conditions, or AI groups that get new orders/units assigned to them.
// You don't need to track individual units unless they are used more than once by the mission script.
struct ScriptGlobal
{
	MiningGroup CommonMining1;
	MiningGroup CommonMining2;
	BuildingGroup Construction;
	//BuildingGroup RebuildMines;	// You actually don't need this, you can record a Common Ore Mine* to a group with a Vehicle Factory in it, and it will automatically build a miner to (re)build the mine.
	                                // *Never directly create or have an AI unit group try to build a Rare Ore Mine.  Always tell it to build a Common Ore Mine, even on a rare ore beacon.
	BuildingGroup Reinforce;
	Trigger AiExpansionTrigger;
} scriptGlobal;
ExportSaveLoadData(scriptGlobal);
// To reference data in this structure, use scriptGlobal.VariableNameHere (so for example, to access CommonMining1, you'd use scriptGlobal.CommonMining1)



void SetupHumanPlayer()
{
	Player[0].GoPlymouth();
	Player[0].SetColorNumber(3);
	Unit x;
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
}

void SetupBlueEdenPlayer()
{
	Unit x;
	Player[1].GoEden();
	Player[1].SetColorNumber(0);
}

void SetupRedPlymouthPlayer()
{
	// Define AI unit groups before doing anything else.  That way you know they're already initialized when you try to add units to them later.
	scriptGlobal.Construction = CreateBuildingGroup(2);
	MAP_RECT ConVecBox(22 + 31, 181 - 1, 30 + 31, 184 - 1);	// Your original box was way too big.  You don't need it to encompass the entire base.  Try to keep it small and centered around the Structure Factory.
	scriptGlobal.Construction.SetRect(ConVecBox);
	scriptGlobal.Construction.SetTargCount(mapConVec, mapNone, 3);
	scriptGlobal.Construction.SetTargCount(mapEarthworker, mapNone, 1);	// You forgot this ;P

	scriptGlobal.CommonMining1 = CreateMiningGroup(2);
	MAP_RECT CommonBox1(14 + 31, 193 - 1, 16 + 31, 198 - 1);

	scriptGlobal.CommonMining2 = CreateMiningGroup(2);
	MAP_RECT CommonBox2(34 + 31, 193 - 1, 36 + 31, 198 - 1);

	// Rare ore group definition will go here and will look something like this:
	// scriptGlobal.RareMining = CreateMiningGroup(Player[2]);

	//scriptGlobal.Reinforce = CreateBuildingGroup(Player[2]);
	scriptGlobal.Reinforce = CreateBuildingGroup(2);
	MAP_RECT MinerBox(11 + 31, 189 - 1, 52 + 31, 200 - 1);
	scriptGlobal.Reinforce.SetRect(MinerBox);
	scriptGlobal.Reinforce.SetTargCount(mapRoboMiner, mapNone, 2);
	scriptGlobal.Reinforce.RecordVehReinforceGroup(scriptGlobal.Reinforce, 10);
	
	Unit x, Smelter;

	// Player setup
	Player[2].CenterViewOn(15 + 31, 182 - 1); // Not strictly necessary but I like to do it anyways
	Player[2].GoPlymouth();
	Player[2].SetColorNumber(1);
	Player[2].SetOre(6000);
	// Note: AI population and food are locked; trying to change them does nothing.
	
	//Start Northern Base Placement:
	TethysGame::CreateUnit(x, mapMHDGenerator, LOCATION(11 + 31, 16 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapMHDGenerator, LOCATION(4 + 31, 16 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapCommandCenter, LOCATION(28 + 31, 8 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapAdvancedLab, LOCATION(43 + 31, 8 - 1), 2, mapNone, 0);
	CreateTubeOrWallLine(31 + 31, 8 - 1, 41 + 31, 8 - 1, mapTube);
	CreateTubeOrWallLine(28 + 31, 10 - 1, 28 + 31, 25 - 1, mapTube);
	CreateTubeOrWallLine(25 + 31, 5 - 1, 31 + 31, 5 - 1, mapWall);
	CreateTubeOrWallLine(25 + 31, 6 - 1, 25 + 31, 10 - 1, mapWall);
	CreateTubeOrWallLine(31 + 31, 7 - 1, 31 + 31, 6 - 1, mapWall);
	CreateTubeOrWallLine(31 + 31, 9 - 1, 31 + 31, 10 - 1, mapWall);
	CreateTubeOrWallLine(26 + 31, 10 - 1, 27 + 31, 10 - 1, mapWall);
	CreateTubeOrWallLine(29 + 31, 10 - 1, 30 + 31, 10 - 1, mapWall);
	CreateTubeOrWallLine(40 + 31, 7 - 1, 40 + 31, 5 - 1, mapWall);
	CreateTubeOrWallLine(41 + 31, 5 - 1, 46 + 31, 5 - 1, mapWall);
	CreateTubeOrWallLine(46 + 31, 6 - 1, 46 + 31, 11 - 1, mapWall);
	CreateTubeOrWallLine(45 + 31, 11 - 1, 40 + 31, 11 - 1, mapWall);
	CreateTubeOrWallLine(40 + 31, 10 - 1, 40 + 31, 9 - 1, mapWall);

	//End Northern Base Placement:
	
	//Start Southern Base Placement:
	TethysGame::CreateBeacon(mapMiningBeacon, 25 + 31, 198 - 1, 1, 0, 2);
	TethysGame::CreateBeacon(mapMiningBeacon, 15 + 31, 198 - 1, 0, 0, 2);
	TethysGame::CreateBeacon(mapMiningBeacon, 35 + 31, 198 - 1, 0, 0, 2);
	TethysGame::CreateUnit(x, mapTokamak, LOCATION(9 + 31, 167 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapMHDGenerator, LOCATION(9 + 31, 171 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapCommandCenter, LOCATION(15 + 31, 182 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapAgridome, LOCATION(44 + 31, 182 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapAgridome, LOCATION(44 + 31, 175 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapNursery, LOCATION(48 + 31, 175 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapUniversity, LOCATION(48 + 31, 182 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapGuardPost, LOCATION(50 + 31, 168 - 1), 2, mapRPG, 0);
	TethysGame::CreateUnit(x, mapGuardPost, LOCATION(79 + 31, 182 - 1), 2, mapRPG, 0);
	TethysGame::CreateUnit(x, mapGuardPost, LOCATION(40 + 31, 200 - 1), 2, mapRPG, 0);
	TethysGame::CreateUnit(x, mapGuardPost, LOCATION(28 + 31, 200 - 1), 2, mapRPG, 0);


	// Place units for construction group
	TethysGame::CreateUnit(x, mapStructureFactory, LOCATION(25 + 31, 182 - 1), 2, mapNone, 0);
	scriptGlobal.Construction.TakeUnit(x);
	TethysGame::CreateUnit(x, mapConVec, LOCATION(22 + 31, 184 - 1), 2, mapNone, 2);
	scriptGlobal.Construction.TakeUnit(x);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapConVec, LOCATION(27 + 31, 184 - 1), 2, mapNone, 2);
	scriptGlobal.Construction.TakeUnit(x);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapConVec, LOCATION(25 + 31, 184 - 1), 2, mapNone, 2);
	scriptGlobal.Construction.TakeUnit(x);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapEarthworker, LOCATION(33 + 31, 184 - 1), 2, mapNone, 2);
	scriptGlobal.Construction.TakeUnit(x);
	x.DoSetLights(1);

	// Place units for common mining group #1 and finalize setup
	TethysGame::CreateUnit(Smelter, mapCommonOreSmelter, LOCATION(15 + 31, 192 - 1), 2, mapNone, 0);
	TethysGame::CreateUnit(x, mapCommonOreMine, LOCATION(15 + 31, 198 - 1), 2, mapNone, 0);
	scriptGlobal.CommonMining1.Setup(x, Smelter, CommonBox1);
	TethysGame::CreateUnit(x, mapCargoTruck, LOCATION(12 + 31, 194 - 1), 2, mapNone, 2);
	scriptGlobal.CommonMining1.TakeUnit(x);
	x.DoSetLights(1);
	TethysGame::CreateUnit(x, mapCargoTruck, LOCATION(13 + 31, 194 - 1), 2, mapNone, 2);
	scriptGlobal.CommonMining1.TakeUnit(x);
	x.DoSetLights(1);
	scriptGlobal.CommonMining1.SetTargCount(mapCargoTruck, mapNone, 2);
	
	// Place units for vehicle factory group and finalize setup
	TethysGame::CreateUnit(x, mapVehicleFactory, LOCATION(35 + 31, 182 - 1), 2, mapNone, 0);
	scriptGlobal.Reinforce.TakeUnit(x);
	TethysGame::CreateUnit(x, mapRoboMiner, LOCATION(32 + 31, 184 - 1), 2, mapNone, 2);
	scriptGlobal.Reinforce.TakeUnit(x);
	x.DoSetLights(1);
	scriptGlobal.Reinforce.RecordVehReinforceGroup(scriptGlobal.CommonMining1, 1500);
	scriptGlobal.Reinforce.RecordVehReinforceGroup(scriptGlobal.CommonMining2, 1500);
	scriptGlobal.Reinforce.RecordVehReinforceGroup(scriptGlobal.Construction, 1000);

	// Tube/wall placement
	CreateTubeOrWallLine(39 + 31, 181 - 1, 42 + 31, 181 - 1, mapTube);
	CreateTubeOrWallLine(18 + 31, 182 - 1, 22 + 31, 182 - 1, mapTube);
	CreateTubeOrWallLine(28 + 31, 182 - 1, 33 + 31, 182 - 1, mapTube);
	CreateTubeOrWallLine(15 + 31, 184 - 1, 15 + 31, 190 - 1, mapTube);
	CreateTubeOrWallLine(44 + 31, 180 - 1, 44 + 31, 177 - 1, mapTube);
	
	
	// Define AI rebuilding/expansion
	scriptGlobal.Construction.RecordBuilding(LOCATION(15 + 31, 182 - 1), mapCommandCenter, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(9 + 31, 167 - 1), mapTokamak, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(15 + 31, 192 - 1), mapCommonOreSmelter, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(35 + 31, 182 - 1), mapVehicleFactory, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(44 + 31, 175 - 1), mapAgridome, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(44 + 31, 182 - 1), mapAgridome, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(48 + 31, 182 - 1), mapUniversity, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(48 + 31, 175 - 1), mapNursery, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(50 + 31, 168 - 1), mapGuardPost, mapRPG);
	scriptGlobal.Construction.RecordBuilding(LOCATION(79 + 31, 182 - 1), mapGuardPost, mapRPG);
	scriptGlobal.Construction.RecordBuilding(LOCATION(40 + 31, 200 - 1), mapGuardPost, mapRPG);
	scriptGlobal.Construction.RecordBuilding(LOCATION(28 + 31, 200 - 1), mapGuardPost, mapRPG);

	//AI Tubes Start
	for (int y = 184; y <= 190; ++y)
	{
		scriptGlobal.Construction.RecordTube(LOCATION(36 + 31, y - 1));
	}

	for (int y = 177; y <= 180; ++y)
	{
		scriptGlobal.Construction.RecordTube(LOCATION(44 + 31, y - 1));
	}

	for (int y = 184; y <= 190; ++y)
	{
		scriptGlobal.Construction.RecordTube(LOCATION(15 + 31, y - 1));
	}

	for (int x = 28; x <= 33; ++x)
	{
		scriptGlobal.Construction.RecordTube(LOCATION(x + 31, 182 - 1));
	}

	for (int x = 18; x <= 22; ++x)
	{
		scriptGlobal.Construction.RecordTube(LOCATION(x + 31, 182 - 1));
	}

	for (int x = 39; x <= 42; ++x)
	{
		scriptGlobal.Construction.RecordTube(LOCATION(x + 31, 181 - 1));
	}

	for (int y = 185; y <= 190; ++y)
	{
		scriptGlobal.Construction.RecordTube(LOCATION(25 + 31, y - 1));
	}

	// AI Tubes Finish
	scriptGlobal.Construction.RecordBuilding(LOCATION(35 + 31, 192 - 1), mapCommonOreSmelter, mapNone);
	scriptGlobal.Reinforce.RecordBuilding(LOCATION(15 + 31, 198 - 1), mapCommonOreMine, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(25 + 31, 192 - 1), mapRareOreSmelter, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(51 + 31, 182 - 1), mapResidence, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(51 + 31, 175 - 1), mapResidence, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(41 + 31, 175 - 1), mapMedicalCenter, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(5 + 31, 167 - 1), mapTokamak, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(5 + 31, 171 - 1), mapMHDGenerator, mapNone);
	scriptGlobal.Construction.RecordBuilding(LOCATION(9 + 31, 171 - 1), mapMHDGenerator, mapNone);
	//scriptGlobal.Construction.RecordBuilding(LOCATION(25 + 31, 168 - 1), mapSpaceport, mapNone);		// Buildings are built in the order they're defined and the AI will not skip a building it can't afford to build.  Ordering a Spaceport before the AI has any rare ore capacity to build it will cause the AI to lock up.
	//End Southern Base Placement
	

	// Here's an example of how you can get the AI to expand using triggers.  It will cause the AI to start building its second mining group after 13 marks.
	scriptGlobal.AiExpansionTrigger = CreateTimeTrigger(1, 1, 1300, "PrepareSecondMiningGroup");
	
}

Export int InitProc()
{
	TethysGame::FreeMoraleLevel(-1);	// Set morale to unsteady.  Use -1 to apply this to all players.  AI players have morale locked at 50 no matter what anyways.
	SetupHumanPlayer();					// Player 0 Yellow Plymouth Human.
	SetupBlueEdenPlayer();				// Player 1 Blue Eden AI
	SetupRedPlymouthPlayer();			// Player 2 Red Plymouth AI

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

Export void PrepareSecondMiningGroup()
{
	scriptGlobal.Construction.RecordBuilding(LOCATION(36 + 31, 192 - 1), mapCommonOreSmelter, mapNone);
	scriptGlobal.Reinforce.RecordBuilding(LOCATION(36 + 31, 198 - 1), mapCommonOreMine, mapNone);

	// Unfortunately this is all we can do for now - we can't actually initialize the new mining group until the smelter and the mine exist.
	// So we'll need a second trigger to check for these.
	// But first, we need to cleanup this trigger now that we're done with it.
	// This way we can reuse the handle after we're done with it, and we won't have a stale trigger hanging around wasting memory.
	// Keep in mind Outpost 2 can only handle about 200 active triggers or AI unit groups total at any one time before it will crash.
	scriptGlobal.AiExpansionTrigger.Destroy();
	scriptGlobal.AiExpansionTrigger = CreateTimeTrigger(1, 0, 12, "CheckForSecondMiningGroup");
}

Export void CheckForSecondMiningGroup()
{
	bool smelterFound = false,
		mineFound = false;
	Unit next, Smelter, Mine;

	// Loop through every Common Ore Smelter, looking to see if it's at the location we wanted to build the new one at.
	PlayerBuildingEnum findSmelter(2, mapCommonOreSmelter);
	while (findSmelter.GetNext(next))
	{
		if (next.Location().x == 36 + 31 && next.Location().y == 192 - 1)
		{
			smelterFound = true;
			Smelter = next;
			break;
		}
	}

	// Loop through every Common Ore Mine, looking to see if it's at the location we wanted to build the new one at.
	PlayerBuildingEnum findMine(2, mapCommonOreMine);
	while (findMine.GetNext(next))
	{
		if (next.Location().x == 36 + 31 && next.Location().y == 198 - 1)
		{
			mineFound = true;
			Mine = next;
			break;
		}
	}

	// If we found both the new smelter and the new mine we want, we can proceed with setting up the mining group.
	if (smelterFound && mineFound)
	{
		// To do: Figure out where you want the smelter and define the mining box.  I just picked some arbitrary values as an example
		MAP_RECT CommonBox2(35 + 31, 193 - 1, 37 + 31, 198 - 1);
		scriptGlobal.CommonMining2.Setup(Mine, Smelter, CommonBox2);
		scriptGlobal.CommonMining2.SetTargCount(mapCargoTruck, mapNone, 2);
		scriptGlobal.Reinforce.RecordVehReinforceGroup(scriptGlobal.CommonMining2, 10);

		scriptGlobal.AiExpansionTrigger.Destroy();
	}
}

