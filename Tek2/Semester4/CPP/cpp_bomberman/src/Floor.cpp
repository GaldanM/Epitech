#include "Floor.hh"

Floor::Floor(const float pos_y, const float pos_x) : AObject(pos_y, pos_x)
{
    float           x = CASE_SIZE;
    float           y = CASE_SIZE;
    float           z = FLOOR_SIZE;
  
    std::string     textu = "./LibGDL/assets/floor.tga";

    if (!_texture.load(textu.c_str(), true))
        throw MyError("Cannot load AssetBomb texture");

    _type = FLOOR;
    
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

Floor::~Floor()
{

}

void	Floor::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
	(void)clock;
	_texture.bind();
	_geometry.draw(shader, getTransformation(), GL_QUADS);
}