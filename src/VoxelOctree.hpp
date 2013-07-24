/*
Copyright (c) 2013 Benedikt Bitterli

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
   distribution.
*/

#ifndef VOXELOCTREE_HPP_
#define VOXELOCTREE_HPP_

#include <vector>
#include <stdint.h>

#include "math/Vec3.hpp"

class VoxelData;

class VoxelOctree {
	static const int32_t MaxScale = 23;

	std::vector<uint32_t> _octree;
	std::vector<uint32_t> _farPointers;

	VoxelData *_voxels;
	Vec3 _center;

	void buildOctree(int x, int y, int z, int size, uint32_t descriptorIndex);

public:

	void save(const char *path);
	bool raymarch(const Vec3 &o, const Vec3 &d, float rayScale, uint32_t &normal, float &t);

	Vec3 center() const {
		return _center;
	}

	VoxelOctree(const char *path);
	VoxelOctree(VoxelData *voxels);
};

#endif /* VOXELOCTREE_HPP_ */