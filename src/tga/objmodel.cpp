/**@file	/data/Projets/MyTinyRenderer/src/tga/objmodel.cpp
 * @author	talos
 * @version	802
 * @date
 * 	Created:	11th Apr 2020
 * 	Last Update:	11th Apr 2020
 */

#include "objmodel.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

Model::Model(const char* filename)
{
    std::ifstream in;
    in.open(filename, std::ifstream::in);
    if (in.fail())
        return;

    std::string line;
    char trash;
    int itrash, idx;
    while (!in.eof()) {
        std::getline(in, line);
        std::istringstream iss(line.c_str());
        if (!line.compare(0, 2, "v ")) {
            iss >> trash;
            Vec3f v;
            for (int i=0; i<3; ++i)
                iss >> v.raw[i];
            mVerts.push_back(v);
        } else if (!line.compare(0, 2, "f ")) {
            std::vector<int> f;
            iss >> trash;
            while (iss >> idx >> trash >> itrash >> trash >> itrash) {
                idx--; // in wavefront obj all indices start at 1, not zero
                f.push_back(idx);
            }
            mFaces.push_back(f);
        }
    }
    std::cerr << "# v# " << mVerts.size() << " f# "  << mFaces.size() << std::endl;
}

size_t Model::nb_verts() const
{
    return mVerts.size();
}

size_t Model::nb_faces() const
{
    return mFaces.size();
}

Model::Face Model::face(size_t idx) const
{
    return mFaces[idx];
}

Vec3f Model::vert(size_t idx) const
{
    return mVerts[idx];
}
