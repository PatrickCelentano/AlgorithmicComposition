#ifndef __COMPOSER_HPP__
#define __COMPOSER_HPP__

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <fstream>

#include "Base.hpp"
#include "Form.hpp"
#include "Harmony.hpp"
#include "Defines.hpp"

////////////////////////////////////////////////
//                COMPOSER                    //
////////////////////////////////////////////////
// A class used for compositional purposes.   //
// All functions are static, and are meant to //
// be called either from main, or by each oth-//
// er in a full composition.                  //
////////////////////////////////////////////////
class Composer
{
	public:
		static void writeToLilyPond(Line line1,Line line2)
		{
			// The file we're writing to.
			std::ofstream file;
			file.open("test.ly");
			
			file << "\\version \"2.16.0\" \n\n";
			file << "\\header{\n";
			file << "	title = \"Title here\"\n";
			file <<	"	subtitle = \"Subtitle here\"\n";
			file << "} \n\n";
			
			file << "\\score{\n";
			file << "	<<\n";
			file << "		\\new PianoStaff = \"piano\" <<\n";
			file << "			\\new Staff = \"upper\"\n";
			file << "			\\absolute{\n";
			file << "				\\clef treble\n";
			file << "				" << line1.toLilyPond() << "\n";
			file << "			}\n";
			file << "			\\new Staff = \"lower\"\n";
			file << "			\\absolute{\n";
			file << "				\\clef bass\n";
			file << "				" << line2.toLilyPond() << "\n";
			file << "			}\n";
			file << "		>>\n";
			file << "	>>\n";
			file << "	\\midi{ }\n";
			file << "	\\layout{ }\n";
			file << "}\n";
			
			file.close();
		}
		static void writeSimpleMelody(int seed)
		{
			Line melody;
			melody.add(Note(Pitch(),Count()));
			writeToLilyPond(melody,Line());
		}
};
#endif