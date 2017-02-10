-- .go xyz 3094.907 1062.633 242.5797 4.911885 1107 HallWarlock              -- Sede de Clase del Brujo
-- .go xyz 1561.02 1399.94 237.108 1.69284 1519 HallDemon                    -- Sede de Clase del DH
-- .go xyz 1126.24 1069.48 3.55888 6.11568 1469 HallShaman                   -- Sede de Clase del Chaman
-- .go xyz 4113.746094 7459.808105 48.231529 0.907679 1220 HallDruid         -- Sede de Clase del Druida
-- .go xyz 4529.880859 5246.978027 862.193237 3.055734 1220 HallHunter       -- Sede de Clase del Cazador
-- .go xyz 2373.476074 -5356.951172 52.583263 2.450318 0 HallPaladin         -- Sede de Clase del Paladín
-- .go xyz -927.239197 4501.060547 7000.747375 3.989714 1220 HallRogue       -- Sede de Clase del Picaro
-- .go xyz -1502.453125 1060.684570 260.416138 4.147008 1220 HallDK          -- Sede Clase del DK
-- .go xyz 1028.47 7225.17 100.181 1.537337 1479 HallWarrior                 -- Sede de Clase del Guerrero
-- .go xyz 885.306274 3605.373779 192.230026 6.263655 1514 HallMonk          -- Sede de Clase del Monje
-- .go xyz -844 4759 918 0.586009 1513 HallMage                              -- Sede de Clase del Mago

-- Game Teles

DELETE FROM `game_tele` WHERE `id` IN ('1584','1585','1586','1587','1588','1589','1590','1591','1592','1593','1594');
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`)VALUES
(1584, 3094.907, 1062.633, 242.5797, 4.911885, 1107, 'HallWarlock'),
(1585, 1561.02, 1399.94, 237.108, 1.69284, 1519, 'HallDemon'),
(1586, 1126.24, 1069.48, 3.55888, 6.11568, 1469, 'HallShaman'),
(1587, 4113.746094, 7459.808105, 48.231529, 0.907679, 1220, 'HallDruid'),
(1588, 4529.880859, 5246.978027, 862.193237, 3.055734, 1220, 'HallHunter'),
(1589, 2373.476074, -5356.951172, 52.583263, 2.450318, 0, 'HallPaladin'),
(1590, -927.239197, 4501.060547, 7000.747375, 3.989714, 1220, 'HallRogue'),
(1591, -1502.453125, 1060.684570, 260.416138, 4.147008, 1220, 'HallDK'),
(1592, 1028.47, 7225.17, 100.181, 1.537337, 1479, 'HallWarrior '),
(1593, 885.306274, 3605.373779, 192.230026, 6.263655, 1514, 'HallMonk'),
(1594, -844, 4759, 918, 0.586009, 1513, 'HallMage');