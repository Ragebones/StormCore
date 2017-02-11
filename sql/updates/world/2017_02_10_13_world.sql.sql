SET @OGUID := 1253486;
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+61;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `parent_rotation4`) VALUES
(@OGUID+13, 0, 0, 1, -4.371139E-08), -- The Maw of Souls
(@OGUID+15, 0, 0, 1, -4.371139E-08), -- Barnacled Cage
(@OGUID+16, 0, 0, 1, -4.371139E-08), -- Barnacled Cage
(@OGUID+18, 0, 0, 1, -4.371139E-08), -- Trap Door 007
(@OGUID+20, 2.592402E-43, 0, 1, -4.371139E-08), -- The Naglfar
(@OGUID+21, 0, 0, 1, -4.371139E-08), -- Barnacled Cage
(@OGUID+22, 0, 0, 1, -4.371139E-08), -- Trap Door 009
(@OGUID+23, 0, 0, 1, -4.371139E-08), -- Barnacled Cage
(@OGUID+24, 0, 0, 1, -4.371139E-08), -- Trap Door 006
(@OGUID+25, 0, 0, 1, -4.371139E-08), -- Barnacled Cage
(@OGUID+26, 0, 0, 1, -4.371139E-08), -- Trap Door 005
(@OGUID+27, 0, 0, 1, -4.371139E-08), -- Trao Door 008
(@OGUID+28, 0, 0, 1, -4.371139E-08), -- Trap Door 010
(@OGUID+29, 0, 0, 1, -4.371139E-08), -- Trap Door 002
(@OGUID+30, 0, 0, 1, -4.371139E-08), -- Trap Door 003
(@OGUID+31, 0, 0, 1, -4.371139E-08), -- Trap Door 001
(@OGUID+32, 0, 0, 1, -4.371139E-08), -- Trap Door 011
(@OGUID+34, 0, 0, 1, -4.371139E-08), -- Trap Door 004
(@OGUID+35, 0, 0, 1, -4.371139E-08), -- Heavy Barnacled Door
(@OGUID+36, 0, 0, 1, -4.371139E-08), -- Heavy Barnacled Door
(@OGUID+37, 0, 0, 1, -4.371139E-08), -- Heavy Barnacled Door
(@OGUID+40, 0, 0, 1, -4.371139E-08), -- Wall of Souls
(@OGUID+41, 0, 0, 1, -4.371139E-08), -- Wall of Souls
(@OGUID+42, 0, 0, 1, -4.371139E-08), -- Murky Fog
(@OGUID+43, 0, 0, 1, -4.371139E-08), -- Murky Fog
(@OGUID+55, 0, 0, 1, -4.371139E-08), -- 0
(@OGUID+59, 0, 0, 0.3826835, 0.9238796); -- -Unknown-