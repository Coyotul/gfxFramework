#include "lab/lab01/lab01.h"

#include <vector>

using namespace std;
using namespace lab;

Lab01::Lab01()
{
    window->SetSize(1280, 720);
}


Lab01::~Lab01()
{
}

void Lab01::Initialize()
{
    Exercise1();
    Exercise2();
    Exercise3();
    Exercise4();
    Exercise5();
    Exercise6();
}

void Lab01::Exercise1()
{
    SetExercise();

    //TODO(student): Ex. 1
    {
        SetPanel("1", { -3, -2, 100 }, { 0, 0, 1280, 720 });

        glm::vec2 v1(5, 2);
        glm::vec2 v2(2, 3);

        //v1 + v2
        auto v3 = v1 + v2;

        RenderVector(v1, glm::vec3(1, 0, 0), "v1");
        RenderVector(v2, glm::vec3(0, 1, 0), "v2");
        RenderVector(v3, glm::vec3(0, 0, 1), "v12");
        RenderVector(v1, glm::vec3(1, 0, 0), "v1", v2);
        RenderVector(v2, glm::vec3(0, 1, 0), "v2", v1);
    }
}

void Lab01::Exercise2()
{
    SetExercise();

    //TODO(student): Ex. 2
    {
        SetPanel("2", { -7, -5, 75 }, { 0, 0, 1280, 720 });

        {
            glm::vec2 p1(1, 1);
            glm::vec2 p2(3, -3);

            RenderPoint(p1, glm::vec3(1, 0, 0), "P1");
            RenderPoint(p2, glm::vec3(0, 0, 1), "P2");

            auto v21 = p1 - p2;

            RenderVector(v21, glm::vec3(1, 0, 1), "v21", p2);
        }

        {
            glm::vec2 p3(-1, -2);
            glm::vec2 p4(-5, -4);

            RenderPoint(p3, glm::vec3(1, 0, 0), "P3");
            RenderPoint(p4, glm::vec3(0, 0, 1), "P4");

            auto v43 = p3 - p4;

            RenderVector(v43, glm::vec3(1, 0, 1), "v43", p4);
        }

        {
            glm::vec2 p5(6, 3);
            glm::vec2 p6(4, 1);

            RenderPoint(p5, glm::vec3(1, 0, 0), "P5");
            RenderPoint(p6, glm::vec3(0, 0, 1), "P6");

            auto v56 = p6 - p5;

            RenderVector(v56, glm::vec3(1, 0, 1), "v56", p5);
        }

        {
            glm::vec2 p7(5, 4);
            glm::vec2 p8(-3, 4);

            RenderPoint(p7, glm::vec3(1, 0, 0), "P7");
            RenderPoint(p8, glm::vec3(0, 0, 1), "P8");

            auto v87 = p7 - p8;
            RenderVector(v87, glm::vec3(1, 0, 1), "v87", p8);
        }
    }
}

void Lab01::Exercise3()
{
    SetExercise();

    //TODO(student): Ex. 3
    {
        SetPanel("3", { -7, -5, 75 }, { 0, 0, 1280, 720 });

        glm::vec2 v1(4, 3);
        glm::vec2 v2(-3, 3);
        glm::vec2 v3(-6, -2);
        glm::vec2 v4(-2, -4);
        glm::vec2 v5(3, -2);

        RenderVector(v1, glm::vec3(1, 0, 0), "v1");
        RenderVector(v2, glm::vec3(0, 1, 0), "v2");
        RenderVector(v3, glm::vec3(0, 1, 1), "v3");
        RenderVector(v4, glm::vec3(0, 0, 1), "v4");
        RenderVector(v5, glm::vec3(1, 0, 1), "v5");

        RenderVector(glm::normalize(v1), glm::vec3(0, 0, 0));
        RenderVector(glm::normalize(v2), glm::vec3(0, 0, 0));
        RenderVector(glm::normalize(v3), glm::vec3(0, 0, 0));
        RenderVector(glm::normalize(v4), glm::vec3(0, 0, 0));
        RenderVector(glm::normalize(v5), glm::vec3(0, 0, 0));
    }
}

void Lab01::Exercise4()
{
    SetExercise ();

    //TODO(student): Ex. 4
    {
        SetPanel("4", { -3, -2, 100 }, { 0, 0, 1280, 720 });

        glm::vec2 v1(4, 1.5);
        glm::vec2 v2(2, 3);

        RenderVector(v1, glm::vec3(1, 0, 0), "v1");
        RenderVector(v2, glm::vec3(0, 1, 0), "v2");

        auto dot_product = glm::dot(v1, v2);
        auto angle = glm::acos(dot_product / (glm::length(v1) * glm::length(v2)));

        auto angleV1 = glm::atan(v1.y, v1.x);
        auto angleV2 = glm::atan(v2.y, v2.x);
        RenderArc(angleV1, angle, glm::vec3(0, 0, 1), 3, glm::vec2(0, 0));

        auto reverseAngle = 2 * glm::pi<float>() - angle;
        RenderArc(angleV2, reverseAngle, glm::vec3(1, 0, 0), 1, glm::vec2(0, 0));
    }
}

