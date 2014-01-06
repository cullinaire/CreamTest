#include "animobj.h"
#include "parse.h"

Animation::Animation()
{
}

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
			validLine = false;

		skipWhiteSpace(line, itr);

		//Now see what that first non-whitespace char is
		if(*itr == '#')
			validLine = false;	//line begins with a comment character so go to next line

		while(itr != line.end() && validLine)
		{
			//Begin reading animation
			if(*itr == '[')	//denotes beginning of frame
			{
				++itr;
				currentSeq.animId = getNumber(line, itr);
				++itr;
				currentSeq.numFrames = getNumber(line, itr);

				std::cout << "Read sequence " << currentSeq.animId << " which has "
					<< currentSeq.numFrames << " frames." << std::endl;
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

				currentSeq.frames.push_back(currentFrame);

				++readFrames;
				if(readFrames == currentSeq.numFrames)	//Sequence fully read, commit
				{
					seqs.push_back(currentSeq);
					std::cout << "Commit sequence to seqs vector" << std::endl;
				}

				std::cout << "Read frame " << readFrames << std::endl;

				break;	//Nothing more to read on this line
			}
			++itr;
		}
		validLine = true;
	}
	defFile.close();
}

Animation::~Animation()
{
}