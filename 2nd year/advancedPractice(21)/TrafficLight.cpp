// Светофор. На перекрестке 3 светофора.
// Каждый светофор бывает красным, желтым или зеленым.
// Переключите светофор 2 на следующий цвет через switch.
#include <array>
#include <span>

enum Light
{
    RED,
    YELLOW,
    GREEN,
};

struct TrafficLight
{
    Light light;
};

struct Crossroad
{
    std::array<TrafficLight, 3> trafficLights;
};

bool change_color(Crossroad &crossroad, size_t index)
{
    if (index >= crossroad.trafficLights.size())
    {
        return false;
    }
    std::span<TrafficLight> traffic_lights {crossroad.trafficLights};

    switch (traffic_lights[index].light)
    {
    case RED:
        traffic_lights[index].light = YELLOW;
        return true;
    case YELLOW:
        traffic_lights[index].light = GREEN;
        return true;
    case GREEN:
        traffic_lights[index].light = RED;
        return true;
    }
    return false;
}

int main()
{
    Crossroad crossroad{};

    crossroad.trafficLights[0].light = RED;
    crossroad.trafficLights[1].light = RED;
    crossroad.trafficLights[2].light = GREEN;

    change_color(crossroad, 1);
}
