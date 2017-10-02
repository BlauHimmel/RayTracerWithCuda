#pragma once

#include "ContainerDependency.h"
#include "ContainerMacro.h"

namespace EasyContainer
{

	template<typename TKey, typename TValue>
	class HashMap
	{

	public:

		using Pair = std::pair<TKey, TValue>;
		using MapInitializer = std::initializer_list<Pair>;
		using MapDelegate = std::function<void(TKey, TValue)>;
		using MapFilter = std::function<bool(TKey, TValue)>;

	private:

		std::unordered_map<TKey, TValue> m_Map;

	public:

		HashMap();
		HashMap(MapInitializer Initializer);
		HashMap(HashMap<TKey, TValue>& Other);
		HashMap(HashMap<TKey, TValue>&& Other);

	public:

		virtual TValue& operator [] (TKey Key);
		virtual bool Add(TKey Key, TValue Value);
		virtual bool TryGetValue(TKey Key, TValue*& OutValuePtr);
		virtual bool ContainsKey(TKey Key) const;
		virtual bool Remove(TKey Key);
		virtual int32 Size() const;
		virtual void Clear();

	public:

		virtual void ForEach(MapDelegate Delegate) const;
		virtual void ForEach(MapDelegate Delegate, MapFilter Filter) const;

	public:

		decltype(auto) begin();
		decltype(auto) end();

	};

	template<typename TKey, typename TValue>
	inline HashMap<TKey, TValue>::HashMap() : m_Map()
	{
	
	}

	template<typename TKey, typename TValue>
	inline HashMap<TKey, TValue>::HashMap(MapInitializer Initializer) : m_Map(Initializer)
	{
	
	}

	template<typename TKey, typename TValue>
	inline HashMap<TKey, TValue>::HashMap(HashMap<TKey, TValue>& Other)
	{
		m_Map = std::unordered_map<TKey, TValue>();
		for (auto Iter = m_Map.begin(); Iter != m_Map.end(); Iter++)
		{
			m_Map.insert(Pair(Iter.first, Iter.second));
		}
	}

	template<typename TKey, typename TValue>
	inline HashMap<TKey, TValue>::HashMap(HashMap<TKey, TValue>&& Other)
	{
		m_Map = Other.m_Map;
	}

	template<typename TKey, typename TValue>
	inline TValue& HashMap<TKey, TValue>::operator [] (TKey Key)
	{
		return m_Map[Key];
	}

	template<typename TKey, typename TValue>
	inline bool HashMap<TKey, TValue>::Add(TKey Key, TValue Value)
	{
		return m_Map.insert(Pair(Key, Value)).second;
	}

	template<typename TKey, typename TValue>
	inline bool HashMap<TKey, TValue>::TryGetValue(TKey Key, TValue*& OutValuePtr)
	{
		auto iter = m_Map.find(Key);
		if (iter != m_Map.end())
		{
			OutValuePtr = &iter->second;
			return true;
		}
		else
		{
			OutValuePtr = nullptr;
			return false;
		}
	}

	template<typename TKey, typename TValue>
	inline bool HashMap<TKey, TValue>::ContainsKey(TKey Key) const
	{
		return m_Map.count(Key) > 0;
	}

	template<typename TKey, typename TValue>
	inline bool HashMap<TKey, TValue>::Remove(TKey Key)
	{
		return m_Map.erase(Key) == 1;
	}

	template<typename TKey, typename TValue>
	inline int32 HashMap<TKey, TValue>::Size() const
	{
		return m_Map.size();
	}

	template<typename TKey, typename TValue>
	inline void HashMap<TKey, TValue>::Clear()
	{
		m_Map.clear();
	}

	template<typename TKey, typename TValue>
	inline void HashMap<TKey, TValue>::ForEach(MapDelegate Delegate) const
	{
		for (auto Pair : m_Map)
		{
			Delegate(Pair.first, Pair.second);
		}
	}

	template<typename TKey, typename TValue>
	inline void HashMap<TKey, TValue>::ForEach(MapDelegate Delegate, MapFilter Filter) const
	{
		for (auto Pair : m_Map)
		{
			if (Filter(Pair.first, Pair.second))
			{
				Delegate(Pair.first, Pair.second);
			}
		}
	}

	template<typename TKey, typename TValue>
	inline decltype(auto) HashMap<TKey, TValue>::begin()
	{
		m_Map.begin();
	}

	template<typename TKey, typename TValue>
	inline decltype(auto) HashMap<TKey, TValue>::end()
	{
		m_Map.end();
	}
}

