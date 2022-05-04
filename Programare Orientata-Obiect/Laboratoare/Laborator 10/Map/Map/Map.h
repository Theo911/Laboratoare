#pragma once

#include <iostream>
using namespace std;

template<typename K, typename V>
struct Pereche
{
	K key;
	V value;
	int index;
};

template<typename K, typename V>
class Map
{
public:

	Pereche<K, V> v[100];
	int count;



	Pereche<K, V>* begin() { return &v[0]; }
	Pereche<K, V>* end() { return &v[count]; }

	Map()
	{
		count = 0;
	}

	V& operator[](K key)
	{
		for (int i = 0; i < count; i++)
		{
			if (v[i].key == key)
			{
				return v[i].value;
			}
		}

		v[count].key = key;
		v[count].index = count;
		return v[count++].value;
	}

	void Print()
	{
		for (int i = 0; i < count; i++)
		{
			cout << v[i].key << ": " << v[i].value << '\n';
		}
		cout << "\n\n";
	}

	void Swap(Map<K, V>& m);

	void Add(Map<K, V>& m);

	void Set(const char* value, int key);
	bool Get(const K& key, V& value);
	int Count();
	void Clear();
	bool Delete(const K& key);
	bool Includes(const Map<K, V>& map);
};

template<typename K, typename V>
void Map<K, V>::Swap(Map<K, V>& m)
{
	Map<K, V> aux;
	for (int i = 0; i < m.count; i++)
	{
		aux.v[i].key = m.v[i].key;
		aux.v[i].value = m.v[i].value;
		aux.count++;
	}

	m.Clear();
	for (int i = 0; i < count; i++)
	{
		m.v[i].key = v[i].key;
		m.v[i].value = v[i].value;
		m.count++;
	}

	this->Clear();
	for (int i = 0; i < aux.count; i++)
	{
		v[i].key = aux.v[i].key;
		v[i].value = aux.v[i].value;
		count++;
	}

	aux.Clear();
}

template<typename K, typename V>
void Map<K, V>::Add(Map<K, V>& m)
{
	for (int i = 0; i < m.count; i++)
	{
		this->Set(m.v[i].value, m.v[i].key);
	}
}

template<typename K, typename V>
void Map<K, V>::Set(const char* value, int key)
{
	int gasit = 0;
	for (int i = 0; i < count; i++)
	{
		if (v[i].key == key)
		{
			gasit = 1;
			v[i].value = value;
		}
	}

	if (!gasit)
	{
		v[count].key = key;
		v[count].value = value;
		count++;
	}
}

template<typename K, typename V>
bool Map<K, V>::Get(const K& key, V& value)
{
	int gasit = 0;
	for (int i = 0; i < count; i++)
	{
		if (v[i].key == key)
		{
			gasit = 1;
			value = this->v[i].value;
			return true;
		}
	}

	if (!gasit)
	{
		return false;
	}
}

template<typename K, typename V>
inline int Map<K, V>::Count()
{
	return count;
}

template<typename K, typename V>
void Map<K, V>::Clear()
{
	cout << "Golire map!\n\n";
	count = 0;
}

template<typename K, typename V>
bool Map<K, V>::Delete(const K& key)
{
	int gasit = 0;
	for (int i = 0; i < count; i++)
	{
		if (v[i].key == key)
		{
			gasit = 1;
			for (int j = i + 1; j < count; j++)
			{
				v[j - 1] = v[j];
			}
			count--;
			return true;
		}
	}

	if (!gasit)
	{
		return false;
	}
}

template<typename K, typename V>
bool Map<K, V>::Includes(const Map<K, V>& map)
{
	if (count < map.count)
	{
		return false;
	}

	for (int i = 0; i < map.count; i++)
	{
		int gasit = 0;
		for (int j = 0; j < count; j++)
		{				

			if (v[i].key == map.v[j].key && v[i].value == map.v[j].value)
			{
				gasit = 1;
			}
		}

		if (!gasit)
		{
			return false;
		}
	}
	return true;
}
