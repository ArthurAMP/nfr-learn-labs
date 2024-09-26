#include <iostream>
#include <memory>
#include <stdlib.h>
#include <signal.h>

#include "tex.hpp"
#include "display.hpp"
#include "render.hpp"
#include "app.hpp"

App::App()
{
    this->OUTPUT_HEIGHT = 30;
    this->OUTPUT_WIDTH = 90;
    // initialize the display
    this->_display = AsciiDisplay(this->OUTPUT_WIDTH, this->OUTPUT_HEIGHT);
}

void App::init()
{
    // noop
}

void App::run()
{
    RenderSettings settings(OUTPUT_WIDTH, OUTPUT_HEIGHT, 60.0f, 0.1f, 100.1f);
    std::cout << settings.toString() << "\n";
    RasciiRenderer renderer = RasciiRenderer(settings);

    // create the scene graph
    SceneGraph sceneGraph = SceneGraph();
    Mesh mesh = Mesh::centeredCube();
    std::shared_ptr<Mesh> meshPtr = std::make_shared<Mesh>(mesh);
    // create the transform node
    RenderInfo renderInfo = RenderInfo(meshPtr);
    std::shared_ptr<TransformNode> transformNode = std::make_shared<TransformNode>(Transform(
        Vec(0.0f, 0.0f, -30.0f),
        Quaternion::fromAxisAngle(Vec(1.0f, 0.0f, 0.0f), 15.0f),
        Vec(1.0f, 1.0f, 1.0f)
    ), renderInfo);

    // add the transform node to the scene graph
    sceneGraph.addChild(transformNode);

    Quaternion rotationQuaternion = Quaternion::fromAxisAngle(Vec(0.0f, 1.0f, 0.0f), 0.05f);
    // update loop
    while (true)
    {
        _display.prepare();
        renderer.prepare();
        // render the scene graph
        renderer.render(sceneGraph);
        // draw the output
        this->_display.draw(*renderer.getOutput());
        transformNode->transform.rotate(rotationQuaternion);
    }
}

void App::onExit(int exitCode)
{
    // cleanup
    this->_display.cleanup();
    exit(exitCode);
}

App::~App()
{
    // cleanup
    this->_display.cleanup();
}