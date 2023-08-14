#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

struct graph {
	int val;
	std::vector<graph*> children;

	graph(int v) {
		val = v;
	}

};




int main(void) {
	std::unordered_map<int, std::pair<int, int>> potions; // pair first -> A, second -> B

	std::stringstream ss("7 3 1 1 2 2 1 3 3 4 3 4 1 7 1 6");
	int i = 1, z = 0, length;
	ss >> length;

	// vector of nodes and relations between potions
	std::vector<graph*> potions_graph;
	for (int var = 1; var <= length; var++) {
		potions_graph.push_back(new graph(var));
	}
	length -= 2;

	/// queue of potions that require FUTURE potions
	std::queue<std::vector<int>> que;

	while (ss && i <= length) {
		int j;
		ss >> j; // j is amount of ingredients

		std::vector<int> for_que; ///we store values in vector for - if the potion requires future potion - we add vector to queue
		for_que.push_back(i + 2);
		for_que.push_back(j);
		bool queing = false; // variable to check if the future potion is needed

		std::pair<int, int> potion = { 0,0 }; // current potion

		while (j > 0) {
			int tmp;
			ss >> tmp;
			for_que.push_back(tmp);
			switch (tmp) {
			case 1://ingridient A
				potion.first++;
				break;
			case 2://ingridient B
				potion.second++;
				break;
			default: //another potion
				if (potions.find(tmp) == potions.end()) {
					std::cout << "needed future potion\n";
					queing = true;
					//PUT A FUNCTION HERE THAT CHECKS FOR LOOPS! IF POTION'S INVOLVED IN LOOP - DELETE FROM UNORDERDED_MAP
				}
				else {
					std::pair<int, int> tmp_pair = potions[tmp];
					potion.first += tmp_pair.first;
					potion.second += tmp_pair.second;
				}
				break;
			}
			j--;
		}
		if (queing) {
			que.push(for_que);
		}
		else {
			potions.insert({ i + 2, potion });
		}

		i++;

	}


	std::cout << "\n potions\n";
	for (auto x : potions) {
		std::cout << x.first << " " << x.second.first << " " << x.second.second << std::endl;
	}
	std::cout << "\n queue\n";
	while (!que.empty()) {
		std::vector<int> tmp = que.front();
		for (int x : tmp) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
		que.pop();
	}
	/*
	int i = 0;
	std::vector<int> vec;
	for (int j=0; j < 10; j++) {
		vec.push_back(i++);
	}
	for (int x : vec) {
		std::cout << x << " ";
	}*/

}