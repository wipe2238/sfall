/*
* sfall
* Copyright (C) 2008-2016 The sfall team
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <string>
#include <vector>

#include "Functions.h"
#include "Variables.h"

//
// Various utility functions, based on FO engine functions
//

namespace fo
{

__inline void DisplayPrint(const std::string& str) {
	fo::func::display_print(str.c_str());
}

// rect_free_ function for inline implementation
__forceinline void sf_rect_free(fo::RectList* rect) {
	fo::RectList* front = fo::var::rectList;
	fo::var::rectList = rect;
	rect->nextRect = front;
}

// returns weapon animation code
long AnimCodeByWeapon(GameObject* weapon);

// returns message string from given file or "Error" when not found
const char* GetMessageStr(const MessageList* fileAddr, long messageId);

// similar to GetMessageStr, but returns nullptr when no message is found
const char* MessageSearch(const MessageList* fileAddr, long messageId);

// returns pointer to prototype by PID, or nullptr on failure
Proto* GetProto(long pid);

bool CritterCopyProto(long pid, long* &proto_dst);

// wrapper for skill_get_tags with bounds checking
void SkillGetTags(long* result, long num);

// wrapper for skill_set_tags with bounds checking
void SkillSetTags(long* tags, long num);

long __fastcall GetItemType(GameObject* item);

__declspec(noinline) GameObject* GetItemPtrSlot(GameObject* critter, InvenType slot);

long& GetActiveItemMode();

GameObject* GetActiveItem();

long GetCurrentAttackMode();

bool HeroIsFemale();

long CheckAddictByPid(fo::GameObject* critter, long pid);

// Checks whether the player is under the influence of negative effects of radiation
long __fastcall IsRadInfluence();

void ToggleNpcFlag(fo::GameObject* npc, long flag, bool set);

// Returns the position of party member in the existing table (begins from 1)
long IsPartyMemberByPid(long pid);

// Returns True if the NPC belongs to the player's potential (set in party.txt) party members (analog of broken isPotentialPartyMember_)
bool IsPartyMember(fo::GameObject* critter);

// Returns the number of local variables of the object script
long GetScriptLocalVars(long sid);

long __fastcall GetTopWindowID(long xPos, long yPos);

// Returns an array of objects within the specified radius from the source tile
void GetObjectsTileRadius(std::vector<fo::GameObject*> &objs, long sourceTile, long radius, long elev, long type = -1);

// Checks the blocking tiles and returns the first blocking object
fo::GameObject* CheckAroundBlockingTiles(fo::GameObject* source, long dstTile);

fo::GameObject* __fastcall MultiHexMoveIsBlocking(fo::GameObject* source, long dstTile);

long wmGetCurrentTerrainType();

void SurfaceCopyToMem(long fromX, long fromY, long width, long height, long fromWidth, BYTE* fromSurface, BYTE* toMem);

void DrawToSurface(long toX, long toY, long width, long height, long toWidth, long toHeight, BYTE* toSurface, BYTE* fromMem);

void DrawToSurface(long width, long height, long fromX, long fromY, long fromWidth, BYTE* fromSurf, long toX, long toY, long toWidth, long toHeight, BYTE* toSurf, int maskRef);

void DrawToSurface(long width, long height, long fromX, long fromY, long fromWidth, BYTE* fromSurf, long toX, long toY, long toWidth, long toHeight, BYTE* toSurf);

// Fills the specified non-scripted interface window with index color 0 (black color)
void ClearWindow(long winID, bool refresh = true);

// Print text to surface
void PrintText(char* displayText, BYTE colorIndex, DWORD xPos, DWORD yPos, DWORD txtWidth, DWORD toWidth, BYTE* toSurface);
void PrintTextFM(char* displayText, BYTE colorIndex, DWORD xPos, DWORD yPos, DWORD txtWidth, DWORD toWidth, BYTE* toSurface);

// gets the height of the currently selected font
DWORD GetTextHeight();

// gets the length of a string using the currently selected font
DWORD GetTextWidth(const char* textMsg);
DWORD GetTextWidthFM(const char* textMsg);

// get width of Char for current font
DWORD GetCharWidth(char charVal);
DWORD GetCharWidthFM(char charVal);

// get maximum string length for current font - if all characters were maximum width
DWORD GetMaxTextWidth(const char* textMsg);

// get number of pixels between characters for current font
DWORD GetCharGapWidth();

// get maximum character width for current font
DWORD GetMaxCharWidth();

// Redraw the given object on screen (does not always redraws the whole object)
void RedrawObject(GameObject* obj);

// Redraws all interface windows
void RefreshGNW(size_t from = 0);

UnlistedFrm *LoadUnlistedFrm(char *frmName, unsigned int folderRef);

}
