-- Auctioneer Drezmit
-- http://www.wowhead.com/npc=44866/auctioneer-drezmit
-- Does not show the auction

UPDATE `creature_template` SET `npcflag`=2097152 WHERE=44866;

-- Urtharo <Weapon Merchant>
-- http://es.wowhead.com/npc=3314/urtharo
-- Does not deploy the store.

UPDATE `creature_template` SET `npcflag`=256 WHERE `entry`=3314;
DELETE FROM `npc_vendor` WHERE `entry`=3314;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(3314, 10, 853, 1, 0, 1, 0, 0, 0), 
(3314, 9, 854, 1, 0, 1, 0, 0, 0),
(3314, 8, 2207, 1, 0, 1, 0, 0, 0),
(3314, 7, 851, 1, 0, 1, 0, 0, 0),
(3314, 6, 1197, 1, 0, 1, 0, 0, 0),
(3314, 5, 1198, 1, 0, 1, 0, 0, 0),
(3314, 4, 4203, 1, 0, 1, 0, 0, 0),
(3314, 3, 852, 1, 0, 1, 0, 0, 0),
(3314, 2, 1196, 1, 0, 1, 0, 0, 0),
(3314, 1, 2488, 1, 0, 1, 0, 0, 0); 

-- Disciple Jusi <Huojin Quartermaster>
-- http://www.wowhead.com/npc=69333/disciple-jusi
-- Does not display items

UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=69333;
DELETE FROM `npc_vendor` WHERE `entry`=69333;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(69333, 2, 92070, 1, 0, 1, 0, 0, 0), 
(69333, 1, 83080, 1, 0, 1, 0, 0, 0); 

-- Raider Bork <War Mount Quartermaster>
-- http://www.wowhead.com/npc=12796/raider-bork
-- When trying to buy the mounts says "The object was not found"

UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=12796;
DELETE FROM `npc_vendor` WHERE `entry`=2796;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(2796, 5, 29466, 1, 0, 1, 0, 0, 0), 
(2796, 4, 29469, 1, 0, 1, 0, 0, 0), 
(2796, 3, 29470, 1, 0, 1, 0, 0, 0), 
(2796, 2, 29472, 1, 0, 1, 0, 0, 0), 
(2796, 1, 34129, 1, 0, 1, 0, 0, 0); 

-- Bezzil <Stable Master>
-- http://www.wowhead.com/npc=45789/bezzil

UPDATE `creature_template` SET `npcflag`=1284194304 WHERE `entry`=45789;
DELETE FROM `npc_vendor` WHERE `entry`=45789;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(45789, 1, 37460, 1, 0, 1, 0, 0, 0); 

-- Tinza Silvermug <Innkeeper>
-- http://es.wowhead.com/npc=45563/tinza-jarrargenta
-- Does not display menu

UPDATE `creature_template` SET `gossip_menu_id`=20586 WHERE `entry`=45563;
UPDATE `creature_template` SET `npcflag`=66179 WHERE `entry`=45563;

DELETE FROM `npc_vendor` WHERE `entry`=45563;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(45563, 10, 81918, 20, 0, 1, 0, 0, 0), 
(45563, 9, 81923, 20, 0, 1, 0, 0, 0), 
(45563, 8, 82451, 20, 0, 1, 0, 0, 0), 
(45563, 7, 58257, 20, 0, 1, 0, 0, 0), 
(45563, 6, 58261, 20, 0, 1, 0, 0, 0), 
(45563, 5, 58269, 20, 0, 1, 0, 0, 0), 
(45563, 4, 81917, 20, 0, 1, 0, 0, 0), 
(45563, 3, 81924, 20, 0, 1, 0, 0, 0), 
(45563, 2, 82450, 20, 0, 1, 0, 0, 0), 
(45563, 1, 58256, 20, 0, 1, 0, 0, 0); 

-- Makavu (banker)
-- http://www.wowhead.com/npc=45081/
-- Does not display menuo

UPDATE `creature_template` SET `npcflag`=131072 WHERE `entry`=45081;

-- Auctioneer Ziji
-- http://www.wowhead.com/npc=45082/
-- Does not display menu

UPDATE `creature_template` SET `npcflag`=2097152 WHERE `entry`=45082;
 
-- Kaja <Bow & Rifle Vendor>
-- http://www.wowhead.com/npc=3322/
-- Does not sell anything

UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=3322;
DELETE FROM `npc_vendor` WHERE `entry`=3322;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(3322, 5, 11307, 1, 0, 1, 0, 0, 0), 
(3322, 4, 3025, 1, 0, 1, 0, 0, 0), 
(3322, 3, 11306, 1, 0, 1, 0, 0, 0), 
(3322, 2, 3024, 1, 0, 1, 0, 0, 0), 
(3322, 1, 3027, 1, 0, 1, 0, 0, 0); 


