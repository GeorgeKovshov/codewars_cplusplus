
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

bool check_loop_potions(graph* g, std::vector<graph*>& visited, std::vector<graph*>& rec_stack) {
	/*checks the potion dependancies for loops*/
	if (find(rec_stack.begin(), rec_stack.end(), g) != rec_stack.end()) return true;
	if (find(visited.begin(), visited.end(), g) != visited.end()) return false;
	int length = rec_stack.size();
	visited.push_back(g);
	rec_stack.push_back(g);
	for (graph* c : g->children) {
		if (check_loop_potions(c, visited, rec_stack)) return true;
	}
	rec_stack.erase(rec_stack.begin() + length);
	return false;
}

void memorize_bad_potions(graph* g, std::vector<int>& visited) {
	/*function that marks potions with a loop in their making*/
	if (find(visited.begin(), visited.end(), g->val) != visited.end()) return;
	visited.push_back(g->val);
	for (graph* c : g->children) {
		memorize_bad_potions(c, visited);
	}

}


void cataloging_potions(std::stringstream& ss, std::unordered_map<int, std::pair<int, int>>& potions, std::vector<int>& bad_potions, std::queue<std::vector<int>>& que) {
	/*function that puts the potions into categories: fills potions, marks potions with loop, queues the potions out of order*/
	int i = 1, z = 0, length;
	ss >> length;

	// vector of nodes and relations between potions
	std::vector<graph*> potions_graph;
	for (int var = 0; var <= length; var++) {
		potions_graph.push_back(new graph(var));
	}
	length -= 2;
	while (ss && i <= length) {
		int j;
		ss >> j; // j is amount of ingredients

		std::vector<int> for_que; ///we store values in vector for - if the potion requires future potion - we add vector to queue
		for_que.push_back(i + 2);
		for_que.push_back(j);
		bool queing = false; // variable to check if the future potion is needed

		std::pair<int, int> potion = { 0,0 }; // current potion

		bool cyclic_potion = false;



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
					potions_graph[i + 2]->children.push_back(potions_graph[tmp]);

					std::vector<graph*> visited;
					std::vector<graph*> rec_stack;
					if (check_loop_potions(potions_graph[tmp], visited, rec_stack)) { // if we detect a loop
						cyclic_potion = true;	//we make sure not to add the potion
						memorize_bad_potions(potions_graph[tmp], bad_potions); // and mark all involved in a loop potions as bad
					}
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
		if (!cyclic_potion) {
			if (queing) {
				que.push(for_que);
			}
			else {
				potions.insert({ i + 2, potion });
			}
		}
		i++;

	}

}

void adding_queued_potions(std::unordered_map<int, std::pair<int, int>>& potions, std::vector<int>& bad_potions, std::queue<std::vector<int>>& que) {
	/* going through all the (not looped) out of order potions until we add them all to main potions list */
	while (!que.empty()) {
		std::vector<int> tmp = que.front();
		que.pop();
		if (find(bad_potions.begin(), bad_potions.end(), tmp[0]) != bad_potions.end()) continue;

		int number = tmp[0];
		int length = tmp.size();
		int j = 2;
		std::pair<int, int> potion = { 0,0 };
		bool queing = false;
		while (j < length) {
			switch (tmp[j]) {
			case 1://ingridient A
				potion.first++;
				break;
			case 2://ingridient B
				potion.second++;
				break;
			default: //another potion
				if (potions.find(tmp[j]) == potions.end()) {
					std::cout << "needed future potion\n";
					queing = true;

				}
				else {
					std::pair<int, int> tmp_pair = potions[tmp[j]];
					potion.first += tmp_pair.first;
					potion.second += tmp_pair.second;
				}
				break;
			}
			j++;
		}
		if (queing) {
			que.push(tmp);
		}
		else {
			potions.insert({ tmp[0], potion });
		}
		std::cout << std::endl;
	}


}

void can_make_potions(std::stringstream& ss1, std::unordered_map<int, std::pair<int, int>>& potions) {
	int i; ss1 >> i;
	while (i > 0) {
		int foo, bar, baz;
		ss1 >> foo; ss1 >> bar; ss1 >> baz;
		//std::cout << foo << " " << bar << " " << baz << " \n"  ;
		if (potions.find(baz) != potions.end()
			&& potions[baz].first <= foo
			&& potions[baz].second <= bar)
			std::cout << "1 ";
		else std::cout << "0 ";
		i--;
	}
}


void dialogue_window(std::stringstream& ss) {
	int amount;
	std::cout << "How many potion recipies do you have? ";
	std::cin >> amount;
	ss << amount;
	int counter = 0;
	amount -= 2;
	while (amount > 0) {
		std::cout << "\n Potion " << ++counter << ": How many ingredients?";
		int tmp;
		std::cin >> tmp;
		ss << " " << tmp;
		int counter1 = 0;
		while (tmp > 0) {
			std::cout << "\n \tingridient " << ++counter1 << ": ";

			int tmp1;
			std::cin >> tmp1;
			ss << " " << tmp1;
			tmp--;
		}

		amount--;
	}
	std::cout << "\nHow many potions do you want to make? ";
	std::cin >> amount;
	ss << " " << amount;
	counter = 0;
	while (amount > 0) {
		std::cout << "\n Potion " << ++counter << ":\n";
		int tmp;
		std::cout << "\n \t How many A ingridients do you have? ";
		std::cin >> tmp;
		ss << " " << tmp;
		std::cout << "\n \t How many B ingridients do you have? ";
		std::cin >> tmp;
		ss << " " << tmp;
		std::cout << "\n \t What potion do you want to make? ";
		std::cin >> tmp;
		ss << " " << tmp;
		amount--;
	}
}


int main(void) {
	std::unordered_map<int, std::pair<int, int>> potions; // pair first -> A, second -> B

	std::stringstream ss;
	dialogue_window(ss);



	//std::stringstream ss("7 3 1 1 2 2 1 3 3 4 3 4 1 7 1 6 3 8 4 5 9 2 5 10 10 6");
	//std::stringstream ss("8 2 5 1 3 1 1 2 2 1 4 3 5 4 5 1 8 1 7");

	/// queue of potions that require FUTURE potions
	std::queue<std::vector<int>> que;

	//potions involved in a cycle
	std::vector<int> bad_potions;

	cataloging_potions(ss, potions, bad_potions, que);


	adding_queued_potions(potions, bad_potions, que);

	std::cout << "\n potions\n";
	for (auto x : potions) {
		std::cout << x.first << " " << x.second.first << " " << x.second.second << std::endl;
	}

	///NOW ANSWERS
	std::cout << "\n answers\n";

	can_make_potions(ss, potions);



}