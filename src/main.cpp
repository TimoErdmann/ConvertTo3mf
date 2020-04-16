/*
 * Command line application to convert models to 3MF.
 * Copyright (C) 2020 Ghostkeeper
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for details.
 * You should have received a copy of the GNU Affero General Public License along with this library. If not, see <https://gnu.org/licenses/>.
 */

#include <iostream>

#include "main.hpp"

int main(int argc, char** argv) {
	show_help();
	return 0;
}

void show_help() {
	std::cout << "Convert 3D models to 3MF.\n"
		"Usage:\n"
		"  convertobjto3mf filename [--output=output_filename]\n"
		"\n"
		"Required parameters:\n"
		"  * filename: The name of the input file to convert to 3MF.\n"
		"\n"
		"Optional parameters:\n"
		"  * --output=output_filename: Store the resulting 3MF file in the specified location. By default, the result will be stored in the same location as the input file, but with the file extension changed to .3mf." << std::endl;
}