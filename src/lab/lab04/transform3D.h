#pragma once

#include "utils/glm_utils.h"


namespace transform3D
{
    // Translation matrix
    inline glm::mat4 Translate(float translateX, float translateY, float translateZ)
    {
        // TODO(student): Ex. 1
        glm::mat4 translation = glm::mat4(1);
        translation[3][0] = translateX;
        translation[3][1] = translateY;
        translation[3][2] = translateZ;
        return translation;
    }

    // Scaling matrix
    inline glm::mat4 Scale(float scaleX, float scaleY, float scaleZ)
    {
        // TODO(student): Ex. 1
		 glm::mat4 scaling = glm::mat4(1);
         scaling[0][0] = scaleX;
         scaling[1][1] = scaleY;
         scaling[2][2] = scaleZ;
         scaling[3][3] = 1;

        return scaling;
    }

    // Rotation matrix relative to the OZ axis
    inline glm::mat4 RotateOZ(float radians)
    {
        // TODO(student): Ex. 1
        glm::mat4 rotation = glm::mat4(1);
        rotation[0][0] = cos(radians);
        rotation[0][1] = sin(radians);
        rotation[1][0] = -sin(radians);
        rotation[1][1] = cos(radians);


        return rotation;
    }

    // Rotation matrix relative to the OY axis
    inline glm::mat4 RotateOY(float radians)
    {
        glm::mat4 rotation = glm::mat4(1);
        rotation[0][0] = cos(radians);
        rotation[0][2] = sin(radians);
        rotation[2][0] = -sin(radians);
        rotation[2][2] = cos(radians);

        // TODO(student): Ex. 1
        return rotation;
    }

    // Rotate matrix relative to the OX axis
    inline glm::mat4 RotateOX(float radians)
    {
        // TODO(student): Ex. 1
        glm::mat4 rotation = glm::mat4(1);
        rotation[1][1] = cos(radians);
        rotation[1][2] = -sin(radians);
        rotation[2][1] = sin(radians);
        rotation[2][2] = cos(radians);

        return rotation;
    }

    // Perspective projection matrix
    inline glm::mat4 Perspective(
        float fovy, float aspect, float zNear, float zFar)
    {
        // TODO(student): Ex. 2

        glm::mat4 view = glm::mat4(1);

        view[0][0] = 1 / (glm::tan(fovy / 2) * aspect);
        view[1][1] = 1 / glm::tan(fovy / 2);
        view[2][2] = -(zFar + zNear) / (zFar - zNear);
        view[3][2] = (- 2) * zFar * zNear / (zFar - zNear);
        view[2][3] = -1;

        return view;
    }

    // View matrix
    inline glm::mat4 View(
        const glm::vec3& position,
        const glm::vec3& forward,
        const glm::vec3& right,
        const glm::vec3& up)
    {
        // TODO(student): Ex. 4

        glm::mat4 vect = glm::mat4(1);
        vect[0][0] = right.x;
        vect[1][0] = right.y;
        vect[2][0] = right.z;
        vect[0][1] = up.x;
        vect[1][1] = up.y;
        vect[2][1] = up.z;
        vect[0][2] = forward.x;
        vect[1][2] = forward.y;
        vect[2][2] = forward.z;

        glm::mat4 positionMat = glm::mat4(1);
        positionMat[3][0] = -position.x;
        positionMat[3][1] = -position.y;
        positionMat[3][2] = -position.z;
        return vect * positionMat;
    }

}   // namespace transform3D
