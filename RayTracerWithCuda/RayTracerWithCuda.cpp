#include "stdafx.h"
#include "Matrix4f.h"
#include "Vector2f.h"
#include "Vector3f.h"
#include "Vector4f.h"
#include "Array.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Stack.h"
#include "HashMap.h"
#include "TreeMap.h"
#include "HashSet.h"
#include "TreeSet.h"
#include "MathFunction.h"

int main()
{

	EasyMath::Matrix4f m(1.0f, 1.1f, 1.2f, 1.3f, 1.41122341121111f, 1.5f, 1.6f, 1.7f, 1.8f, 1.9f, 2.0f, 2.1f, 2.2f, 2.3f, 2.4f, 2.5f);
	EasyMath::Vector2f v2;
	EasyMath::Vector3f v3;
	EasyMath::Vector4f v4(1.222f, 2.556f, 8.13f, 0.1111111564f);
	
	EasyContainer::Array<int> a(4);
	EasyContainer::ArrayList<int> al;
	EasyContainer::LinkedList<int> ll;
	EasyContainer::PriorityQueue<int, false> pqf;
	EasyContainer::PriorityQueue<int, true> pqt;
	EasyContainer::Queue<int> q;
	EasyContainer::Stack<int> s;
	EasyContainer::TreeMap<int, int> tm;
	EasyContainer::HashMap<int, int> hm;
	EasyContainer::TreeSet<int> ts;
	EasyContainer::HashSet<int> hs;

	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;
	std::cout << v4 << std::endl;
	std::cout << m << std::endl;

	return 0;
}

