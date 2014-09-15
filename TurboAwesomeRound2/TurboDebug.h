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
#ifndef __TURBO_DEBUG_H_DEFINED__
#define __TURBO_DEBUG_H_DEFINED__

#define DEBUG
#define DEBUGLEVEL 0

#include <fstream>
#include <time.h>

class TurboDebugHelper
{
    public:
        static TurboDebugHelper& getInstance()
        {
            static TurboDebugHelper instance;
            return instance;
        }

		void writeToLog(const char *msg, unsigned level = 0)
		{
			#ifdef DEBUG
			if (level >= DEBUGLEVEL)
			{
				time(&rawtime);
				ctime_s(tbuff, 27, &rawtime);
				tbuff[24] = '\0';
				this -> logFile << "[" << tbuff << "]: " << msg << "\n";
			}
			#endif
		}
		void writeToConsole(const char *msg, unsigned level = 0)
		{
			#ifdef DEBUG
			if (level >= DEBUGLEVEL)
			{
				time(&rawtime);
				ctime_s(tbuff, 27, &rawtime);
				tbuff[24] = '\0';
				printf("[%s]: %s\n", tbuff, msg);
			}
			#endif
		}
		void writeToBoth(const char *msg, unsigned level = 0)
		{
			#ifdef DEBUG
			this -> writeToConsole(msg, level);
			this -> writeToLog(msg, level);
			#endif
		}
		void clean()
		{
			logFile.close();
			logFile.open("Log.txt", std::ios::out | std::ios::trunc);
		}

    private:
        TurboDebugHelper()
		{
			logFile.open("Log.txt", std::ios::out | std::ios::app);
			if (!logFile.is_open()) throw new std::exception("Couldn't open the logfile!");
			writeToBoth("TurboDebugHelper instantiated.", 0);
		}
		~TurboDebugHelper()
		{
			logFile.close();
		}
        TurboDebugHelper(TurboDebugHelper const&); // Don't Implement
        void operator=(TurboDebugHelper const&);   // Don't implement

		std::ofstream logFile;
		time_t rawtime;
		char tbuff[27];
};

#endif//__TURBO_DEBUG_H_DEFINED__