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
	Twitter() {
		time = 0;
	}

	void postTweet(int userId, int tweetId) {
		follow(userId, userId);
		tweets[userId].insert({ time++, tweetId });
	}

	vector<int> getNewsFeed(int userId) {
		vector<int> res;
		map<int, int> top10;
		for (auto id : friends[userId]) {
			for (auto a : tweets[id]) {
				top10.insert({ a.first, a.second });
				if (top10.size() > 10) top10.erase(top10.begin());
			}
		}
		for (auto a : top10) {
			res.insert(res.begin(), a.second);
		}
		return res;
	}

	void follow(int followerId, int followeeId) {
		friends[followerId].insert(followeeId);
	}

	void unfollow(int followerId, int followeeId) {
		if (followerId != followeeId) {
			friends[followerId].erase(followeeId);
		}
	}

private:
	int time;
	unordered_map<int, unordered_set<int>> friends;
	unordered_map<int, map<int, int>> tweets;
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