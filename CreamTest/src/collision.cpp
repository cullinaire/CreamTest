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

bool Collision::Add(const Box newBox)
{	
	std::vector<Box>::iterator itr;
	for(itr = boxes->begin();itr != boxes->end();++itr)
	{
		if(itr->id == newBox.id)
		{
			std::cout << "Duplicate of box id " << newBox.id << " found. Not inserting!!" << std::endl;
			return false;
		}
	}
	boxes->push_back(newBox);
	return true;
}

void Collision::Remove(const int id)
{
	std::vector<Box>::iterator itr;
	for(itr = boxes->begin();itr != boxes->end();++itr)
	{
		if(itr->id == id)
		{
			boxes->erase(itr);
			return;
		}
	}
	std::cout << "Could not find id " << id << " to delete!!" << std::endl;
}

void Collision::Update(const Box updateBox)
{
	std::vector<Box>::iterator itr;
	for(itr = boxes->begin();itr != boxes->end();++itr)
	{
		if(itr->id == updateBox.id)
		{
			itr->aabb = updateBox.aabb;
			return;
		}
	}
	std::cout << "Could not find id " << updateBox.id << " to update!!" << std::endl;
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