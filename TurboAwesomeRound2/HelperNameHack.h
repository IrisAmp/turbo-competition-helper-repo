/*
    turbo-competition-helper
    Copyright (C) 2014  Brandon Yue & Andrew Coulthard

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __TURBO_HELPER_NAME_HACK_H_DEFINED__
#define __TURBO_HELPER_NAME_HACK_H_DEFINED__

#include "Helper.h"

/*============================================================================
	SHORTCUT NAMESPACE
============================================================================*/
#ifdef __TURBO_HELPER_H_DEFINED__
namespace help
{
	namespace c // Containers
	{
		typedef std::string					s;
		typedef StringList_t				sl;
		typedef IntList_t					il;
		typedef std::pair<int, int>			ii;
		typedef std::tuple<int, int, int>	iii;
		typedef std::pair<std::string,
			std::string>					ss;
		typedef std::tuple<std::string,
			std::string, std::string>		sss;
	}
	namespace f // File
	{
		auto r  = parseFile;
		auto ri = parseIntFile;
		auto w  = appendToOutput;
		auto wl = appendStringListToOutput;
	}
	namespace s // String
	{
		auto rm = removeAllChar;
		auto rs = removeString;
		auto sp = splitString;
		auto tu = toUpper;
		auto fs = formatString;
	}
	namespace m // Math
	{
		auto na = normalizeAngle;
		auto li = lerp;
		auto ib = IsBetween;
		auto rd = rtodeg;
		auto dr = degtor;
		auto cs = convertScales;
	}
	namespace log // Debug log
	{
		void c(const char *msg, int level = 0){TurboDebugHelper::getInstance().writeToConsole(msg, level);}
		void l(const char *msg, int level = 0){TurboDebugHelper::getInstance().writeToLog(msg, level);}
		void b(const char *msg, int level = 0){TurboDebugHelper::getInstance().writeToBoth(msg, level);}
		void rm(){TurboDebugHelper::getInstance().clean();}
	}
}
#endif//__TURBO_HELPER_H_DEFINED__

#endif//__TURBO_HELPER_NAME_HACK_H_DEFINED__