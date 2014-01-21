#include "collision.h"

bool collide(const AABB boxA, const AABB boxB)
{
	if(boxA.A[0] < boxB.A[0]) { return false; }
	if(boxA.A[0] > boxB.B[0]) { return false; }
	if(boxA.B[1] < boxB.A[1]) { return false; }
	if(boxA.A[1] > boxB.B[1]) { return false; }
	return true;
}

Collision::Collision()
{
	boxes.clear();
}

void Collision::AddBox(const Box newBox)
{
	boxes.push_back(newBox);
}

//This is a naive collision detect for testing only
void Collision::naiveCollide()
{
	std::vector<Box>::iterator itr;
	std::vector<Box>::iterator itrInner;
	if(boxes.size() > 1)
	{
		for(itr = boxes.begin();itr != boxes.end();++itr)
		{
			for(itrInner = boxes.begin();itrInner != boxes.end();++itrInner)
			{
				if(itrInner != itr)
				{
					if(collide(itrInner->aabb, itr->aabb))
					{
						std::cout << "Collision detected" << std::endl;
					}
				}
			}
		}
	}
}