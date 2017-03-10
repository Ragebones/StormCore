-- Bloodhunter's Quarry
-- http://www.wowhead.com/item=140227/bloodhunters-quarry

DELETE FROM `item_loot_template` WHERE `Entry`=140227;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`)VALUES
(140227, 124124, 0, 100, 0, 1, 0, 1, 5, 'Blood of Sargeras');

-- Ravencrest Cache
-- http://www.wowhead.com/item=136383/ravencrest-cache

DELETE FROM `item_loot_template` WHERE `Entry`=136383;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`)VALUES
(136383, 136382, 0, 100, 0, 1, 0, 1, 2, 'Ravencrest Estate Papers'),
(136383, 131745, 0, 100, 0, 1, 0, 1, 1, 'Key of Kalyndras');

-- Ancient War Remnants
-- http://www.wowhead.com/item=136362/ancient-war-remnants

DELETE FROM `item_loot_template` WHERE `Entry`=136362;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`)VALUES
(136362, 131724, 0, 79, 0, 1, 0, 1, 2, 'Crystalline Eye of Undravius'),
(136362, 136360, 0, 21, 0, 1, 0, 1, 1, 'Crystalline Demonic Eye');