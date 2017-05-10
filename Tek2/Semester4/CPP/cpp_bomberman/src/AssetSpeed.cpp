

#include "AssetSpeed.hh"

AssetSpeed::AssetSpeed(const float pos_y, const float pos_x) : AObject(pos_y, pos_x)
{
    float           x = CASE_SIZE;
    float           y = CASE_SIZE;
    float           z = 0.01f;
    std::string     textu = "./LibGDL/assets/assetSpeed.tga";

    if (!_texture.load(textu.c_str(), true))
        throw MyError("Cannot load AssetSpeed texture");

    _position.z = 0.01f;
    _type = ASSETSPEED;

    _geometry.pushVertex(glm::vec3(x, -y, z));
    _geometry.pushVertex(glm::vec3(x, y, z));
    _geometry.pushVertex(glm::vec3(-x, y, z));
    _geometry.pushVertex(glm::vec3(-x, -y, z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(x, -y, -z));
    _geometry.pushVertex(glm::vec3(x, y, -z));
    _geometry.pushVertex(glm::vec3(-x, y, -z));
    _geometry.pushVertex(glm::vec3(-x, -y, -z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(x, -y, -z));
    _geometry.pushVertex(glm::vec3(x, y, -z));
    _geometry.pushVertex(glm::vec3(x, y, z));
    _geometry.pushVertex(glm::vec3(x, -y, z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(-x, -y, z));
    _geometry.pushVertex(glm::vec3(-x, y, z));
    _geometry.pushVertex(glm::vec3(-x, y, -z));
    _geometry.pushVertex(glm::vec3(-x, -y, -z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(x, y, z));
    _geometry.pushVertex(glm::vec3(x, y, -z));
    _geometry.pushVertex(glm::vec3(-x, y, -z));
    _geometry.pushVertex(glm::vec3(-x, y, z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(x, -y, -z));
    _geometry.pushVertex(glm::vec3(x, -y, z));
    _geometry.pushVertex(glm::vec3(-x, -y, z));
    _geometry.pushVertex(glm::vec3(-x, -y, -z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.build();
}

AssetSpeed::~AssetSpeed()
{

}

void    AssetSpeed::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
    (void)clock;
    _texture.bind();
    _geometry.draw(shader, getTransformation(), GL_QUADS);
}