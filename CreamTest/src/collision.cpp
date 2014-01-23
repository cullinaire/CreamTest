#include "collision.h"

bool operator==(const Box &lhs, const Box &rhs)
{
	if(lhs.id == rhs.id)
		return true;
	else
		return false;
}

bool collide(const AABB boxA, const AABB boxB)
{
	if(boxA.A[0] < boxB.A[0]) { return false; }
	if(boxA.A[0] > boxB.B[0]) { return false; }
	if(boxA.B[1] < boxB.A[1]) { return false; }
	if(boxA.A[1] > boxB.B[1]) { return false; }
	return true;
}

Collision::Collision(std::vector<Box> *boxVector)
{
	boxes = boxVector;
}

int Collision::Add(const Box newBox)
{
	boxes->push_back(newBox);
	
	std::vector<Box>::iterator itr;
	auto it = std::find(boxes->begin(), boxes->end(), newBox);

	if(it == boxes->end())
	{
		//Something's wrong - a box that was just inserted can't be found in the vector!!
		std::cout << "Houston there's something wrong with adding box to boxes!"<< std::endl;
	}
	else
	{
		int index = 0;
		for(itr = boxes->begin();itr != boxes->end();++itr)
		{
			if(itr == it)
				return index;
			else
				++index;
		}
	}

	return -80000;	//Should not ever get here
}

//This is a naive collision detect for testing only
//void Collision::naiveCollide()
//{
//	std::vector<Box>::iterator itr;
//	std::vector<Box>::iterator itrInner;
//	if(boxes.size() > 1)
//	{
//		for(itr = boxes.begin();itr != boxes.end();++itr)
//		{
//			for(itrInner = boxes.begin();itrInner != boxes.end();++itrInner)
//			{
//				if(itrInner != itr)
//				{
//					if(collide(itrInner->aabb, itr->aabb))
//					{
//						std::cout << "Collision detected" << std::endl;
//					}
//				}
//			}
//		}
//	}
//}