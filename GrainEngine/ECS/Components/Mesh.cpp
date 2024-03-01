#include "Mesh.h"

namespace GrainEngine::ECS::Components
{
	Mesh::Mesh() :
		IComponent()
	{
		_pVertices = std::make_unique<Vertex[]>(_verticesCount);
        _pIndices = std::make_unique<unsigned int[]>(_indicesCount);

        //(_pVertices.get())[0] = { -1.0f, 1.0f, 0.0f };
        //(_pVertices.get())[1] = { 1.0f, 1.0f, 0.0f };
        //(_pVertices.get())[2] = { -1.0f, -1.0f, 0.0f };
        //(_pVertices.get())[3] = { 1.0f, -1.0f, 0.0f };

        (_pVertices.get())[0] = { -0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f };
        (_pVertices.get())[1] = { 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f };
        (_pVertices.get())[2] = { -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f };
        (_pVertices.get())[3] = { 0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f };

        (_pVertices.get())[4] = { 0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f };
        (_pVertices.get())[5] = { 0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f };
        (_pVertices.get())[6] = { 0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f };
        (_pVertices.get())[7] = { 0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f };

        (_pVertices.get())[8] = { -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f };
        (_pVertices.get())[9] = { -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f };
        (_pVertices.get())[10] = { -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f };
        (_pVertices.get())[11] = { -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f };

        (_pVertices.get())[12] = { 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 1.0f };
        (_pVertices.get())[13] = { -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 1.0f };
        (_pVertices.get())[14] = { 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 1.0f };
        (_pVertices.get())[15] = { -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 1.0f };

        (_pVertices.get())[16] = { -0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 1.0f };
        (_pVertices.get())[17] = { 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 1.0f, 1.0f };
        (_pVertices.get())[18] = { 0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 1.0f };
        (_pVertices.get())[19] = { -0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 1.0f, 1.0f };

        (_pVertices.get())[20] = { 0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f };
        (_pVertices.get())[21] = { -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f };
        (_pVertices.get())[22] = { 0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f };
        (_pVertices.get())[23] = { -0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f };

        (_pIndices.get())[0] = 0;
        (_pIndices.get())[1] = 1;
        (_pIndices.get())[2] = 2;
        (_pIndices.get())[3] = 0;
        (_pIndices.get())[4] = 3;
        (_pIndices.get())[5] = 1;

        (_pIndices.get())[6] = 4;
        (_pIndices.get())[7] = 5;
        (_pIndices.get())[8] = 6;
        (_pIndices.get())[9] = 4;
        (_pIndices.get())[10] = 7;
        (_pIndices.get())[11] = 5;

        (_pIndices.get())[12] = 8;
        (_pIndices.get())[13] = 9;
        (_pIndices.get())[14] = 10;
        (_pIndices.get())[15] = 8;
        (_pIndices.get())[16] = 11;
        (_pIndices.get())[17] = 9;

        (_pIndices.get())[18] = 12;
        (_pIndices.get())[19] = 13;
        (_pIndices.get())[20] = 14;
        (_pIndices.get())[21] = 12;
        (_pIndices.get())[22] = 15;
        (_pIndices.get())[23] = 13;

        (_pIndices.get())[24] = 16;
        (_pIndices.get())[25] = 17;
        (_pIndices.get())[26] = 18;
        (_pIndices.get())[27] = 16;
        (_pIndices.get())[28] = 19;
        (_pIndices.get())[29] = 17;

        (_pIndices.get())[30] = 20;
        (_pIndices.get())[31] = 21;
        (_pIndices.get())[32] = 22;
        (_pIndices.get())[33] = 20;
        (_pIndices.get())[34] = 23;
        (_pIndices.get())[35] = 21;
	}
}