class Twitter {
    struct Tweet
    {
        int id;
        unsigned int timestamp;
        Tweet(int id, unsigned int timestamp) 
        : id(id), timestamp(timestamp) 
        {}
    };
public:
    Twitter() : time_(0U) {}
    
    void postTweet(int userId, int tweetId) {
        time_++;
        tweets_[userId].emplace_back(tweetId, time_);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> tweets;

        vector<int> users(1, userId);
        map<int, int> indices;
        indices[userId] = tweets_[userId].size();
        for (auto &follow : following_[userId])
        {
            users.push_back(follow.first);
            indices[follow.first] = tweets_[follow.first].size();
        }

        int foundUser{-1};
        do
        {
            unsigned int lastPostTime{0U};
            foundUser = -1;
            for (auto &user : users)
            {
                if (indices[user] > 0)
                {
                    if (tweets_[user][indices[user]-1].timestamp > lastPostTime)
                    {
                        lastPostTime = tweets_[user][indices[user]-1].timestamp;
                        foundUser = user;
                    }
                }
            }
            if (foundUser != -1)
            {
                tweets.push_back(tweets_[foundUser][indices[foundUser]-1].id);
                indices[foundUser] -= 1;
            }

        } while (tweets.size() < 10 && (foundUser != -1));


        return tweets;
    }
    
    void follow(int followerId, int followeeId) {
        following_[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        following_[followerId].erase(followeeId);
    }

private:
    unsigned int time_;
    map<int, map<int, bool>> following_;
    map<int, vector<Tweet>> tweets_;
};
