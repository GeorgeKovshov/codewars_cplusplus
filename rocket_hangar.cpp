#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
//#include <string>


struct rocket {
	int day;
	int hour;
	int minute;
	int id;
	char status;

	rocket() {
		day = 0;
		hour = 0;
		minute = 0;
		id = 0;
		status = 'R'; //R stands for Ready;
	}

	rocket* copy() {
		rocket* cp = new rocket();
		cp->day = day;
		cp->hour = hour;
		cp->minute = minute;
		cp->id = id;
		cp->status = status;
		return cp;
	}

	void copy(rocket* x) {
		day = x->day;
		hour = x->hour;
		minute = x->minute;
		status = x->status;
	}

	void reset() {
		day = 0;
		hour = 0;
		minute = 0;
		status = 'R';
	}
};


class hangar {
	std::unordered_map<int, rocket*> rockets;
	std::unordered_map<int, long> rocket_traversal;
	std::vector<rocket*> rocket_launches;
public:

	hangar() {

	}

	void put_rocket_in(std::vector<rocket*>& rocket_launches, rocket* r) {
		int length = rocket_launches.size() - 1;
		rocket_launches.push_back(r);
		while (length >= 0) {
			if (rocket_launches[length]->day < rocket_launches[length + 1]->day) {
				return;
			}
			else if (rocket_launches[length]->day == rocket_launches[length + 1]->day) {
				if (rocket_launches[length]->hour < rocket_launches[length + 1]->hour) {
					return;
				}
				else if (rocket_launches[length]->hour == rocket_launches[length + 1]->hour) {
					if (rocket_launches[length]->minute <= rocket_launches[length + 1]->minute) {
						return;
					}
				}

			}
			rocket* tmp = rocket_launches[length];
			rocket_launches[length] = rocket_launches[length + 1];
			rocket_launches[length + 1] = tmp;
			length--;
		}

		return;

	}

	int insert_flight(std::stringstream& ss, rocket* r) {
		int tmp; std::string token;
		std::vector<int*> vec = { &r->day, &r->hour, &r->minute, &r->id };

		for (int i = 0; i < vec.size(); i++) {
			std::getline(ss, token, ' ');
			if (ss.eof()) return 1;
			try
			{
				tmp = stoi(token);
			}
			catch (std::exception& err)
			{
				std::cout << "Conversion failure: " << err.what() << std::endl; // Note: what() tells the exact error
				return 2;
			}
			*vec[i] = tmp;

		}
		std::getline(ss, token, ' ');
		r->status = token[0];
		return 0;

	}

	void processing_input(std::stringstream& ss) {
		while (!ss.eof()) {
			rocket* r = new rocket();
			int error = insert_flight(ss, r);
			if (error == 1) break;
			else if (error == 2) return;
			rocket* r1 = new rocket();
			r1->id = r->id;
			if (rockets.find(r->id) == rockets.end()) {
				rockets.insert({ r->id, r1 });
				rocket_traversal.insert({ r->id, 0 });
			}
			if (rockets.find(r->id) == rockets.end()) rockets.insert({ r->id, r1 });
			put_rocket_in(rocket_launches, r);

		}
	}


	void print() {
		for (rocket* x : rocket_launches) {
			std::cout << x->day << " " << x->hour << " " << x->minute << " " << x->id << " " << x->status << "\n";
		}
	}

	void calculate_distance() {
		for (rocket* x : rocket_launches) {
			rocket* tmp = rockets[x->id];
			if (tmp->status == 'R') {
				tmp->copy(x);
			}
			else if (x->status == 'C' || x->status == 'S') {
				long time_start = tmp->day * 1440 + tmp->hour * 60 + tmp->minute;
				long time_end = x->day * 1440 + x->hour * 60 + x->minute;

				rocket_traversal[tmp->id] += time_end - time_start;
				tmp->reset();
			}
		}
	}

	void print_distance() {

		for (auto x : rocket_traversal) {

			std::cout << x.second << " ";
		}
	}

	void manual_input() {
		std::string input; int i;
		std::cout << "How many log inputs? ";
		std::getline(std::cin, input);
		try
		{
			i = stoi(input);
		}
		catch (std::exception& err)
		{
			std::cout << "Conversion failure: " << err.what() << std::endl;
			return;
		}
		std::stringstream ss;
		while (i > 0) {
			std::cout << "\nLog " << i << ": ";
			std::getline(std::cin, input);
			ss << input; ss << " ";
			i--;
		}
		processing_input(ss);
		calculate_distance();
	}

	void automated_input(std::string input) {
		std::stringstream ss(input);
		processing_input(ss);
		calculate_distance();
	}



};

void using_hangar() {
	std::string input("50 7 25 3632 A 14 23 52 212372 S 15 0 5 3632 C 14 21 30 212372 A 50 7 26 3632 C 14 21 30 3632 A 14 21 40 212372 B 14 23 52 3632 B");//
	///std::stringstream ss(input);

	hangar* h = new hangar();
	h->manual_input();
	//h->automated_input(input);

	h->print();

	h->print_distance();
}
