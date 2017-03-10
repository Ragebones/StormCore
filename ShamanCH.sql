delete from gameobject where map= '1469';

insert into `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) values(@OGUID+0,'252823','1469','0','0','1','0','0','951.23','1072.66','19.3213','4.27352','0','0','0.844072','-0.53623','300','0','1','0'),
(@OGUID+1,'245211','1469','0','0','1','0','0','1046.11','1016.07','20.2891','1.39776','0','0','0.643362','0.765563','300','0','1','0');
