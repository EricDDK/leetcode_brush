//https://zhuanlan.zhihu.com/p/54510444

#include "iostream"
#include <vector>
#include <memory>
#include <cstdint>
#include <functional>
#include <algorithm>

using namespace std;

struct Vec2
{
	int x;
	int y;

	Vec2() : x(0), y(0) {}

	Vec2(int x1, int y1) : x(x1), y(y1) {}

	int distance(const Vec2 &other) const
	{
		return abs(other.x - x) + abs(other.y - y);
	}

	bool operator== (const Vec2 &other) const
	{
		return x == other.x && y == other.y;
	}
};

struct Node
{
	Vec2 pos;
	Node* parent;
	int g;
	int h;

	int f()
	{
		return g + h;
	}

	Node(const Vec2 &pos) : g(0), h(0), pos(pos), parent(nullptr)
	{

	}

	bool operator== (const Node &other) const
	{
		return pos == other.pos;
	}

};

class AStar
{
public:
	AStar() {}
	~AStar() {}

	// 获取最高优先级
	Node* getHighPriority(int& index)
	{
		index = 0;
		for (int i = 1; i < openSet.size(); ++i)
		{
			if (openSet[i]->f() < openSet[index]->f())
				index = i;
		}
		return openSet[index];
	}

	Node* isOpenHas(Vec2& pos)
	{
		for (auto& c : openSet)
		{
			if (pos == c->pos)
				return c;
		}
		return nullptr;
	}

	bool isCloseHas(Vec2& pos)
	{
		for (auto& c : closeSet)
		{
			if (pos == c->pos)
				return true;
		}
		return false;
	}

	vector<Vec2> find(vector<vector<int>> maps, const Vec2& start, const Vec2& end)
	{
		int n = maps.size();
		Node* first = new Node(start);
		first->h = 0;
		first->g = 0;
		openSet.push_back(first);
		vector<Vec2> result;
		while (!openSet.empty())
		{
			int indexHp = 0;
			Node* hp = getHighPriority(indexHp);
			if (hp->pos == end)
			{
				while (hp->parent != nullptr)
				{
					result.insert(result.begin(), hp->pos);
					hp = hp->parent;
				}
				return result;
			}
			else
			{
				openSet.erase(openSet.begin() + indexHp);
				closeSet.push_back(hp);
				Vec2 nPos = hp->pos;

				// 8个方向
				/*dfs(maps, end, Vec2(hp->pos.x - 1, hp->pos.y + 1), hp);
				dfs(maps, end, Vec2(hp->pos.x - 1, hp->pos.y), hp);
				dfs(maps, end, Vec2(hp->pos.x - 1, hp->pos.y - 1), hp);
				dfs(maps, end, Vec2(hp->pos.x, hp->pos.y - 1), hp);
				dfs(maps, end, Vec2(hp->pos.x + 1, hp->pos.y - 1), hp);
				dfs(maps, end, Vec2(hp->pos.x + 1, hp->pos.y), hp);
				dfs(maps, end, Vec2(hp->pos.x + 1, hp->pos.y + 1), hp);
				dfs(maps, end, Vec2(hp->pos.x, hp->pos.y + 1), hp);*/

				// 十字
				dfs(maps, end, Vec2(hp->pos.x + 1, hp->pos.y), hp);
				dfs(maps, end, Vec2(hp->pos.x - 1, hp->pos.y), hp);
				dfs(maps, end, Vec2(hp->pos.x, hp->pos.y + 1), hp);
				dfs(maps, end, Vec2(hp->pos.x, hp->pos.y - 1), hp);
			}
		}
		return result;
	}

	void dfs(vector<vector<int>>& maps, const Vec2& end, Vec2& pos, Node* parent)
	{
		if (pos.x < 0 || pos.y < 0 || pos.x >= maps[0].size() || pos.y >= maps.size())
			return;
		if (maps[pos.x][pos.y] == 1)
			return;
		if (isCloseHas(pos))
			return;
		Node* isInOpenNode = isOpenHas(pos);
		if (isInOpenNode == nullptr)
		{
			Node* node = new Node(pos);
			node->pos = pos;
			node->g = pos.distance(Vec2(0, 0));
			node->h = node->pos.distance(end);
			node->parent = parent;
			openSet.push_back(node);
		}
		else
		{
			int g = pos.distance(Vec2(0, 0));
			if (g < parent->g)
			{
				isInOpenNode->parent = parent;
				isInOpenNode->g = g;
				isInOpenNode->h = isInOpenNode->pos.distance(end);
				//openSet.push_back(node);
			}
		}
	}

private:
	vector<Node*> openSet;
	vector<Node*> closeSet;
};

int main()
{
	vector<vector<int>> maps =
	{
		{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
		{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
		{ 1, 1, 0, 0, 1, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
	};

	AStar as;
	auto result = as.find(maps, Vec2(0, 0), Vec2(9, 9));
	
	return 0;
}