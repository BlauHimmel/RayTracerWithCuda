#pragma once

#ifndef __STACK__
#define __STACK__

#include "Container\Dependency\ContainerDependency.h"
#include "Container\Dependency\ContainerMacro.h"

namespace EasyContainer
{

	template<typename TElement>
	class Stack
	{

	private:

		std::stack<TElement> m_Stack;

	public:

		Stack();

	public:

		void Push(TElement Element);
		void Pop();
		TElement Top() const;
		int32 Size() const;
		bool Empty() const;

	};

	template<typename TElement>
	INLINE Stack<TElement>::Stack() : m_Stack()
	{
	
	}

	template<typename TElement>
	INLINE void Stack<TElement>::Push(TElement Element)
	{
		m_Stack.push(Element);
	}

	template<typename TElement>
	INLINE void Stack<TElement>::Pop()
	{
		m_Stack.pop();
	}

	template<typename TElement>
	INLINE TElement Stack<TElement>::Top() const
	{
		return m_Stack.top();
	}

	template<typename TElement>
	INLINE int32 Stack<TElement>::Size() const
	{
		return static_cast<int32>(m_Stack.size());
	}

	template<typename TElement>
	INLINE bool Stack<TElement>::Empty() const
	{
		return m_Stack.empty();
	}
}

#endif