SET @CGUID := 1369249;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 65183, 1481, 7705, 0, 1, 5837, 0, 0, 0, 1180.778, 3309.238, 75.19302, 4.760153, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420); -- 65183 (Area: 0 - Difficulty: Normal) (Auras: 9036 - Fantasma, 9617 - Fantasma visual, 22011 - Canalizar Sanar espíritu)

DELETE FROM graveyard_zone WHERE ghost_zone = 7705;
INSERT INTO graveyard_zone (id, ghost_zone, faction) VALUES
(5103, 7705, 0);