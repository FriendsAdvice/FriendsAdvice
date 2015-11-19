#include <iostream>
#include <unordered_map>
using namespace std;

class AngleOfUsers {
public:
    AngleOfUsers(unordered_map<std::string, int> vector_1, unordered_map<std::string, int> vector_2);
    ~AngleOfUsers();
    double GetScore();
private:
    double score;
};


AngleOfUsers::AngleOfUsers(unordered_map<std::string, int> vector_1, unordered_map<std::string, int> vector_2) {
    int sum = 0;
    double vector_1_length = 0.0, vector_2_length = 0.0;
    for (auto it = vector_1.begin(); it != vector_1.end(); ++it ) {
        auto temp = vector_2.find((*it).first);
        if (temp != vector_2.end()) {
            sum += (*it).second * (*temp).second;
        }
    }
    for (auto it = vector_1.begin(); it != vector_1.end(); ++it )
        vector_1_length += (*it).second * (*it).second;
    for (auto it = vector_2.begin(); it != vector_2.end(); ++it )
        vector_2_length += (*it).second * (*it).second;
    score = sum / sqrt(vector_1_length * vector_2_length);

}

AngleOfUsers::~AngleOfUsers() {
}

double AngleOfUsers::GetScore() {
    return score;
}

