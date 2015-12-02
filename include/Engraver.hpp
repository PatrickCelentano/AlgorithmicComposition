#ifndef __ENGRAVER_HPP__
#define __ENGRAVER_HPP__

#include <string>
#include <iostream>
#include <fstream>

#include "Defines.hpp"

////////////////////////////////////////////////
//                ENGRAVER                    //
////////////////////////////////////////////////
// A class used for engraving purposes.       //
////////////////////////////////////////////////
class Engraver
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
			//file << "			\\absolute{\n";
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
		static void writeToLilyPond(unsigned int upper, unsigned int lower, Line* line, Progression* progression)
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
			file << "				\\numericTimeSignature\n";
			file << "				\\time" << upper << "/" << lower << "\n";
			file << "				" << line->toLilyPond() << "\n";
			file << "			}\n";
			file << "			\\new Staff = \"lower\"\n";
			file << "			\\absolute{\n";
			file << "				\\clef bass\n";
			file << "				\\numericTimeSignature\n";
			file << "				\\time" << upper << "/" << lower << "\n";
			file << "				" << progression->toLilyPond() << "\n";
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