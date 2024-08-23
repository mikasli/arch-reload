#include<vector>
#include<stdlib.h>
#include<iostream>
#include<fstream>

struct FilePair {
	std::string old_file_path;
	std::string new_file_path;

	FilePair(std::string old_file_path,std::string new_file_path) {
		this->old_file_path = old_file_path;
		this->new_file_path = new_file_path;
	}
};


void parse_file_paths(std::vector<FilePair>& file_paths) {
	std::ifstream structure_config;
	structure_config.open("./configs/structure.conf");

	std::string line;
	while (getline(structure_config, line)) {
		if (line[0] != '#' && !line.empty()) {
			file_paths.push_back(FilePair(line.substr(0, line.find(':')), line.substr(line.find(':') + 1, line.length())));
		}
	}

	structure_config.close();
}

void copy_files(std::vector<FilePair> file_paths) {
	for (FilePair pair : file_paths) {
		std::string mkdir_command = "mkdir -p " + pair.new_file_path.substr(0, pair.new_file_path.find_last_of('/'));
		std::cout << "[Executing] " << mkdir_command << std::endl;
		system(mkdir_command.c_str());

		std::string copy_command = "cp -r " + pair.old_file_path + " " + pair.new_file_path;
		std::cout << "[Executing] " << copy_command << std::endl;
		system(copy_command.c_str());
	}
}

void handle_structure() {
	std::vector<FilePair> file_paths;
	parse_file_paths(file_paths);
	copy_files(file_paths);
}

void handle_packages() {
	std::ifstream package_config;
	package_config.open("./configs/packages.conf");

	std::string line;
	while (getline(package_config, line)) {
		if (line[0] != '#' && !line.empty()) {
			std::string pkg_command = "yay -S --needed --noconfirm " + line;
			std::cout << "[Executing] " << pkg_command << std::endl;
			system(pkg_command.c_str());
		}
	}

	package_config.close();
}

int main() {
	handle_structure();
	handle_packages();
	return 0;
}
