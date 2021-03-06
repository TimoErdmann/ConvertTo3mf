/*
 * Command line application to convert models to 3MF.
 * Copyright (C) 2020 Ghostkeeper
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for details.
 * You should have received a copy of the GNU Affero General Public License along with this library. If not, see <https://gnu.org/licenses/>.
 */

#ifndef THREEMF_HPP
#define THREEMF_HPP

#include <array> //To store triangles.
#include <sstream> //A buffer to write the 3D model data into before zipping it.
#include <string> //To accept a file name.
#include <zip.h> //To write zip archives to file, part of the format of 3MF.

#include "model.hpp" //To convert from 3D models.

namespace convertto3mf {

/*!
 * This class represents a 3MF file.
 *
 * This class can convert from our internal representation to a representation
 * corresponding to how 3MF saves thing, and then save that to a file.
 */
class ThreeMF {
public:
	/*!
	 * Writes a model to a file in the 3MF format.
	 * \param filename The path to the file to write.
	 * \param model The model to write to this file.
	 */
	static void export_to_file(const std::string& filename, const Model& model);

protected:
	/*!
	 * For each mesh, a list of vertices.
	 *
	 * The vertices within one mesh are supposed to be unique. To save file
	 * size, the same vertex should not appear in this list twice, but rather be
	 * referenced by the same index from the face.
	 */
	std::vector<std::vector<Point3>> vertices;

	/*!
	 * For each mesh, a list of triangles.
	 *
	 * The triangles refer to indices within the corresponding list of vertices.
	 *
	 * 3MF doesn't support faces with more than 3 vertices.
	 */
	std::vector<std::vector<std::array<size_t, 3>>> triangles;

	/*!
	 * Fill the 3MF file from the common model data structure.
	 */
	void fill_from_model(const Model& model);

	/*!
	 * Write the 3MF file to a file.
	 * \param filename The path to the file to write.
	 */
	void write(const std::string& filename) const;

	/*!
	 * Write the 3D model data to a string stream.
	 *
	 * This serialises the contents of this `ThreeMF` instance into a stream.
	 * The archive can then later read out the contents of this stream to
	 * compress it into the archive. This way the data does not get deallocated
	 * before the zip archive is closed.
	 * \param model_data An empty string stream to write into.
	 */
	void write_model_data(std::stringstream& model_data) const;
};

}

#endif //THREEMF_HPP

