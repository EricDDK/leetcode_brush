//Design a simplified version of Twitter where users can post tweets, follow / unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
//
//postTweet(userId, tweetId) : Compose a new tweet.
//getNewsFeed(userId) : Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
//follow(followerId, followeeId) : Follower follows a followee.
//unfollow(followerId, followeeId) : Follower unfollows a followee.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include "windows.h"
#include <algorithm>
#include <stack>
#include <string>
#include <queue>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Twitter {
public:
	/** Initialize your data structure here. */
	Twitter() {
		twitters.clear();
		followMap.clear();
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		twitters.push_back({ tweetId, userId });
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		auto followings = followMap[userId];
		vector<int> result;
		int size = twitters.size();
		int index = 0;
		for (int i = size - 1; index < 10 && i >= 0; --i)
		{
			if (userId == twitters[i].second || followings.count(twitters[i].second))
			{
				result.push_back(twitters[i].first);
				index++;
			}
		}
		return result;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		followMap[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followMap[followerId].count(followeeId))
		{
			followMap[followerId].erase(followeeId);
		}
	}

private:

	vector<pair<int, int>> twitters;  // {id, userID}

	unordered_map<int, unordered_set<int>> followMap;  // {userID, {userID, userID, ...}}

};

int main()
{
	Twitter *t = new Twitter;
	t->postTweet(1, 5);
	auto result = t->getNewsFeed(1);
	t->follow(1, 2);
	t->postTweet(2, 6);
	result = t->getNewsFeed(1);
	t->unfollow(1, 2);
	result = t->getNewsFeed(1);
	delete t;
	system("pause");
	return 0;
}