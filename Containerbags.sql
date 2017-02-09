-- Saco de gemas encontrado
-- http://es.wowhead.com/item=140221

DELETE FROM `item_loot_template` WHERE `Entry`=140221;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`)VALUES
(140221, 130172, 0, 33, 0, 1, 0, 1, 2, 'Sangrarita'),
(140221, 129099, 0, 33, 0, 1, 0, 2, 5, 'Trozo de gema'),
(140221, 130177, 0, 25, 0, 1, 0, 1, 2, 'Ópalo de reina'),
(140221, 130176, 0, 25, 0, 1, 0, 1, 1, 'Piedra celestial'),
(140221, 130203, 0, 25, 0, 1, 0, 2, 4, 'Trozo de gema'),
(140221, 130204, 0, 25, 0, 1, 0, 3, 5, 'Trozo de gema'),
(140221, 130202, 0, 22, 0, 1, 0, 3, 4, 'Trozo de gema'),
(140221, 130174, 0, 20, 0, 1, 0, 1, 2, 'Azsunita'),
(140221, 130201, 0, 20, 0, 1, 0, 3, 5, 'Trozo de gema'),
(140221, 130181, 0, 16, 0, 1, 0, 1, 1, 'Pandemonita'),
(140221, 130200, 0, 10, 0, 1, 0, 2, 6, 'Trozo de gema'),
(140221, 130173, 0, 8, 0, 1, 0, 1, 2, 'Ámbar intenso'),
(140221, 130175, 0, 6, 0, 1, 0, 1, 1, 'Espinela caótica'),
(140221, 130179, 0, 1, 0, 1, 0, 1, 1, 'Ojo de profecía');

-- Bienes recolectados
-- http://es.wowhead.com/item=140222

DELETE FROM `item_loot_template` WHERE `Entry`=140222;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`)VALUES
(140222, 124105, 0, 23, 0, 1, 0, 2, 4, 'Rosa luz estelar'),
(140222, 124104, 0, 23, 0, 1, 0, 10, 20, 'Fjarnskaggl'),
(140222, 124103, 0, 23, 0, 1, 0, 10, 20, 'Flor de raposa'),
(140222, 124102, 0, 23, 0, 1, 0, 10, 20, 'Frondasueño'),
(140222, 124101, 0, 23, 0, 1, 0, 10, 20, 'Aethril'),
(140222, 124107, 0, 18, 0, 1, 0, 10, 20, 'Pez reina maldito'),
(140222, 124112, 0, 18, 0, 1, 0, 10, 20, 'Barracuda negra'),
(140222, 124111, 0, 18, 0, 1, 0, 10, 20, 'Koi de escamas rúnicas'),
(140222, 124108, 0, 18, 0, 1, 0, 10, 20, 'Perca branquimusgo'),
(140222, 124110, 0, 18, 0, 1, 0, 10, 20, 'Rayatormenta'),
(140222, 124109, 0, 18, 0, 1, 0, 10, 20, 'Salmón de Monte Alto'),
(140222, 124106, 0, 18, 0, 1, 0, 1, 1, 'Matojo vil');

-- Carne troceada
-- http://es.wowhead.com/item=140224

DELETE FROM `item_loot_template` WHERE `Entry`=140224;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`)VALUES
(140224, 124115, 0, 38, 0, 1, 0, 10, 20, 'Escama tormentosa'),
(140224, 124113, 0, 35, 0, 1, 0, 10, 20, 'Cuero de Petrapiel'),
(140224, 124117, 0, 23, 0, 1, 0, 10, 20, 'Corvo magro'),
(140224, 124118, 0, 23, 0, 1, 0, 10, 20, 'Filete de oso graso'),
(140224, 124120, 0, 23, 0, 1, 0, 10, 20, 'Sangre Ley'),
(140224, 124119, 0, 22, 0, 1, 0, 10, 20, 'Costillas grandes de sabor fuerte'),
(140224, 124121, 0, 21, 0, 1, 0, 10, 20, 'Huevo de ave silvestre'),
(140224, 124439, 0, 17, 0, 1, 0, 10, 20, 'Diente sin romper'),
(140224, 124438, 0, 17, 0, 1, 0, 10, 20, 'Garra sin romper'),
(140224, 124116, 0, 17, 0, 1, 0, 1, 1, 'Pellejo vil');

-- Bolsa teñida con maná
-- http://es.wowhead.com/item=140226

DELETE FROM `item_loot_template` WHERE `Entry`=140226;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`)VALUES
(140226, 124441, 0, 31, 0, 1, 0, 1, 3, 'Fragmento de luz Ley'),
(140226, 124440, 0, 31, 0, 1, 0, 5, 10, 'Arkhana'),
(140226, 127839, 0, 8, 0, 1, 0, 1, 1, 'Elixir de avalancha'),
(140226, 127835, 0, 8, 0, 1, 0, 1, 1, 'Poción de maná antigua'),
(140226, 127841, 0, 8, 0, 1, 0, 1, 1, 'Poción de soplo aéreo'),
(140226, 127840, 0, 7, 0, 1, 0, 1, 1, 'Brebajeskaggl'),
(140226, 127838, 0, 7, 0, 1, 0, 1, 1, 'Elixir nemoroso'),
(140226, 127837, 0, 7, 0, 1, 0, 1, 1, 'Jarabe de magia pura'),
(140226, 127836, 0, 7, 0, 1, 0, 1, 1, 'Poción de rejuvenecimiento antigua'),
(140226, 127834, 0, 6, 0, 1, 0, 1, 1, 'Poción de sanación antigua'),
(140226, 143734, 0, 4, 0, 1, 0, 1, 1, 'Montón de cristales de maná antiguo'),
(140226, 127843, 0, 4, 0, 1, 0, 1, 1, 'Poción de gracia letal'),
(140226, 127846, 0, 4, 0, 1, 0, 1, 1, 'Poción de torrente Ley'),
(140226, 127845, 0, 4, 0, 1, 0, 1, 1, 'Poción inalterable'),
(140226, 124442, 0, 3, 0, 1, 0, 1, 2, 'Cristal del caos'),
(140226, 127844, 0, 3, 0, 1, 0, 1, 1, 'Poción de la vieja guerra'),
(140226, 127849, 0, 3, 0, 1, 0, 1, 1, 'Frasco del sinfín de ejércitos'),
(140226, 143733, 0, 3, 0, 1, 0, 1, 1, 'Fragmentos de maná antiguo'),
(140226, 127850, 0, 3, 0, 1, 0, 1, 1, 'Frasco de las diez mil cicatrices'),
(140226, 127847, 0, 3, 0, 1, 0, 1, 1, 'Frasco del pacto murmurado'),
(140226, 127848, 0, 3, 0, 1, 0, 1, 1, 'Frasco del séptimo demonio');

-- Presa del cazasangre
-- http://es.wowhead.com/item=140227 

DELETE FROM `item_loot_template` WHERE `Entry`=140227;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`)VALUES
(140227, 124124, 0, 100, 0, 1, 0, 1, 5, 'Sangre de Sargeras');

-- Tela arramblada
-- http://es.wowhead.com/item=140220

 DELETE FROM `item_loot_template` WHERE `Entry`=140220;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`)VALUES
(140220, 124437, 0, 100, 0, 1, 0, 18, 20, 'Seda Shaldorei');