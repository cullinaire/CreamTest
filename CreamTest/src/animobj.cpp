#include "animobj.h"

Animation::Animation(const std::string defFilename)
{
	std::ifstream			defFile(defFilename);
	std::string::iterator	itr;
	std::string				line;
	Frame					currentFrame;
	AnimSequence			currentSeq;
	int						readFrames = 0;

	currentSeq.frames.clear();
	seqs.clear();

	bool validLine = true;

	if(!defFile.is_open())
	{
		std::cout << "Failed to open " << defFilename << std::endl;
		return;
	}

	while(std::getline(defFile, line))
	{
		itr = line.begin();

		//skip blank lines
		if(line.size() == 0)
		{
			validLine = false;
		}
		else
		{
			skipWhiteSpace(line, itr);

			//Now see what that first non-whitespace char is
			if(*itr == '#')
				validLine = false;	//line begins with a comment character so go to next line
		}

		while(itr != line.end() && validLine)
		{
			//Begin reading animation
			if(*itr == '[')	//denotes beginning of sequence
			{
				readFrames = 0;
				++itr;
				currentSeq.frames.clear();
				currentSeq.animId = getNumber(line, itr);

				std::cout << "Reading sequence " << currentSeq.animId << "." << std::endl;
			}
			else if(*itr == '{')	//reading frames
			{
				++itr;
				currentFrame.cutout.x = getNumber(line, itr);
				++itr;
				currentFrame.cutout.y = getNumber(line, itr);
				++itr;
				currentFrame.cutout.w = getNumber(line, itr);
				++itr;
				currentFrame.cutout.h = getNumber(line, itr);
				++itr;
				currentFrame.duration = getNumber(line, itr);

				currentSeq.frames.push_back(currentFrame);

				++readFrames;

				std::cout << "Read frame " << readFrames << std::endl;
			}
			else if(*itr == '!')	//Termination of sequence
			{
				currentSeq.numFrames = readFrames;
				seqs.push_back(currentSeq);
				std::cout << "Commit sequence to seqs vector" << std::endl;
			}
			++itr;
		}
		validLine = true;
	}
	defFile.close();
}