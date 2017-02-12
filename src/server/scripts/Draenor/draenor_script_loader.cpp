/*
 * Copyright (C) 2014-2017 StormCore
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// This is where scripts' loading functions should be declared:
	
		//Instance Iron Docks #1 
void AddSC_instance_iron_docks(); 
void AddSC_iron_docks();
void AddSC_boss_fleshrender_nokgar();
void AddSC_boss_grimrail_enforcers();

	//Zone Tanaan Jungle
void AddSC_tanaan_jungle();


// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddDraenorScripts()
{
		// Iron Docks
    AddSC_instance_iron_docks();
    AddSC_iron_docks();
    AddSC_boss_fleshrender_nokgar();
    AddSC_boss_grimrail_enforcers();
	
	//Zone Tanaan Jungle
	AddSC_tanaan_jungle();
}
