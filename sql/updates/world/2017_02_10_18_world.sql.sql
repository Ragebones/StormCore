UPDATE instance_template SET script = 'instance_maw_of_souls' WHERE map = 1492;
INSERT INTO game_tele (`position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES (7186.82, 7319.46, 23.5025, 6.18178, 1492, 'mawofsouls');

DELETE FROM `instance_encounters` WHERE entry IN (1822, 1823, 1824);
INSERT INTO `instance_encounters` (`entry`, `creditType`, `creditEntry`, `lastEncounterDungeon`, `comment`) VALUES
(1822, 0, 96756, 0, "Ymiron, The Fallen King"),
(1823, 0, 96754, 0, "Harbaron"),
(1824, 0, 96759, 1192, "Helya");

DELETE FROM graveyard_zone WHERE id IN (5101, 5102);
INSERT INTO graveyard_zone(`ID`, `GhostZone`, `Faction`, `Comment`) VALUES
(5102, 7812, 0, "Maw of Souls - Instance Entrance"),
(5101, 7811, 0, "Maw of Souls - The Naglfar - Lower Deck");

DELETE FROM `creature_template` WHERE (entry = 600000);
INSERT INTO creature_template VALUES ('600000', '0', '0', '0', '0', '0', '1126', '11686', '0', '0', 'Maw Players Resurrector Stalker', '', '', '', '0', '110', '110', '6', '0', '0', '35', '0', '1', '0.992063', '1', '0', '0', '0', '0', '1', '1', '1', '131330', '0', '0', '0', '0', '0', '0', '10', '1024', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '0', '3', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '0', '0', 'maw_players_resurrector', '23222');