void Lab01::Exercise5()
{
    SetExercise();

    //TODO(student): Ex. 5
    {
        SetPanel("5", { -7, -5, 75 }, { 0, 0, 1280, 720 });

        {
            glm::vec2 p1(1, 1);
            glm::vec2 p2(3, 1);
            glm::vec2 p3(2, 4);

            RenderTriangle(p1, p2, p3, glm::vec3(0, 1, 1));

            RenderPoint(p1, glm::vec3(1, 0, 0), "P1");
            RenderPoint(p2, glm::vec3(0, 0, 1), "P2");
            RenderPoint(p3, glm::vec3(0, 1, 0), "P3");

            auto a = glm::length(p2 - p1);
            auto b = glm::length(p3 - p2);
            auto c = glm::length(p1 - p3);
            auto semiperimeter = (a + b + c) / 2.0f;
            float area = glm::sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));

            glm::vec2 centroid = (p1 + p2 + p3) / 3.0f;
            RenderText(centroid, to_string(area), glm::vec3(0), 1);
        }

        {
            glm::vec2 p1(-1.5, -3.7);
            glm::vec2 p2(-2.5, 3.2);
            glm::vec2 p3(-6.1, 2.9);

            RenderTriangle(p1, p2, p3, glm::vec3(0, 1, 1));

            RenderPoint(p1, glm::vec3(1, 0, 0), "P1");
            RenderPoint(p2, glm::vec3(0, 0, 1), "P2");
            RenderPoint(p3, glm::vec3(0, 1, 0), "P3");

            auto a= glm::length(p2 - p1);
            auto b= glm::length(p3 - p2);
            auto c= glm::length(p1 - p3);
            auto semiperimeter = (a + b + c) / 2.0f;
            float area = glm::sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));
            glm::vec2 centroid = (p1 + p2 + p3) / 3.0f;
            RenderText(centroid, to_string(area), glm::vec3(0), 1);

        }

        {
            glm::vec2 p1(2.3, -2.1);
            glm::vec2 p2(7.1, -3.5);
            glm::vec2 p3(7.5, 3.7);

            RenderTriangle(p1, p2, p3, glm::vec3(0, 1, 1));

            RenderPoint(p1, glm::vec3(1, 0, 0), "P1");
            RenderPoint(p2, glm::vec3(0, 0, 1), "P2");
            RenderPoint(p3, glm::vec3(0, 1, 0), "P3");

            auto a = glm::length(p2 - p1);
            auto b = glm::length(p3 - p2);
            auto c = glm::length(p1 - p3);
            auto semiperimeter = (a + b + c) / 2.0f;
            float area = glm::sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));
            glm::vec2 centroid = (p1 + p2 + p3) / 3.0f;
            RenderText(centroid, to_string(area), glm::vec3(0), 1);

        }
    }
}

void Lab01::Exercise6()
{
    SetExercise();

    //TODO(student): Ex. 6
    {
        SetPanel("6", { -7, -5, 75 }, { 0, 0, 1280, 720 });

        glm::vec2 p1(-4, 3);
        glm::vec2 p2(6, 2);
        glm::vec2 p3(1, -4);

        RenderTriangle(p1, p2, p3, glm::vec3(0, 1, 1));

        RenderPoint(p1, glm::vec3(0, 0, 1), "P1");
        RenderPoint(p2, glm::vec3(0, 0, 1), "P2");
        RenderPoint(p3, glm::vec3(0, 0, 1), "P3");

        std::vector<glm::vec2> check_points{
            glm::vec2(1, 1), glm::vec2(3.21, 3.2),
            glm::vec2(-2.16, 2.9), glm::vec2(2, -2),
            glm::vec2(-1.1, -0.9), glm::vec2(-1.9, 2.1),
            glm::vec2(-4, 0), glm::vec2(-4, -2.5),
            glm::vec2(4.5, 1.1), glm::vec2(5.9, -3.1),
            glm::vec2(7.1, 1.9), glm::vec2(-5.9, 1.5)
        };

        const float EPSILON = 0.01f;

        auto a = glm::length(p2 - p1);
        auto b = glm::length(p3 - p2);
        auto c = glm::length(p1 - p3);
        auto semiperimeter = (a + b + c) / 2.0f;
        float area_v1v2v3 = glm::sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));


        for (const glm::vec2 &check_point : check_points) {

            auto a1 = glm::length(p1 - check_point);
            auto b1 = glm::length(p3 - check_point);
            auto semiperimeter1 = (a1 + b1 + c) / 2.0f;
            float area_pv1v3 = glm::sqrt(semiperimeter1 * (semiperimeter1 - a1) * (semiperimeter1 - b1) * (semiperimeter1 - c));
            auto a2 = glm::length(p1 - check_point);
            auto b2 = glm::length(p2 - check_point);
            auto semiperimeter2 = (a2 + b2 + a) / 2.0f;
            float area_pv1v2 = glm::sqrt(semiperimeter2 * (semiperimeter2 - a2) * (semiperimeter2 - b2) * (semiperimeter2 - a));
            auto a3 = glm::length(p2 - check_point);
            auto b3 = glm::length(p3 - check_point);
            auto semiperimeter3 = (a3 + b3 + b) / 2.0f;
            float area_pv2v3 = glm::sqrt(semiperimeter3 * (semiperimeter3 - a3) * (semiperimeter3 - b3) * (semiperimeter3 - b));

            bool inside_triangle = abs(area_v1v2v3 - (area_pv1v3 + area_pv1v2 + area_pv2v3)) < EPSILON;

            if (inside_triangle) 
				RenderPoint(check_point, glm::vec3(0,1 , 0), "in");
			else

            RenderPoint(check_point, glm::vec3(1,0,0), "out");
        }


    }
}
