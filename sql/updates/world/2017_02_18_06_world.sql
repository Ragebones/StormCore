SET @CGUID := 4000147;
DELETE FROM creature WHERE guid BETWEEN @CGUID+0 AND @CGUID+2;

insert into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) values
(@CGUID+0,'28512','609','0','0','1','0','0','0','0','2402.98','-5593.03','420.73','0.418879','120','0','0','1','0','0','0','0','0','0'),
(@CGUID+1,'28486','0','0','0','1','0','0','0','0','2383.75','-5649.5','382.439','4.24115','360','0','0','252000','79880','0','0','0','0','0'),
(@CGUID+2,'27928','0','0','0','1','0','0','0','0','2379.41','-5648.53','382.522','3.735','360','0','0','11770','0','0','0','0','0','0');
