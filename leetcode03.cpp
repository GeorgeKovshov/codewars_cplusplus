#include "Header.h"

unsigned int strCount(const std::string& word, char letter) {
	int count = 0;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == letter) {
			count++;
		}
	}
	return count;
}


// FINDING A CYCLE IN A GRAPH
/* bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<UF*> vertices;
    for (int i = 0; i < numCourses; i++) {
        vertices.push_back(new UF(i));
    }
    for (std::vector<int> pr : prerequisites) {
        vertices[pr[0]]->previous.push_back(vertices[pr[1]]);
    }
    std::vector<UF*> visited;
    for (int i = 0; i < numCourses; i++) {
        if (find(visited.begin(), visited.end(), vertices[i]) != visited.end()) { // SEARCHING IN A VECTOR
            continue;
        }
        std::vector<UF*> rec_stack;
        if (check_cycle(visited, vertices[i], rec_stack)) return false;

    }
    return true;

}*/
/*  FINDING AN ELEMENT IN UNORDERED MAP
std::unordered_map<std::string, int> hash;
if (hash.find(equations[i][0]) == hash.end()) {
    hash.insert({ equations[i][0], ind++ });
*/


int lowest(std::string s) {
    std::unordered_map<char, int> hash;
    for (int i = 0; i < s.length(); i++) {
        if (hash.find(s[i]) == hash.end()) { // INSERT INTO THE UNORDERED MAP
            hash.insert({ s[i], 0 });
        }
        hash[s[i]]++;
    }
    for (std::pair<char, int> i : hash) { // PRINTING THE UNORDERED MAP
        std::cout << i.first << " " << i.second << "\n";
    }
    int count = 0;
    for (std::pair<char, int> i : hash) {
        if (i.second == 1) {
            count++;
        }
    }
    if (count < 2) { return 1; }
    std::vector<int> result(count);
    int remainder = s.length() - count;
    int i = 0;
    while (remainder > 0) {
        result[i++] += 2;
        if (i >= count) { i = 0; }
        remainder -= 2;

    }
    return (*std::min_element(result.begin(), result.end())) + 1;

}


std::string alphabetWar(std::string fight)
{
    std::unordered_map<char, int> map{
        {'w',-4},
        {'p', -3},
        {'b', -2},
        {'s', -1},
        {'m',  4},
        {'q',  3},
        {'d',  2},
        {'z',  1}
    };
    int sum = 0;
    for (int i = 0; i < fight.length(); i++) {
        if (fight[i] == '*') {
            if (i > 0 && map.find(fight[i - 1]) != map.end()) { sum -= map[fight[i - 1]]; }
            if (i < fight.length() - 1 && map.find(fight[i - 1]) != map.end()) { sum -= map[fight[i + 1]]; }
        }
        if (map.find(fight[i]) != map.end()) {
            sum += map[fight[i]];
        }

    }
    if (sum == 0) {
        return "Let's fight again!";
    }
    if (sum >= 0) {
        return "Right side wins!";
    }
    if (sum <= 0) {
        return "Left side wins!";
    }
    for (std::pair<char, int> p : map) {
        std::cout << p.first << " " << p.second << "\n";
    }
    return "Have mercy!";
}