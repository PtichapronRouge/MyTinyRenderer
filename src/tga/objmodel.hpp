/**@file	/data/Projets/MyTinyRenderer/src/tga/objmodel.hpp
 * @author	talos
 * @version	802
 * @date
 * 	Created:	11th Apr 2020
 * 	Last Update:	11th Apr 2020
 */

#ifndef OBJMODEL_HPP
#define OBJMODEL_HPP

#include "vector.hpp"

#include <vector>

class Model
{
    public:
        using Face = std::vector<int>;

    public:
        Model(const char* filename);

        size_t nb_verts() const;
        size_t nb_faces() const;

        Face face(size_t idx) const;
        Vec3f vert(size_t idx) const;

    private:
        std::vector<Vec3f> mVerts;
        std::vector<Face> mFaces;
};



#endif // OBJMODEL_HPP
