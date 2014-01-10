#include "animobj.h"

Animation::Animation(const std::string defFilename)
{
	std::ifstream			defFile(defFilename);
	std::string::iterator	itr;
	std::string				line;
	Frame					currentFrame;
	AnimSequence			currentSeq;
	int						readFrames = 0;

	currentPlayingId = 0;
	currentFrameId = 0;
	isPlaying = false;
	loopAnim = false;
	bNfAnim = false;
	reverse = false;
	elapsed = 0;

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

void Animation::Play(const int idToPlay, const bool looping, const bool backNforth)
{
	elapsed = 0;
	currentPlayingId = idToPlay;
	currentFrameId = 0;
	loopAnim = looping;
	bNfAnim = backNforth;
	isPlaying = true;
}

void Animation::Stop()
{
	isPlaying = false;
}

SDL_Rect Animation::Update(const double dt)
{
	if(isPlaying)
	{
		//If time elapsed exceeds current frame's duration, update to new current frame
		if(seqs[currentPlayingId].frames[currentFrameId].duration > elapsed)
		{
			elapsed = 0;
			if(reverse && currentFrameId > 0)
			{
				--currentFrameId;
			}
			else if(reverse && currentFrameId == 0)
			{
				reverse = false;
				++currentFrameId;
			}
			else
			{
				++currentFrameId;
			}

			//If end of sequence is reached
			if(currentFrameId == seqs[currentPlayingId].numFrames)
			{
				//Three possibilities here: stop, loop, or reverse (backNforth)
				if(loopAnim)
				{
					currentFrameId = 0;	//go back to the beginning
				}
				else if(bNfAnim)
				{
					reverse = true;
				}
				else
				{
					isPlaying = false;
				}
			}
		}
		else
		{
			elapsed += dt;
		}
	}
	return seqs[currentPlayingId].frames[currentFrameId].cutout;
}

Animobj::Animobj(const std::string defFile, Spritesheet *spritesheet)
{
	animSheet = spritesheet;
	anims = Animation(defFile);
}

void Animobj::Play(const int idToPlay, const bool looping, const bool backNforth)
{
	anims.Play(idToPlay, looping, backNforth);
}

void Animobj::Stop()
{
	anims.Stop();
}

void Animobj::Update(const double dt)
{
	src = anims.Update(dt);
}

void Animobj::Draw(const float x, const float y)
{
	dst = src;	//set dst's width and height to that of src

	dst.x = round(x);
	dst.y = round(y);

	animSheet->Draw(src, dst);
}