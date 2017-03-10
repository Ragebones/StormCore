 -- Reparación de Npcs vendedores de Darnassus

 -- Mydrannul
 -- http://es.wowhead.com/npc=4241/mydrannul

UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=4241;   
DELETE FROM `npc_vendor` WHERE `entry`=4241;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(4241, 13, 1645, 0, 0, 1, 0, 0, 23171), -- 1645 Zumo de baya lunar
(4241, 12, 4499, 0, 0, 1, 0, 0, 23171), -- 4499 Saco marrón enorme
(4241, 11, 4601, 0, 0, 1, 0, 0, 23171), -- 4601 Pan de plátano tierno
(4241, 10, 1708, 0, 0, 1, 0, 0, 23171), -- 1708 Néctar dulce
(4241, 9, 4497, 0, 0, 1, 0, 0, 23171), -- 4497 Bolsa marrón pesada
(4241, 8, 1205, 0, 0, 1, 0, 0, 23171), -- 1205 Zumo de melón
(4241, 7, 4498, 0, 0, 1, 0, 0, 23171), -- 4498 Cartera de cuero marrón
(4241, 6, 4542, 0, 0, 1, 0, 0, 23171), -- 4542 Pan de maíz húmedo
(4241, 5, 4470, 0, 0, 1, 0, 0, 23171), -- 4470 Madera simple
(4241, 4, 4496, 0, 0, 1, 0, 0, 23171), -- 4496 Faltriquera marrón pequeña
(4241, 3, 5042, 0, 0, 1, 0, 0, 23171), -- 5042 Papel para envolver con lazo rojo
(4241, 2, 159, 0, 0, 1, 0, 0, 23171), -- 159 Agua de manantial refrescante
(4241, 1, 4540, 0, 0, 1, 0, 0, 23171); -- 4540 Mendrugo de pan duro

 -- Layna Karner <Suministros de herrería>
 -- http://es.wowhead.com/npc=52641/layna-karner

 /*
UPDATE `creature_template` SET `npcflag`=4224 WHERE `entry`=52641;   
DELETE FROM `npc_vendor` WHERE `entry`=52641;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(52641, 41, 66100, 0, , 1, 0, 0, 23171),
(52641, 40, 66101, 0, , 1, 0, 0, 23171),
(52641, 39, 66122, 0, , 1, 0, 0, 23171),
(52641, 38, 66123, 0, , 1, 0, 0, 23171),
(52641, 37, 66124, 0, , 1, 0, 0, 23171),
(52641, 36, 66130, 0, , 1, 0, 0, 23171),
(52641, 35, 66131, 0, , 1, 0, 0, 23171),
(52641, 34, 66132, 0, , 1, 0, 0, 23171),
(52641, 33, 66110, 0, , 1, 0, 0, 23171),
(52641, 32, 66112, 0, , 1, 0, 0, 23171),
(52641, 31, 66114, 0, , 1, 0, 0, 23171),
(52641, 30, 66115, 0, , 1, 0, 0, 23171),
(52641, 29, 66116, 0, , 1, 0, 0, 23171),
(52641, 28, 66121, 0, , 1, 0, 0, 23171),
(52641, 27, 66129, 0, , 1, 0, 0, 23171),
(52641, 26, 67606, 0, , 1, 0, 0, 23171),
(52641, 25, 66104, 0, , 1, 0, 0, 23171),
(52641, 24, 66106, 0, , 1, 0, 0, 23171),
(52641, 23, 66108, 0, , 1, 0, 0, 23171),
(52641, 22, 66111, 0, , 1, 0, 0, 23171),
(52641, 21, 66113, 0, , 1, 0, 0, 23171),
(52641, 20, 66120, 0, , 1, 0, 0, 23171),
(52641, 19, 66128, 0, , 1, 0, 0, 23171),
(52641, 18, 67603, 0, , 1, 0, 0, 23171),
(52641, 17, 66105, 0, , 1, 0, 0, 23171),
(52641, 16, 66107, 0, , 1, 0, 0, 23171),
(52641, 15, 66109, 0, , 1, 0, 0, 23171),
(52641, 14, 66119, 0, , 1, 0, 0, 23171), No se cual es el ExtendedCost De este. 
(52641, 14, 66119, 0, , 1, 0, 0, 23171), 
(52641, 13, 66127, 0, , 1, 0, 0, 23171),
(52641, 12, 66103, 0, , 1, 0, 0, 23171),
(52641, 11, 66117, 0, , 1, 0, 0, 23171),
(52641, 10, 66118, 0, , 1, 0, 0, 23171),
(52641, 9, 66125, 0, , 1, 0, 0, 23171),
(52641, 8, 66126, 0, , 1, 0, 0, 23171),
(52641, 7, 18567, 0, , 1, 0, 0, 23171),
(52641, 6, 12162, 1, , 1, 0, 0, 23171),
(52641, 5, 3857, 0, , 1, 0, 0, 23171),
(52641, 4, 3466, 0, , 1, 0, 0, 23171),
(52641, 3, 2880, 0, , 1, 0, 0, 23171),
(52641, 2, 2901, 0, , 1, 0, 0, 23171),
(52641, 1, 5956, 0, , 1, 0, 0, 23171);
 */ 

 -- Reparación de Npcs vendedores de Ventormenta
 -- Hans Ascuatenue <El Cono de frío>
 -- http://es.wowhead.com/npc=52421/hans-ascuatenue

UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=52421;   
DELETE FROM `npc_vendor` WHERE `entry`=52421;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(52421, 4, 69243, 0, 0, 1, 0, 0, 23171), 
(52421, 3, 33234, 0, 0, 1, 0, 0, 23171), 
(52421, 2, 69244, 0, 0, 1, 0, 0, 23171), 
(52421, 1, 69027, 0, 0, 1, 0, 0, 23171);

 -- Bazzil Frostweaver
 -- http://www.wowhead.com/npc=52420/bazzil-frostweaver

UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=52420;   
DELETE FROM `npc_vendor` WHERE `entry`=52420;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(52420, 4, 69243, 0, 0, 1, 0, 0, 23171), 
(52420, 3, 33234, 0, 0, 1, 0, 0, 23171), 
(52420, 2, 69244, 0, 0, 1, 0, 0, 23171), 
(52420, 1, 69027, 0, 0, 1, 0, 0, 23171);

 -- Adherent Hanjun
 -- http://es.wowhead.com/npc=69334/partidario-hanjun

UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=69334;   
DELETE FROM `npc_vendor` WHERE `entry`=69334;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(69334, 2, 92071, 0, 0, 1, 0, 0, 23171), 
(69334, 1, 83079, 0, 0, 1, 0, 0, 23171);

-- Reparación de Npcs vendedores de Forjaz
-- Sraaz <Vendedor de tartas>
-- Sraaz <Vendedor de tartas>

UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=9099;   
DELETE FROM `npc_vendor` WHERE `entry`=9099;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(9099, 1, 8950, 0, 0, 1, 0, 0, 23171);