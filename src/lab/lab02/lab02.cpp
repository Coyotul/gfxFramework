#include "lab/lab02/lab02.h"

#include <vector>

using namespace std;
using namespace lab;

Lab02::Lab02()
{
    window->SetSize(1280, 720);
}


Lab02::~Lab02()
{
}

void Lab02::Initialize()
{
    image->Init(1280, 720, 3 /* channels */);
    depthImage->Init(1280, 720);

    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(290, 90,  0.5), glm::vec3(1, 0, 0)),
            VertexFormat(glm::vec3(1099, 450,  0.5), glm::vec3(0, 1, 0)),
            VertexFormat(glm::vec3(650, 719,  0.5), glm::vec3(0, 0, 1)),

            VertexFormat(glm::vec3(200, 450,  0), glm::vec3(0, 1, 1)),
            VertexFormat(glm::vec3(830, 719,  1), glm::vec3(1, 1, 0)),
            VertexFormat(glm::vec3(1099, 0,  1), glm::vec3(1, 0, 1)) };

        vector<unsigned int> indices
        {
            0, 1, 2,    // indices for first triangle
            3, 4, 5,    // indices for second triangle
        };

        Rasterize(vertices, indices);
        
        const int circlePoints = 100;

        vector<VertexFormat> circleVertices;
        
        float R = 300;

        for (int i = 0; i < circlePoints; i++) {
			float angle = 2 * glm::pi<float>() * i / circlePoints;
            float x = R * cos(angle);
            float y = R * sin(angle);
            circleVertices.push_back(
				VertexFormat(glm::vec3(x+640, y + 360, 0.0f), glm::vec3(1, 0, 1))
			);


            float angle2 = 2 * glm::pi<float>() * (i + 1) / circlePoints;
            float x2 = R * cos(angle2);
            float y2 = R * sin(angle2);
            circleVertices.push_back(
                VertexFormat(glm::vec3(x2+640, y2+360, 0.0f), glm::vec3(1, 0, 1))
            );

            circleVertices.push_back(
                VertexFormat(glm::vec3(640, 360, 0.0f), glm::vec3(1, 0, 1))
				);
		}

        vector<unsigned int> circleIndices;

        for (int i = 0; i < circlePoints*3; i) {
			circleIndices.push_back(i++);
			circleIndices.push_back(i++);
			circleIndices.push_back(i++);
		}

        Rasterize(circleVertices, circleIndices);
    }
}

void Lab02::Rasterize(
    const vector<VertexFormat> &vertices,
    const vector<unsigned int> &indices)
{
    for (int i = 0; i < indices.size(); i += 3) {
        auto v1 = vertices[indices[i]];
        auto v2 = vertices[indices[i+1]];
        auto v3 = vertices[indices[i+2]];

        TriangleRasterizer::Rasterize(
            v1, v2, v3, image, depthImage
        );
    }
}
