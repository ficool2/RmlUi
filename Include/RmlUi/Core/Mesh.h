#pragma once

#include "Header.h"
#include "Texture.h"
#include "Vertex.h"

namespace Rml {

struct RMLUICORE_API Mesh {
	Vector<Vertex> vertices;
	Vector<int> indices;
	Vector<byte> data;

	explicit operator bool() const { return !indices.empty() || !data.empty(); }
	friend bool operator==(const Mesh& lhs, const Mesh& rhs)
	{
		return lhs.vertices == rhs.vertices && lhs.indices == rhs.indices && lhs.data == rhs.data;
	}
	friend bool operator!=(const Mesh& lhs, const Mesh& rhs) { return !(lhs == rhs); }
};

struct RMLUICORE_API TexturedMesh {
	Mesh mesh;
	Texture texture;
};

using TexturedMeshList = Vector<TexturedMesh>;

} // namespace Rml
