/* 
* Ronos Cuerno Férreo [Trainer-Quest]
* Versión : 0.1alpha
*/
/* Correct Level, Health, Flags */
UPDATE `creature_template` SET `minlevel` = '110' , `maxlevel` = '110' , `npcflag` = '18' WHERE `entry` = '93691'; 
UPDATE `creature_template` SET `trainer_type` = '2' WHERE `entry` = '93691'; 
 
/* Trainer [Spell]*/
SET @ID := 93691 ;
SET @SKILL := 186;
DELETE FROM `npc_trainer` WHERE `ID` = '93691'; 
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES 
(@ID, 2575, 10, 0, 0, 5),
(@ID, 2576, 500, @SKILL, 50, 10),
(@ID, 3564, 5000, @SKILL, 125, 20),
(@ID, 10248, 50000, @SKILL, 200, 35),
(@ID, 29354, 100000, @SKILL, 275, 50),
(@ID, 50310, 350000, @SKILL, 350, 65),
(@ID, 74517, 500000, @SKILL, 425, 75),
(@ID, 102161, 600000, @SKILL, 500, 81),
(@ID, 3304, 50, @SKILL, 50, 0),
(@ID, 2659, 200, @SKILL, 50, 0),
(@ID, 2658, 200, @SKILL, 65, 0),
(@ID, 3307, 500, @SKILL, 100, 0),
(@ID, 3308, 600, @SKILL, 115, 0),
(@ID, 3569, 750, @SKILL, 125, 0),
(@ID, 10097, 5000, @SKILL, 150, 0),
(@ID, 10098, 10000, @SKILL, 165, 0),
(@ID, 16153, 20000, @SKILL, 230, 0),
(@ID, 70524, 10000, @SKILL, 250, 0),
(@ID, 29356, 40000, @SKILL, 275, 0),
(@ID, 35750, 10000, @SKILL, 300, 0),
(@ID, 35751, 10000, @SKILL, 300, 0),
(@ID, 29358, 40000, @SKILL, 325, 0),
(@ID, 29360, 40000, @SKILL, 350, 0),
(@ID, 29359, 40000, @SKILL, 350, 0),
(@ID, 49252, 100000, @SKILL, 350, 0),
(@ID, 29361, 100000, @SKILL, 375, 0),
(@ID, 29686, 100000, @SKILL, 375, 0),
(@ID, 49258, 150000, @SKILL, 400, 0),
(@ID, 84038, 50000, @SKILL, 425, 0),
(@ID, 55208, 200000, @SKILL, 450, 0),
(@ID, 55211, 200000, @SKILL, 450, 0),
(@ID, 74530, 50000, @SKILL, 475, 0),
(@ID, 74537, 50000, @SKILL, 500, 0),
(@ID, 102165, 60000, @SKILL, 500, 0),
(@ID, 74529, 50000, @SKILL, 525, 0),
(@ID, 102167, 60000, @SKILL, 600, 0);
/* Quest Start */
DELETE FROM `creature_queststarter` WHERE `id` = '93691'; 
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES 
(93691, 38786),
(93691, 38787);
/* 
* Quest Ended (Not Implemented)
*/
DELETE FROM `creature_questender` WHERE `id` = '93691'; 
INSERT INTO `creature_questender` (`id`, `quest`) VALUES 
(@ID, 38793),
(@ID, 38791),
(@ID, 38789),
(@ID, 38792),
(@ID, 38790),
(@ID, 38794),
(@ID, 38888),
(@ID, 38787),
(@ID, 38786);