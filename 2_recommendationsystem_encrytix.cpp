#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

// Structure to represent a user
struct User {
    int id;
    map<int, double> ratings; // movieId -> rating
};

// Structure to represent a movie
struct Movie {
    int id;
    string title;
};

// Function to calculate cosine similarity between two users
double cosineSimilarity(const User& user1, const User& user2) {
    double dotProduct = 0.0;
    double magnitude1 = 0.0;
    double magnitude2 = 0.0;

    for (auto& rating1 : user1.ratings) {
        for (auto& rating2 : user2.ratings) {
            if (rating1.first == rating2.first) {
                dotProduct += rating1.second * rating2.second;
                magnitude1 += rating1.second * rating1.second;
                magnitude2 += rating2.second * rating2.second;
            }
        }
    }

    magnitude1 = sqrt(magnitude1);
    magnitude2 = sqrt(magnitude2);

    if (magnitude1 == 0.0 || magnitude2 == 0.0) {
        return 0.0;
    }

    return dotProduct / (magnitude1 * magnitude2);
}

// Function to get recommendations for a user
vector<Movie> getRecommendations(const User& user, const vector<User>& users, const vector<Movie>& movies) {
    vector<pair<double, int>> similarities; // similarity -> userId

    for (const auto& otherUser : users) {
        if (otherUser.id != user.id) {
            double similarity = cosineSimilarity(user, otherUser);
            similarities.push_back({similarity, otherUser.id});
        }
    }

    (similarities.begin(), similarities.end(), greater<pair<double, int>>());

    vector<Movie> recommendations;

    for (const auto& similarity : similarities) {
        const User& otherUser = users[similarity.second];
        for (const auto& rating : otherUser.ratings) {
            bool alreadyRated = false;
            for (const auto& userRating : user.ratings) {
                if (userRating.first == rating.first) {
                    alreadyRated = true;
                    break;
                }
            }
            if (!alreadyRated) {
                Movie movie;
                movie.id = rating.first;
                movie.title = "Movie " + to_string(rating.first);
                recommendations.push_back(movie);
            }
        }
    }

    return recommendations;
}

int main() {
    vector<User> users = {
        {1, {{1, 5.0}, {2, 3.0}, {3, 4.0}}},
        {2, {{1, 4.0}, {2, 5.0}, {4, 3.0}}},
        {3, {{1, 3.0}, {2, 4.0}, {3, 5.0}}},
        {4, {{2, 3.0}, {3, 4.0}, {4, 5.0}}},
    };

    vector<Movie> movies = {
        {1, "Movie 1"},
        {2, "Movie 2"},
        {3, "Movie 3"},
        {4, "Movie 4"},
    };

    User user = users[0];
    vector<Movie> recommendations = getRecommendations(user, users, movies);

    cout << "Recommendations for user " << user.id << ":" << endl;
    for (const auto& movie : recommendations) {
        cout << movie.title << endl;
    }

    return 0;
}