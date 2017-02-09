DELETE FROM creature_template_locale WHERE entry IN ('3216', '5875', '3325', '10181', '36273') AND locale IN ('esES', 'esMX');

INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `TitleAlt`, `VerifiedBuild`) VALUES
('3216','esES','Arnak Hojafuego','','',NULL,'18019'),
('3216','esMX','Arnak Hojafuego','','',NULL,'18019'),
('3325','esES','Mirkat','','Instructora de brujos',NULL,'18019'),
('3325','esMX','Mirkat','','Instructora de brujos',NULL,'18019'),
('5875','esES','Mordak Puño Oscuro','','',NULL,'18019'),
('5875','esMX','Mordak Puño Oscuro','','',NULL,'18019'),
('10181','esES','Lady Sylvanas Brisaveloz','','Jefa de Guerra',NULL,'18019'),
('10181','esMX','Lady Sylvanas Brisaveloz','','Jefa de Guerra',NULL,'18019'),
('36273','esES','Bragor Puñosangre','','Mano del Jefe de Guerra',NULL,'18019'),
('36273','esMX','Bragor Puñosangre','','Mano del Jefe de Guerra',NULL,'18019');